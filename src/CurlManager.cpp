#include "CurlManager.h"

CurlManager::CurlManager() {
	curl_global_init(CURL_GLOBAL_ALL);
}

CurlManager::~CurlManager() {
	curl_global_cleanup();
}