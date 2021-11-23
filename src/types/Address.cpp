#include "Address.h"

using namespace Blockfrost;

// Address

Address::Address()
{
  address = std::string();
  amount = std::vector<Amount>();
  stake_address = std::make_pair(std::string(), false);

  type = std::string();
  script = false;
}

Address::Address(std::string jsonString)
{
  this->fromJson(jsonString);
}

Address::~Address()
{
}

void
Address::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    for(auto& var: object["amount"].array_range()) {
      Amount tmp(var.dump());
      amount.push_back(tmp);
    }
    fromJSONMay(stake_address, "std::string");

    fromJSON(type, "std::string");
    fromJSON(script, "bool");
}

bourne::json
Address::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    std::size_t index = 0;
    auto arr = bourne::json(bourne::class_type::array);
    for(auto amt: amount) {
      arr[index] = amt.toJson();
      index++;
    }
    object["amount"] = arr;
    toJSONMay(stake_address);
    toJSON(type);
    toJSON(script);

    return object;
}

// AddressDetails

AddressDetails::AddressDetails()
{
  address = std::string();
  received_sum = std::vector<Amount>();
  sent_sum = std::vector<Amount>();
  tx_count = int(0);
}

AddressDetails::AddressDetails(std::string jsonString)
{
  this->fromJson(jsonString);
}

AddressDetails::~AddressDetails()
{
}

void
AddressDetails::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    for(auto& var: object["received_sum"].array_range()) {
      Amount tmp(var.dump());
      received_sum.push_back(tmp);
    }
    for(auto& var: object["sent_sum"].array_range()) {
      Amount tmp(var.dump());
      sent_sum.push_back(tmp);
    }

    fromJSON(tx_count, "int");
}

bourne::json
AddressDetails::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    std::size_t index = 0;
    auto arr = bourne::json(bourne::class_type::array);
    for(auto amt: received_sum) {
      arr[index] = amt.toJson();
      index++;
    }
    object["received_sum"] = arr;

    index = 0;
    auto arrs = bourne::json(bourne::class_type::array);
    for(auto amt: sent_sum) {
      arrs[index] = amt.toJson();
      index++;
    }
    object["sent_sum"] = arrs;

    toJSON(tx_count);

    return object;
}

// AddressUtxo

AddressUtxo::AddressUtxo()
{
  tx_hash = std::string();
  output_index = int(0);
  amount = std::vector<Amount>();
  block = std::string();
  data_hash = std::make_pair(std::string(), false);
}

AddressUtxo::AddressUtxo(std::string jsonString)
{
  this->fromJson(jsonString);
}

AddressUtxo::~AddressUtxo()
{
}

void
AddressUtxo::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(output_index, "int");
    for(auto& var: object["amount"].array_range()) {
      Amount tmp(var.dump());
      amount.push_back(tmp);
    }
    fromJSON(block, "std::string");
    fromJSONMay(data_hash, "std::string");
}

bourne::json
AddressUtxo::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(output_index);
    std::size_t index = 0;
    auto arr = bourne::json(bourne::class_type::array);
    for(auto amt: amount) {
      arr[index] = amt.toJson();
      index++;
    }
    object["amount"] = arr;
    toJSON(block);
    toJSONMay(data_hash);

    return object;
}

// AddressTransaction

AddressTransaction::AddressTransaction()
{
  tx_hash = std::string();
  tx_index = int(0);
  block_height = int(0);
}

AddressTransaction::AddressTransaction(std::string jsonString)
{
  this->fromJson(jsonString);
}

AddressTransaction::~AddressTransaction()
{
}

void
AddressTransaction::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(tx_index, "int");
    fromJSON(block_height, "int");
}

bourne::json
AddressTransaction::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(tx_index);
    toJSON(block_height);

    return object;
}
