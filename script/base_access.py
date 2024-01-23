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

import requests

from json_parser import *  # Import functions from script/json_parser.py
from constinf import *  # Import constants from script/constinf.py

def get_collection():
    payload = {}
    headers = {
    API_H_REQUESTS_KEY : API_KEY
    }

    response = requests.request("GET", COLLECTION_URL, headers=headers, data=payload)

    print_json(response)

def get_mocks():
    payload = {}
    headers = {
    API_H_REQUESTS_KEY : API_KEY
    }

    response = requests.request("GET", MOCKS_URL, headers=headers, data=payload)

    print_json(response)