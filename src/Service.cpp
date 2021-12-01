#include "Service.h"


Blockfrost::Service::Service(WiFiClientSecure *inSClient) {
  sClient = inSClient;
};

Blockfrost::Service::~Service() {
};

bool Blockfrost::Service::setToken(std::string tok){
  bool knownEnv;
  std::size_t foundMainnet = tok.find("mainnet");
  if (foundMainnet!=std::string::npos) {
    basepath = BASEPATH_MAINNET;
    knownEnv = true;
  }

  std::size_t foundTestnet = tok.find("testnet");
  if (foundTestnet!=std::string::npos) {
    basepath = BASEPATH_TESTNET;
    knownEnv = true;
  }

  std::size_t foundIPFS = tok.find("ipfs");
  if (foundIPFS!=std::string::npos) {
    basepath = BASEPATH_IPFS;
    knownEnv = true;
  }

  token = tok;
  return knownEnv;
}

void Blockfrost::Service::begin(std::string url){
    if (!sClient) {
      DEBUG_MSG("Error sClient is NULL\n");
    }

    DEBUG_MSG("URL: %s\r\n", url.c_str());

    http.begin(
        dynamic_cast<WiFiClient&>(*sClient),
        String(url.c_str())
        );

    http.addHeader("project_id", token.c_str());
    http.addHeader("User-Agent", BLOCKFROST_CLIENT_VERSION);

    DEBUG_MSG("Free heap before GET %d\n\r", ESP.getFreeHeap());
}
