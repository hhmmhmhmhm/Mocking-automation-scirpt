#pragma once

#include "../include/base_access.hpp"

namespace base_access {
    // Callback function to handle the received data
    size_t WriteCallback(
        void* contents,        /* Data received */
        size_t size, 	        /* Size of each data received */
        size_t nmemb,          /* Number of data received */
        std::string* output    /* Output string */)
    {
        size_t total_size = size * nmemb;
        output->append(static_cast<char*>(contents), total_size);
        return total_size;
    }

    // Function to get the collection of the Postman API
    void curl_session(CURL* curl, std::string& url) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    }

    // Function to integrate the header into the endpoint
    void header_integration(CURL* curl, std::string& header, struct curl_slist*& headers) {
        headers = curl_slist_append(headers, header.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    }

    // Function to prettify the output
    void output_integration(CURL* curl, std::string& output) {
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
    }

    // Function to perform the session
    void perform_session(CURL* curl, CURLcode& res, std::string& output, struct curl_slist*& headers) {
        output_integration(curl, output);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        output = glz::prettify(output);
    }

    // Function to initialize the session
    CURLcode session_init(CURL* curl, CURLcode& res, std::string& url, std::string& output, std::string& header){
        struct curl_slist* headers = NULL;
        curl_session(curl, url);                        // Transmission : OK
        header_integration(curl, header, headers);      
        perform_session(curl, res, output, headers);

        return res;
    }

    // Function to get the collection of the Postman API
    std::string get_call(
        std::string& url        /* For exemple : https://api.getpostman.com/mocks */,
        std::string& header     /* For header API key integration into endpoint */,
        std::string& api_key    /* Pass the PMAK APÏ key */
    ) {
        CURL* curl;
        CURLcode res;
		std::string output; 
        curl = curl_easy_init();

        if (curl) { // Start the session
            res = session_init(curl, res, url, output, header);
            if (res != CURLE_OK /* Execution : OK */) {
                return "Error while performing the curl session.";
            }
        }
        curl_easy_cleanup(curl);

        //std::cout << curl_easy_strerror(res) << "\n";

        return output;
    }
} // namespace base_access

//      !BASE_ACCESS_CPP