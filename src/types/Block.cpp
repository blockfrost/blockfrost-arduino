#include "Block.h"

using namespace Blockfrost;

Block::Block()
{
  time = int(0);
  height = std::make_pair(int(0), false);
  hash = std::string();
  slot = std::make_pair(int(0), false);
  epoch = std::make_pair(int(0), false);
  epoch_slot = std::make_pair(int(0), false);
  slot_leader = std::string();
  size = int(0);
  tx_count = int(0);
  output = std::make_pair(std::string(), false);
  fees = std::make_pair(std::string(), false);
  block_vrf = std::make_pair(std::string(), false);
  previous_block = std::make_pair(std::string(), false);
  next_block = std::make_pair(std::string(), false);
  confirmations = int(0);
}

Block::Block(std::string jsonString)
{
  this->fromJson(jsonString);
}

Block::~Block()
{
}

void
Block::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(time, "int");
    fromJSONMay(height, "int");
    fromJSON(hash, "std::string");
    fromJSONMay(slot, "int");
    fromJSONMay(epoch, "int");
    fromJSONMay(epoch_slot, "int");
    fromJSON(slot_leader, "std::string");
    fromJSON(size, "int");
    fromJSON(tx_count, "int");
    fromJSONMay(output, "std::string");
    fromJSONMay(fees, "std::string");
    fromJSONMay(block_vrf, "std::string");
    fromJSONMay(previous_block, "std::string");
    fromJSONMay(next_block, "std::string");
    fromJSON(confirmations, "int");
}

bourne::json
Block::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(time);
    toJSONMay(height);
    toJSON(hash);
    toJSONMay(slot);
    toJSONMay(epoch);
    toJSONMay(epoch_slot);
    toJSON(slot_leader);
    toJSON(size);
    toJSON(tx_count);
    toJSONMay(output);
    toJSONMay(fees);
    toJSONMay(block_vrf);
    toJSONMay(previous_block);
    toJSONMay(next_block);
    toJSON(confirmations);

    return object;
}
