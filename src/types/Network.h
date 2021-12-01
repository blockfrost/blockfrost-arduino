/*
 * Network.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Network_H_
#define BLOCKFROST_CPP_CLIENT_Network_H_

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

class NetworkSupply{
public:

    // \brief Constructor.
    NetworkSupply();
    NetworkSupply(std::string jsonString);

    // \brief Destructor.
    virtual ~NetworkSupply();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string max;
    std::string total;
    std::string circulating;
    std::string locked;
    std::string treasury;
    std::string reserves;
};

class NetworkStake{
public:

    // \brief Constructor.
    NetworkStake();
    NetworkStake(std::string jsonString);

    // \brief Destructor.
    virtual ~NetworkStake();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string live;
    std::string active;
};

class Network{
public:

    // \brief Constructor.
    Network();
    Network(std::string jsonString);

    // \brief Destructor.
    virtual ~Network();

    // \brief Retrieve a bourne CBOR representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne CBOR object representing it.
    void fromJson(std::string jsonObj);

    NetworkSupply supply;
    NetworkStake stake;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Network_H_ */
