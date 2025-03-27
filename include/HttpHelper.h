#pragma once
#include <curl/curl.h>
#include <string>
#include <iostream>

namespace HttpHelper {

	std::string Get(const std::string& url);
	//std::string Get(const std::string& url, const std::string& reqBody);
	std::string Post(const std::string& url, const std::string& data, const std::string& contentType);
}