#include "Network.h"

using namespace Blockfrost;

NetworkSupply::NetworkSupply()
{
  max = std::string();
  total = std::string();
  circulating = std::string();
  locked = std::string();
  treasury = std::string();
  reserves = std::string();
}

NetworkSupply::NetworkSupply(std::string jsonString)
{
  this->fromJson(jsonString);
}

NetworkSupply::~NetworkSupply()
{
}

void
NetworkSupply::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(max, "std::string");
    fromJSON(total, "std::string");
    fromJSON(circulating, "std::string");
    fromJSON(locked, "std::string");
    fromJSON(treasury, "std::string");
    fromJSON(reserves, "std::string");
}

bourne::json
NetworkSupply::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(max);
    toJSON(total);
    toJSON(circulating);
    toJSON(locked);
    toJSON(treasury);
    toJSON(reserves);

    return object;
}

// NetworkStake

NetworkStake::NetworkStake()
{
  live = std::string();
  active = std::string();
}

NetworkStake::NetworkStake(std::string jsonString)
{
  this->fromJson(jsonString);
}

NetworkStake::~NetworkStake()
{
}

void
NetworkStake::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(live, "std::string");
    fromJSON(active, "std::string");
}

bourne::json
NetworkStake::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(live);
    toJSON(active);

    return object;
}

// Network

Network::Network()
{
  supply = NetworkSupply();
  stake = NetworkStake();
}

Network::Network(std::string jsonString)
{
  this->fromJson(jsonString);
}

Network::~Network()
{
}

void
Network::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    supply = NetworkSupply(object["supply"].dump());
    stake = NetworkStake(object["stake"].dump());
}

bourne::json
Network::toJson()
{
    bourne::json object = bourne::json::object();

    object["supply"] = supply.toJson();
    object["stake"] = stake.toJson();

    return object;
}
