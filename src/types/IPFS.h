/*
 * IPFS.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_IPFS_H_
#define BLOCKFROST_CPP_CLIENT_IPFS_H_

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

class IPFSAdd{
public:

    // \brief Constructor.
    IPFSAdd();
    IPFSAdd(std::string jsonString);

    // \brief Destructor.
    virtual ~IPFSAdd();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string name;
    std::string ipfs_hash;
    std::string size;
};

class IPFSPinChange{
public:

    // \brief Constructor.
    IPFSPinChange();
    IPFSPinChange(std::string jsonString);

    // \brief Destructor.
    virtual ~IPFSPinChange();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string ipfs_hash;
    std::string state;
};

class IPFSPin{
public:

    // \brief Constructor.
    IPFSPin();
    IPFSPin(std::string jsonString);

    // \brief Destructor.
    virtual ~IPFSPin();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    time_t time_created;
    time_t time_pinned;
    std::string ipfs_hash;
    std::string size;
    std::string state;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_IPFS_H_ */
