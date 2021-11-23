#include "Asset.h"

using namespace Blockfrost;

// Asset

Asset::Asset()
{
  asset = std::string();
  quantity = std::string();
}

Asset::Asset(std::string jsonString)
{
  this->fromJson(jsonString);
}

Asset::~Asset()
{
}

void
Asset::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(asset, "std::string");
    fromJSON(quantity, "std::string");
}

bourne::json
Asset::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(asset);
    toJSON(quantity);

    return object;
}

// AssetOnChainMetadata

AssetOnChainMetadata::AssetOnChainMetadata()
{
  name = std::string();
  image = std::string();
}

AssetOnChainMetadata::AssetOnChainMetadata(std::string jsonString)
{
  this->fromJson(jsonString);
}

AssetOnChainMetadata::~AssetOnChainMetadata()
{
}

void
AssetOnChainMetadata::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(name, "std::string");
    fromJSON(image, "std::string");
}

bourne::json
AssetOnChainMetadata::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(name);
    toJSON(image);

    return object;
}

// AssetMetadata

AssetMetadata::AssetMetadata()
{
  name = std::string();
  description = std::string();
  ticker = std::make_pair(std::string(), false);
  url = std::make_pair(std::string(), false);
  //logo = std::make_pair(std::string(), false);
  decimals = std::make_pair(int(0), false);
}

AssetMetadata::AssetMetadata(std::string jsonString)
{
  this->fromJson(jsonString);
}

AssetMetadata::~AssetMetadata()
{
}

void
AssetMetadata::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(name, "std::string");
    fromJSON(description, "std::string");
    fromJSONMay(ticker, "std::string");
    fromJSONMay(url, "std::string");
    //fromJSONMay(logo, "std::string");
    fromJSONMay(decimals, "int");
}

bourne::json
AssetMetadata::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(name);
    toJSON(description);
    toJSONMay(ticker);
    toJSONMay(url);
    toJSONMay(logo);
    toJSONMay(decimals);

    return object;
}

// AssetDetail

AssetDetail::AssetDetail()
{
  asset = std::string();
  policy_id = std::string();
  asset_name = std::string();
  fingerprint = std::string();
  quantity = std::string();
  initial_mint_tx_hash = std::string();
  mint_or_burn_count = int(0);

  onchain_metadata = std::make_pair(AssetOnChainMetadata(), false);
  metadata = std::make_pair(AssetMetadata(), false);
}

AssetDetail::AssetDetail(std::string jsonString)
{
  this->fromJson(jsonString);
}

AssetDetail::~AssetDetail()
{
}

void
AssetDetail::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(asset, "std::string");
    fromJSON(policy_id, "std::string");
    fromJSON(asset_name, "std::string");
    fromJSON(fingerprint, "std::string");
    fromJSON(quantity, "std::string");
    fromJSON(initial_mint_tx_hash, "std::string");
    fromJSON(mint_or_burn_count, "int");
    if(!object["onchain_metadata"].is_null()) {
      AssetOnChainMetadata tmp(object["onchain_metadata"].dump());
      onchain_metadata.first = tmp;
      onchain_metadata.second = true;
    }
    if(!object["metadata"].is_null()) {
      AssetMetadata tmp(object["metadata"].dump());
      metadata.first = tmp;
      metadata.second = true;
    }
}

bourne::json
AssetDetail::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(asset);
    toJSON(policy_id);
    toJSON(asset_name);
    toJSON(fingerprint);
    toJSON(quantity);
    toJSON(initial_mint_tx_hash);
    toJSON(mint_or_burn_count);
    if(onchain_metadata.second) {
      object["onchain_metadata"] = onchain_metadata.first.toJson();
    }
    if(metadata.second) {
      object["metadata"] = metadata.first.toJson();
    }

    return object;
}

// AssetHistory

AssetHistory::AssetHistory()
{
  tx_hash = std::string();
  amount = std::string();
  action = std::string();
}

AssetHistory::AssetHistory(std::string jsonString)
{
  this->fromJson(jsonString);
}

AssetHistory::~AssetHistory()
{
}

void
AssetHistory::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(amount, "std::string");
    fromJSON(action, "std::string");
}

bourne::json
AssetHistory::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(amount);
    toJSON(action);

    return object;
}

// AssetTransaction

AssetTransaction::AssetTransaction()
{
  tx_hash = std::string();
  tx_index = int(0);
  block_height = int(0);
}

AssetTransaction::AssetTransaction(std::string jsonString)
{
  this->fromJson(jsonString);
}

AssetTransaction::~AssetTransaction()
{
}

void
AssetTransaction::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(tx_index, "int");
    fromJSON(block_height, "int");
}

bourne::json
AssetTransaction::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(tx_index);
    toJSON(block_height);

    return object;
}

// AssetAddress

AssetAddress::AssetAddress()
{
  address = std::string();
  quantity = std::string();
}

AssetAddress::AssetAddress(std::string jsonString)
{
  this->fromJson(jsonString);
}

AssetAddress::~AssetAddress()
{
}

void
AssetAddress::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    fromJSON(quantity, "std::string");
}

bourne::json
AssetAddress::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    toJSON(quantity);

    return object;
}
