#include <iostream>

#include "../include/perf_measure.hpp"
#include "../include/base_access.hpp"

/****************************************************************************************
* 
* Credit : Mathieu KERBEL (Consultant) - Mideky-Hub
* 
* Description :
*	The goal is to give developper a built-in tool to allow them to automate endpoint test
*	with Postman API.
* 
* Assistance :
*	If you need any assistance of any form to use this API tool, ask @Mathieu Kerbel on Teams,
*	Else make a ticket on GitHub.
****************************************************************************************/

int foo() {
	std::string api_key = o_927f7d68b793a6413613dcae7cf831eb;
	std::string url = "https://api.getpostman.com/mocks" + API_URL_ADDERS + api_key;
	std::string header = API_H_REQUESTS_KEY + o_927f7d68b793a6413613dcae7cf831eb;
	std::cout << get_call(url, header, api_key) << "\n";

	return 42;
}

int main(void) {
	std::cout << wrapper<decltype(&foo), foo>() << "\n";
	return 0;
}