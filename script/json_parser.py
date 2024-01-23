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

import json
from requests import Response

def generate_json(response: Response) -> str:
    # Convert the response to JSON
    json_response = json.loads(response.text)
    # Pretty print JSON
    return json.dumps(json_response, indent=4, sort_keys=True)

def print_json(response: Response) -> None:
    print(generate_json(response))