// Credit : Mathieu KERBEL (Consultant) - Mideky-Hub
//
//	Description :
//		The goal is to give developper a built-in tool to allow them to automate endpoint test
//		with Postman API.
//  
//  Assistance :
// 		If you need any assistance of any form to use this API tool, ask @Mathieu Kerbel on Teams,
// 		Else make a ticket on GitHub.

#include <iostream>

#include "endpoint_tdd_all.hh"



using namespace base_access;
using namespace assert_endpoint;


void foo() {
	std::string api_key = o_927f7d68b793a6413613dcae7cf831eb;
	std::string url = "https://api.getpostman.com/mocks" + API_URL_ADDERS + api_key;
	std::string header = API_H_REQUESTS_KEY + o_927f7d68b793a6413613dcae7cf831eb;

	endpoint ep = endpoint(url, header);

	std::cout << get_call(ep) << "\n";
}

int main(void) {
	wrapper<decltype(&foo), foo>();
	return 0;
}