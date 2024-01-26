#pragma once

#include "../include/assert_endpoint.hpp"

namespace assert_endpoint {
	/*	Here a possible upgrade would be with the mocked 
	*   online HMI with a verification endpoint to automate 
	*	the physical testing process.
	* 
	*   For now, we will just use a simple assert function.
	*/

	static void assert_ep(bool condition, const std::string& message) {
		if (!condition) {
			throw std::runtime_error(message);
		}
	}

	//function to find the var name and value in the json file
	std::pair<std::string, std::string> fetch_data(const std::string& var_name) {
		//TODO : find the var name and value in the json file
		//return std::make_pair(var_name, var_value);
		return std::make_pair("je suis", "le plus beau");
	}

	static void assert_p_ed(const std::string& var_name, std::string& var_value, const std::string& message) {
		//TODO : find the var name and value in the json file
		
		//TODO : assert the value
	}
} // namespace assert_enpoint