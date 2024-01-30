#pragma once	// ASSERT_ENDPOINT_HPP

#include <exception>
#include <stdexcept>
#include <cassert>
#include <string>

#include <glaze/json.hpp>

#include "assertion.hpp"
#include "endpoint.hpp"

namespace assert_endpoint
{
	// Here, all the way when you'll be seeing the 'message' parameter
	// it will stand for the response body of the get_call request made earlier
	// to the endpoint. It will be used to check if the endpoint is working
	// properly or not.

	// The namespace should contains the following functions:
	//		- bool is_endpoint_working(const std::string& message);
	//		- void assert_endpoint_working(const std::string& message);

	// The namespace should also contains the following variables:

}

//		!ASSERT_ENDPOINT_HPP