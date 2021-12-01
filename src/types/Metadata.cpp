#include "Metadata.h"

using namespace Blockfrost;

TxMeta::TxMeta()
{
  label = std::string();
  cip10 = std::make_pair(std::string(), false);
  count = std::string();
}

TxMeta::TxMeta(std::string jsonString)
{
  this->fromJson(jsonString);
}

TxMeta::~TxMeta()
{
}

void
TxMeta::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(label, "std::string");
    fromJSONMay(cip10, "std::string");
    fromJSON(count, "std::string");
}

bourne::json
TxMeta::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(label);
    toJSONMay(cip10);
    toJSON(count);

    return object;
}

// TxMetaJSON

TxMetaJSON::TxMetaJSON()
{
  tx_hash = std::string();
  json_metadata = std::make_pair(bourne::json(), false);
}

TxMetaJSON::TxMetaJSON(std::string jsonString)
{
  this->fromJson(jsonString);
}

TxMetaJSON::~TxMetaJSON()
{
}

void
TxMetaJSON::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    if(!object["json_metadata"].is_null()) {
      json_metadata.first = object["json_metadata"];
      json_metadata.second = true;
    }
}

bourne::json
TxMetaJSON::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    if(json_metadata.second) {
      object["json_metadata"] = json_metadata.first;
    } else {
      object["json_metadata"] = nullptr;
    };

    return object;
}

// TxMetaCBOR

TxMetaCBOR::TxMetaCBOR()
{
  tx_hash = std::string();
  metadata = std::make_pair(std::string(), false);
}

TxMetaCBOR::TxMetaCBOR(std::string jsonString)
{
  this->fromJson(jsonString);
}

TxMetaCBOR::~TxMetaCBOR()
{
}

void
TxMetaCBOR::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    if(!object["metadata"].is_null()) {
      metadata.first = object["metadata"].to_string();
      metadata.second = true;
    }
}

bourne::json
TxMetaCBOR::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    if(metadata.second) {
      object["metadata"] = metadata.first;
    } else {
      object["metadata"] = nullptr;
    };

    return object;
}
