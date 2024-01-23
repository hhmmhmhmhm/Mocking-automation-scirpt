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

# Documentation : https://learning.postman.com/docs/designing-and-developing-your-api/mocking-data/mock-with-api/

# path: script/py/src/mat.py

from json_mocking import *  # Import JSON Dumping & Interpreting functionnalities 
from base_access import *   # Import the base functions of the framework
from perf_mes import *      # Import the performance measurement for optimizations

@perf_mes
def main():
    get_collection()
    get_mocks()

if __name__ == "__main__":
    main()
    