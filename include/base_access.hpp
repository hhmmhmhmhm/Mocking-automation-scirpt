#pragma once    //     BASE_ACCESS_HPP
#pragma warning(disable : 4996)

#include <iostream>
#include <string>           

#include <glaze/json.hpp>
#include <curl/curl.h>

#include "endpoint.hpp"

namespace base_access {
    // Callback function to handle the received data
    size_t WriteCallback(
        void* contents,        /* Data received */
        size_t size, 	        /* Size of each data received */
        size_t nmemb,          /* Number of data received */
        std::string* output    /* Output string */);

    // Function to get the collection of the Postman API
    void curl_session(
        CURL* curl, 
        std::string& url);
    // Function to integrate the header into the endpoint
    void header_integration(
        CURL* curl, 
        std::string& header, 
        struct curl_slist*& headers);
    // Function to prettify the output
    void output_integration(
        CURL* curl, 
        std::string& output);
    // Function to perform the session
    void perform_session(
        CURL* curl, 
        CURLcode& res, 
        std::string& output, 
        struct curl_slist*& headers);
    // Function to initialize the session
    CURLcode session_init(
        CURL* curl, 
        CURLcode& res, 
        std::string& url, 
        std::string& output, 
        std::string& header);
    // Function to get the collection of the Postman API
    std::string get_call(
        endpoint endpoint
    );
}

//      !BASE_ACCESS_HPP