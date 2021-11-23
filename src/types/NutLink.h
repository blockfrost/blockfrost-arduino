/*
 * NutLink.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_NutLink_H_
#define BLOCKFROST_CPP_CLIENT_NutLink_H_

#include <ctime>
#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class NutLinkAddress{
public:

    // \brief Constructor.
    NutLinkAddress();
    NutLinkAddress(std::string jsonString);

    // \brief Destructor.
    virtual ~NutLinkAddress();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::string metadata_url;
    std::string metadata_hash;
    std::pair<bourne::json, bool> metadata;
};

class NutLinkAddressTicker{
public:

    // \brief Constructor.
    NutLinkAddressTicker();
    NutLinkAddressTicker(std::string jsonString);

    // \brief Destructor.
    virtual ~NutLinkAddressTicker();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string name;
    int count;
    int latest_block;
};

class NutLinkTicker{
public:

    // \brief Constructor.
    NutLinkTicker();
    NutLinkTicker(std::string jsonString);

    // \brief Destructor.
    virtual ~NutLinkTicker();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    int block_height;
    int tx_index;
    bourne::json payload;
};

class NutLinkTickerAddress{
public:

    // \brief Constructor.
    NutLinkTickerAddress();
    NutLinkTickerAddress(std::string jsonString);

    // \brief Destructor.
    virtual ~NutLinkTickerAddress();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::string tx_hash;
    int block_height;
    int tx_index;
    bourne::json payload;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_NutLink_H_ */
