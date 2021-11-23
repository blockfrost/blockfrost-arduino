#ifndef BLOCKFROST_CPP_CLIENT_CommonApi_H_
#define BLOCKFROST_CPP_CLIENT_CommonApi_H_


#include "AbstractService.h"

#include "types/Response.h"
#include "types/Helpers.h"

#include "types/Common.h"

#if defined(ESP8266)
#include <WiFiClientSecureBearSSL.h>
#endif

namespace Blockfrost {

/**
 *  Class
 */

class CommonApi : public AbstractService {

using AbstractService::AbstractService;
public:
    CommonApi() = default;
    virtual ~CommonApi() = default;

    /**
    * Root endpoint
    */
    Response<URLVersion> getRoot();


    /**
    * Backend health
    */
    Response<Health> getHealth();

    /**
    * Backend clock
    */
    Response<ServerTime> getClock();

    /**
    * Usage metrics
    */
    Response<std::vector<Metric>> getMetrics();

    /**
    * Usage metrics per endpoint
    */
    Response<std::vector<MetricEndpoint>> getMetricsEndpoints();
};

}

#endif /* BLOCKFROST_CPP_CLIENT_CommonApi_H_ */
