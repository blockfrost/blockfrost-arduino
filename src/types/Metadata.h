/*
 * Metadata.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Metadata_H_
#define BLOCKFROST_CPP_CLIENT_Metadata_H_

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

class TxMeta{
public:

    // \brief Constructor.
    TxMeta();
    TxMeta(std::string jsonString);

    // \brief Destructor.
    virtual ~TxMeta();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string label;
    std::pair<std::string, bool> cip10;
    std::string count;
};

class TxMetaJSON{
public:

    // \brief Constructor.
    TxMetaJSON();
    TxMetaJSON(std::string jsonString);

    // \brief Destructor.
    virtual ~TxMetaJSON();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    std::pair<bourne::json, bool> json_metadata;
};

class TxMetaCBOR{
public:

    // \brief Constructor.
    TxMetaCBOR();
    TxMetaCBOR(std::string jsonString);

    // \brief Destructor.
    virtual ~TxMetaCBOR();

    // \brief Retrieve a bourne CBOR representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne CBOR object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    std::pair<std::string, bool> metadata;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Metadata_H_ */
