#include "NutLink.h"

using namespace Blockfrost;

NutLinkAddress::NutLinkAddress()
{
  address = std::string();
  metadata_url = std::string();
  metadata_hash = std::string();
  metadata = std::make_pair(bourne::json(), false);
}

NutLinkAddress::NutLinkAddress(std::string jsonString)
{
  this->fromJson(jsonString);
}

NutLinkAddress::~NutLinkAddress()
{
}

void
NutLinkAddress::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    fromJSON(metadata_url, "std::string");
    fromJSON(metadata_hash, "std::string");
    if(!object["metadata"].is_null()) {
      metadata.first = object["metadata"];
      metadata.second = true;
    }
}

bourne::json
NutLinkAddress::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    toJSON(metadata_url);
    toJSON(metadata_hash);
    if(metadata.second) {
      object["metadata"] = metadata.first;
    } else {
      object["metadata"] = nullptr;
    };

    return object;
}

// NutLinkAddressTicker

NutLinkAddressTicker::NutLinkAddressTicker()
{
  name = std::string();
  count = int(0);
  latest_block = int(0);
}

NutLinkAddressTicker::NutLinkAddressTicker(std::string jsonString)
{
  this->fromJson(jsonString);
}

NutLinkAddressTicker::~NutLinkAddressTicker()
{
}

void
NutLinkAddressTicker::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(name, "std::string");
    fromJSON(count, "int");
    fromJSON(latest_block, "int");
}

bourne::json
NutLinkAddressTicker::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(name);
    toJSON(count);
    toJSON(latest_block);

    return object;
}

// NutLinkTicker

NutLinkTicker::NutLinkTicker()
{
  tx_hash = std::string();
  block_height = int(0);
  tx_index = int(0);
  payload = bourne::json();
}

NutLinkTicker::NutLinkTicker(std::string jsonString)
{
  this->fromJson(jsonString);
}

NutLinkTicker::~NutLinkTicker()
{
}

void
NutLinkTicker::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(block_height, "int");
    fromJSON(tx_index, "int");
    payload = object["payload"];
}

bourne::json
NutLinkTicker::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(block_height);
    toJSON(tx_index);
    object["payload"] = payload;

    return object;
}

// NutLinkTickerAddress

NutLinkTickerAddress::NutLinkTickerAddress()
{
  address = std::string();
  tx_hash = std::string();
  block_height = int(0);
  tx_index = int(0);
  payload = bourne::json();
}

NutLinkTickerAddress::NutLinkTickerAddress(std::string jsonString)
{
  this->fromJson(jsonString);
}

NutLinkTickerAddress::~NutLinkTickerAddress()
{
}

void
NutLinkTickerAddress::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    fromJSON(tx_hash, "std::string");
    fromJSON(block_height, "int");
    fromJSON(tx_index, "int");
    payload = object["payload"];
}

bourne::json
NutLinkTickerAddress::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    toJSON(tx_hash);
    toJSON(block_height);
    toJSON(tx_index);
    object["payload"] = payload;

    return object;
}
