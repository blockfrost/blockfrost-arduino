/*
 * Pool.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Pool_H_
#define BLOCKFROST_CPP_CLIENT_Pool_H_

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

class PoolEpoch{
public:

    // \brief Constructor.
    PoolEpoch();
    PoolEpoch(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolEpoch();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string pool_id;
    int epoch;
};

class PoolInfo{
public:

    // \brief Constructor.
    PoolInfo();
    PoolInfo(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolInfo();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string pool_id;
    std::string hex;
    std::string vrf_key;
    int blocks_minted;
    std::string live_stake;
    double live_size;
    double live_saturation;
    double live_delegators;
    std::string active_stake;
    double active_size;
    std::string declared_pledge;
    std::string live_pledge;
    double margin_cost;
    std::string fixed_cost;
    std::string reward_account;
    std::vector<std::string> owners;
    std::vector<std::string> registration;
    std::vector<std::string> retirement;
};

class PoolHistory{
public:

    // \brief Constructor.
    PoolHistory();
    PoolHistory(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolHistory();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int epoch;
    int blocks;
    std::string active_stake;
    double active_size;
    int delegators_count;
    std::string rewards;
    std::string fees;
};

class PoolMetadata{
public:

    // \brief Constructor.
    PoolMetadata();
    PoolMetadata(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolMetadata();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string pool_id;
    std::string hex;
    std::pair<std::string, bool> url;
    std::pair<std::string, bool> hash;
    std::pair<std::string, bool> ticker;
    std::pair<std::string, bool> name;
    std::pair<std::string, bool> description;
    std::pair<std::string, bool> homepage;
};

class PoolRelay{
public:

    // \brief Constructor.
    PoolRelay();
    PoolRelay(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolRelay();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::pair<std::string, bool> ipv4;
    std::pair<std::string, bool> ipv6;
    std::pair<std::string, bool> dns;
    std::pair<std::string, bool> dns_srv;
    int port;
};

class PoolDelegator{
public:

    // \brief Constructor.
    PoolDelegator();
    PoolDelegator(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolDelegator();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::string live_stake;
};

class PoolUpdate{
public:

    // \brief Constructor.
    PoolUpdate();
    PoolUpdate(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolUpdate();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    int cert_index;
    std::string action;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Pool_H_ */
