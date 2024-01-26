#pragma once	// ASSERT_ENDPOINT_HPP

#include <exception>
#include <stdexcept>
#include <cassert>
#include <string>

#include <glaze/json.hpp>

namespace assert_endpoint
{
	// Here, all the way when you'll be seeing the 'message' parameter
	// it will stand for the response body of the get_call request made earlier
	// to the endpoint. It will be used to check if the endpoint is working
	// properly or not.

	static void assert_ed(bool condition, const std::string& message);
	static void assert_p_ed(std::string& var_name, std::string& var_value, const std::string& message);
}

//		!ASSERT_ENDPOINT_HPP