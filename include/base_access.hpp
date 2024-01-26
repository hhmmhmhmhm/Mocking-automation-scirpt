#pragma once    //     BASE_ACCESS_HPP
#pragma warning(disable : 4996)

#include "constinf.hpp"
#include <string>
#include <glaze/json.hpp>
#include <curl/curl.h>
#include <iostream>

// get_collection function is used to get the collection of the Postman API
// and to store it in a JSON object

// We display in the console the collection in a JSON format

// Callback function to handle the received data
size_t WriteCallback(
    void*& contents,        /* Data received */
    size_t& size, 	        /* Size of each data received */
    size_t& nmemb,          /* Number of data received */
    std::string*& output    /* Output string */)
{
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

// Function to get the collection of the Postman API
void curl_session(CURL*& curl, std::string& url) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
}

// Function to integrate the header into the endpoint
void header_integration(CURL*& curl, std::string& header, struct curl_slist*& headers) {
	headers = curl_slist_append(headers, header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
}

// Function to prettify the output
void output_integration(CURL*& curl, std::string& output, std::string& ret_output) {
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
    ret_output = glz::prettify(output);
}

// Function to perform the session
void perform_session(CURL*& curl, CURLcode& res, struct curl_slist*& headers) {
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
}

// Function to initialize the session
CURLcode session_init(CURL*& curl, CURLcode& res, std::string& ret_output, std::string& url, std::string& header) {
    std::string output;
    struct curl_slist* headers = NULL;

    curl_session(curl, url);
    header_integration(curl, header, headers);
    output_integration(curl, output, ret_output);
    perform_session(curl, res, headers);
    
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
    std::string ret_output;

    curl = curl_easy_init();
    if (curl) { // Start the session
        if(session_init(curl, res, ret_output, url, header) != CURLE_OK /* Execution : OK */) {
            return "Error while performing the curl session.";
		}
    }
    curl_easy_cleanup(curl);

    //std::cout << curl_easy_strerror(res) << "\n";

    return ret_output;
}

// !BASE_ACCESS_HPP