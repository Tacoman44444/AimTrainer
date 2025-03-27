#include "HttpHelper.h"

namespace {

	size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* store) {
		size_t bytes = size * nmemb;
		static_cast<std::string*>(store)->append((char*)contents, bytes);
		return bytes;
	}

	void InitCurl() {
		static bool initialized = [] {
			curl_global_init(CURL_GLOBAL_ALL);
			atexit(curl_global_cleanup);
			return true;
		}();
		(void)initialized;
	}

}

namespace HttpHelper {

	std::string Get(const std::string& url) {
		InitCurl();

		CURL* curl = curl_easy_init();
		if (!curl) {
			std::cout << "Could not initialize libcurl" << std::endl;
		}

		std::string response;
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

		CURLcode res = curl_easy_perform(curl);

		if (res != CURLE_OK) {
			std::cout << "Could not perform HTTP GET request" << std::endl;
		}

		return response;
	}

	std::string Post(const std::string& url, const std::string& data, const std::string& contentType) {
		InitCurl();

		CURL* curl = curl_easy_init();
		if (!curl) {
			std::cout << "Could not initialize libcurl" << std::endl;
		}

		std::string response;
		struct curl_slist* headers = nullptr;
		headers = curl_slist_append(headers, ("Content-Type: " + contentType).c_str());

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

		CURLcode res = curl_easy_perform(curl);
		curl_slist_free_all(headers);
		curl_easy_cleanup(curl);

		if (res != CURLE_OK) {
			std::cout << "Could not perform HTTP GET request" << std::endl;
		}

		return response;
	}
}