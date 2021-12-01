#include "IPFS.h"

using namespace Blockfrost;

IPFSAdd::IPFSAdd()
{
  name = std::string();
  ipfs_hash = std::string();
  size = std::string();
}

IPFSAdd::IPFSAdd(std::string jsonString)
{
  this->fromJson(jsonString);
}

IPFSAdd::~IPFSAdd()
{
}

void
IPFSAdd::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(name, "std::string");
    fromJSON(ipfs_hash, "std::string");
    fromJSON(size, "std::string");
}

bourne::json
IPFSAdd::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(name);
    toJSON(ipfs_hash);
    toJSON(size);

    return object;
}

// IPFSPinChange

IPFSPinChange::IPFSPinChange()
{
  ipfs_hash = std::string();
  state = std::string();
}

IPFSPinChange::IPFSPinChange(std::string jsonString)
{
  this->fromJson(jsonString);
}

IPFSPinChange::~IPFSPinChange()
{
}

void
IPFSPinChange::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(ipfs_hash, "std::string");
    fromJSON(state, "std::string");
}

bourne::json
IPFSPinChange::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(ipfs_hash);
    toJSON(state);

    return object;
}

// IPFSPin

IPFSPin::IPFSPin()
{
  time_created = time_t(0);
  time_pinned = time_t(0);
  ipfs_hash = std::string();
  size = std::string();
  state = std::string();
}

IPFSPin::IPFSPin(std::string jsonString)
{
  this->fromJson(jsonString);
}

IPFSPin::~IPFSPin()
{
}

void
IPFSPin::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(time_created, "time_t");
    fromJSON(time_pinned, "time_t");
    fromJSON(ipfs_hash, "std::string");
    fromJSON(size, "std::string");
    fromJSON(state, "std::string");
}

bourne::json
IPFSPin::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(time_created);
    toJSON(time_pinned);
    toJSON(ipfs_hash);
    toJSON(size);
    toJSON(state);

    return object;
}


