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
	get_collection(); get_mock();

	return 42;
}

int main(void) {
	std::cout << wrapper<decltype(&foo), foo>() << "\n";
	return 0;
}