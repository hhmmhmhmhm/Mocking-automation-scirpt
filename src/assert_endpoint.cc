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

	static void assert_p_ed(std::string& var_name, std::string& var_value, const std::string& message) {
		
	}
} // namespace assert_enpoint