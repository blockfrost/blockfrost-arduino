#ifndef BLOCKFROST_CPP_CLIENT_SERVICE_H_
#define BLOCKFROST_CPP_CLIENT_SERVICE_H_

#if defined(ESP8266)

#include "ESP8266HTTPClient.h"
#include <WiFiClientSecureBearSSL.h>
using namespace BearSSL;

#elif defined(ESP32)

#include "HTTPClient.h"
#include <WiFiClientSecure.h>

#else
#error "This ain't ESP8266 or ESP32"
#endif

#include "types/Response.h"
#include "util/config.h"
#include "util/debug.h"

namespace Blockfrost {

class Service {
public:
  Service(WiFiClientSecure *);
  virtual ~Service();
  WiFiClientSecure *sClient;
  HTTPClient http;
  std::string basepath = std::string();
  void begin(std::string url);
  bool setToken(std::string tok);

private:
  std::string token = std::string();

}; // end class
}// namespace Blockfrostclient

#endif /* BLOCKFROST_CPP_CLIENT_SERVICE_H_ */
