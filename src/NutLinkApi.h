#ifndef BLOCKFROST_CPP_CLIENT_NutLinkApi_H_
#define BLOCKFROST_CPP_CLIENT_NutLinkApi_H_


#include "Service.h"

#include "types/Response.h"
#include "types/Helpers.h"

#include "types/NutLink.h"

#if defined(ESP8266)
#include <WiFiClientSecureBearSSL.h>
#endif

namespace Blockfrost {

/**
 *  Class
 */

class NutLinkApi : public Service {

using Service::Service;
public:
    NutLinkApi() = default;
    virtual ~NutLinkApi() = default;

    /**
    * List metadata about specific address
    *
    * \param address  *Required*
    */
    Response<NutLinkAddress> nutlinkListAddress(std::string address);

    /**
    *
    * List tickers for a specific metadata oracle
    *
    * \param address  *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<NutLinkAddressTicker>> nutlinkListAddressTickers(std::string address, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    *
    * List of records of a specific ticker
    *
    * \param address  *Required*
    * \param ticker  *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<NutLinkTicker>> nutlinkAddressTickers(std::string address, std::string ticker, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

   /**
    *
    * List of records of a specific ticker
    *
    * \param ticker  *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<NutLinkTickerAddress>> nutlinkTickers(std::string ticker, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);
};

}

#endif /* BLOCKFROST_CPP_CLIENT_NutLinkApi_H_ */
