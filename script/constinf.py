# |---------------------------------------|-----------------------------------------|
# |///////////////////////////////////////|/////////////////////////////////////////|
# | Made by : Mathieu KERBEL (Consultant) |                                         |
# | Created : 22/01/2024                  |                                         |
# | Updated : 22/01/2024                  |                                         |
# |///////////////////////////////////////|/////////////////////////////////////////|
# | Description :                         |                                         |
# |                                       |                                         |
# | Design of an easy to use script       |                                         |
# | for Postman API calls and mocking     |                                         |
# | to automate endpoint test.            |                                         |
# |                                       |                                         |
# |///////////////////////////////////////|/////////////////////////////////////////|
# |---------------------------------------|-----------------------------------------|

API_REQUESTS_KEY = "x-api-key"
API_H_REQUESTS_KEY = "X-API-Key"

# API key for Postman API, to be replaced with your own
API_KEY = "PMAK-65aeb41b4e563d000136fd1a-674f7d0fd9e23eddc55a2b3707fc4b1fd8"

COLLECTION_URL = "https://api.getpostman.com/collections?" + API_REQUESTS_KEY + "=" + API_KEY
MOCKS_URL = "https://api.getpostman.com/mocks?" + API_REQUESTS_KEY + "=" + API_KEY

GET_KEY = ""
GET_KEY_VALUE = ""
GET_URL = "https://postman-echo.com/get?" + GET_KEY + "=" + GET_KEY_VALUE