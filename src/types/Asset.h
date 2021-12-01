/*
 * Asset.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Asset_H_
#define BLOCKFROST_CPP_CLIENT_Asset_H_

#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Asset{
  public:
    // \brief Constructor.
    Asset();
    Asset(std::string jsonString);

    // \brief Destructor.
    virtual ~Asset();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string asset;
    std::string quantity;
};

class AssetOnChainMetadata{
  public:
    // \brief Constructor.
    AssetOnChainMetadata();
    AssetOnChainMetadata(std::string jsonString);

    // \brief Destructor.
    virtual ~AssetOnChainMetadata();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string name;
    std::string image;
};

class AssetMetadata{
  public:
    // \brief Constructor.
    AssetMetadata();
    AssetMetadata(std::string jsonString);

    // \brief Destructor.
    virtual ~AssetMetadata();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string name;
    std::string description;
    std::pair<std::string, bool> ticker;
    std::pair<std::string, bool> url;
    std::pair<std::string, bool> logo;
    std::pair<int, bool> decimals;
};

class AssetDetail{
  public:
    // \brief Constructor.
    AssetDetail();
    AssetDetail(std::string jsonString);

    // \brief Destructor.
    virtual ~AssetDetail();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string asset;
    std::string policy_id;
    std::string asset_name;
    std::string fingerprint;
    std::string quantity;
    std::string initial_mint_tx_hash;
    int mint_or_burn_count;
    std::pair<AssetOnChainMetadata , bool> onchain_metadata;
    std::pair<AssetMetadata, bool> metadata;
};

// AssetHistory

class AssetHistory{
  public:
    // \brief Constructor.
    AssetHistory();
    AssetHistory(std::string jsonString);

    // \brief Destructor.
    virtual ~AssetHistory();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    std::string amount;
    std::string action;
};

// AssetTransaction

class AssetTransaction{
  public:
    // \brief Constructor.
    AssetTransaction();
    AssetTransaction(std::string jsonString);

    // \brief Destructor.
    virtual ~AssetTransaction();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    int tx_index;
    int block_height;
};

// AssetAddress

class AssetAddress{
  public:
    // \brief Constructor.
    AssetAddress();
    AssetAddress(std::string jsonString);

    // \brief Destructor.
    virtual ~AssetAddress();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::string quantity;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Asset_H_ */
