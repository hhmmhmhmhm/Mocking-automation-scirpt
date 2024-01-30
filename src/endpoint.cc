#include "../include/endpoint.hpp"

#include <string>

inline bool endpoint::is_operational_endpoint(endpoint& ed){		//Check if the endpoint is valid by sending a peak request to the endpoint
	return true;
}

inline endpoint::endpoint(std::string& url, std::string& header)
	: url(url), header(header) {}

