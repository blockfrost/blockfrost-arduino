#ifndef BLOCKFROST_CPP_CLIENT_IPFSApi_H_
#define BLOCKFROST_CPP_CLIENT_IPFSApi_H_


#include "Service.h"

#include "types/Response.h"
#include "types/Helpers.h"

#include "types/IPFS.h"

#if defined(ESP8266)
#include <WiFiClientSecureBearSSL.h>
#endif

namespace Blockfrost {

/**
 *  Class
 */

class IPFSApi : public Service {

using Service::Service;
public:
    IPFSApi() = default;
    virtual ~IPFSApi() = default;

    Response<std::vector<IPFSPin>> listPins(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);
    Response<IPFSPin> getPin(std::string ipfs_path);
    Response<IPFSPinChange> addPin(std::string ipfs_path);
    Response<IPFSPinChange> removePin(std::string ipfs_path);
};

}

#endif /* BLOCKFROST_CPP_CLIENT_IPFSApi_H_ */
