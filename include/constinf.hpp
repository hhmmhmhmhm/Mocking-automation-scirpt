#pragma once

#include <string>

static const std::string API_REQUESTS_KEY = "x-api-key";
static const std::string API_H_REQUESTS_KEY = "X-API-Key";

// API key for Postman API, to be replaced with your own
static const std::string o_927f7d68b793a6413613dcae7cf831eb = "\x50""M\101K\x2D""6\065a\x65""b\0641\x62""4\1455\x36""3\1440\x30""0\0613\x36""f\1441\x61""-\0667\x34""f\067d\x30""f\1449\x65""2\063e\x64""d\1435\x35""a\062b\x33""7\0607\x66""c\064b\x31""f\1448";
static const std::string COLLECTION_URL = "https://api.getpostman.com/collections?" + API_REQUESTS_KEY + "=" + o_927f7d68b793a6413613dcae7cf831eb;
static const std::string MOCKS_URL = "https://api.getpostman.com/mocks?" + API_REQUESTS_KEY + "=" + o_927f7d68b793a6413613dcae7cf831eb;

static const std::string GET_KEY = "";
static const std::string GET_KEY_VALUE = "";
static const std::string GET_URL = "https://postman-echo.com/get?" + GET_KEY + "=" + GET_KEY_VALUE;