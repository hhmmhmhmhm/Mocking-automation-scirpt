#pragma once

#include <string>

static const std::string API_REQUESTS_KEY = "x-api-key";
static const std::string API_H_REQUESTS_KEY = "X-API-Key";

// API key for Postman API, to be replaced with your own
static const std::string o_927f7d68b793a6413613dcae7cf831eb = "PMAK-65aeb41b4e563d000136fd1a-c8215aa53f9cf401e825dba5a3e5f3b73d";
static const std::string COLLECTION_URL = "https://api.getpostman.com/collections?" + API_REQUESTS_KEY + "=" + o_927f7d68b793a6413613dcae7cf831eb;
static const std::string MOCKS_URL = "https://api.getpostman.com/mocks?" + API_REQUESTS_KEY + "=" + o_927f7d68b793a6413613dcae7cf831eb;

static const std::string HEADER_KEY = API_H_REQUESTS_KEY + ": " + o_927f7d68b793a6413613dcae7cf831eb;

static const std::string GET_KEY = "";
static const std::string GET_KEY_VALUE = "";
static const std::string GET_URL = "https://postman-echo.com/get?" + GET_KEY + "=" + GET_KEY_VALUE;