#pragma once    //     BASE_ACCESS_HPP

#include "constinf.hpp"

#include <glaze/json.hpp>
#include <curl/curl.h>
#include <iostream>

// get_collection function is used to get the collection of the Postman API
// and to store it in a JSON object

// We display in the console the collection in a JSON format

// Callback function to handle the received data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

void get_collection() {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.getpostman.com/collections?x-api-key=PMAK-65aeb41b4e563d000136fd1a-c8215aa53f9cf401e825dba5a3e5f3b73d");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "X-API-Key: PMAK-65aeb41b4e563d000136fd1a-c8215aa53f9cf401e825dba5a3e5f3b73d");
        
        std::string output;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);

        std::cout << glz::prettify(output) << "\n";
    }
    curl_easy_cleanup(curl);
}

void get_mock() {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.getpostman.com/mocks?x-api-key=PMAK-65aeb41b4e563d000136fd1a-c8215aa53f9cf401e825dba5a3e5f3b73d");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "X-API-Key: PMAK-65aeb41b4e563d000136fd1a-c8215aa53f9cf401e825dba5a3e5f3b73d");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string output;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);

        std::cout << glz::prettify(output) << "\n";
    }
    curl_easy_cleanup(curl);
}
// !BASE_ACCESS_HPP