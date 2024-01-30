#pragma once

#include <string>

#include "constinf.hpp" 

class endpoint {
/*Variable public space*/	public:
	std::string url;				//URL of the endpoint		(e.g. https://api.example.com/)
	std::string header;				//Header for the endpoint	(e.g. "X-Api-Key: " + api_key)
	bool is_operational{};
/*Methods public space*/	public:
	inline bool is_operational_endpoint(endpoint& ed);		//Check if the endpoint is valid by sending a peak request to the endpoint

	inline endpoint(std::string& url, std::string& header);
};
