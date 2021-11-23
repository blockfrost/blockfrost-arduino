#include "Pool.h"

using namespace Blockfrost;

// PoolEpoch

PoolEpoch::PoolEpoch()
{
  pool_id = std::string();
  epoch = int(0);
}

PoolEpoch::PoolEpoch(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolEpoch::~PoolEpoch()
{
}

void
PoolEpoch::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(pool_id, "std::string");
    fromJSON(epoch, "int");
}

bourne::json
PoolEpoch::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(pool_id);
    toJSON(epoch);

    return object;
}

// PoolInfo

PoolInfo::PoolInfo()
{
  pool_id = std::string();
  hex = std::string();
  vrf_key = std::string();
  blocks_minted = int(0);
  live_stake = std::string();
  live_size = double(0);
  live_saturation = double(0);
  active_stake = std::string();
  active_size = double(0);
  declared_pledge = std::string();
  live_pledge = std::string();
  margin_cost = double(0);
  fixed_cost = std::string();
  reward_account = std::string();
  owners = std::vector<std::string>();
  registration = std::vector<std::string>();
  retirement = std::vector<std::string>();
}

PoolInfo::PoolInfo(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolInfo::~PoolInfo()
{
}

void
PoolInfo::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(pool_id, "std::string");
    fromJSON(hex, "std::string");
    fromJSON(vrf_key, "std::string");
    fromJSON(blocks_minted, "int");
    fromJSON(live_stake, "std::string");
    fromJSON(live_size, "double");
    fromJSON(live_saturation, "double");
    fromJSON(live_delegators, "double");
    fromJSON(active_stake, "std::string");
    fromJSON(active_size, "double");
    fromJSON(declared_pledge, "std::string");
    fromJSON(live_pledge, "std::string");
    fromJSON(margin_cost, "double");
    fromJSON(fixed_cost, "std::string");
    fromJSON(reward_account, "std::string");
    for(auto& var: object["owners"].array_range()) {
      owners.push_back(var.to_string());
    }
    for(auto& var: object["registration"].array_range()) {
      registration.push_back(var.to_string());
    }
    for(auto& var: object["retirement"].array_range()) {
      retirement.push_back(var.to_string());
    }
}

bourne::json
PoolInfo::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(pool_id);
    toJSON(hex);
    toJSON(vrf_key);
    toJSON(blocks_minted);
    toJSON(live_stake);
    toJSON(live_size);
    toJSON(live_saturation);
    toJSON(live_delegators);
    toJSON(active_stake);
    toJSON(active_size);
    toJSON(declared_pledge);
    toJSON(live_pledge);
    toJSON(margin_cost);
    toJSON(fixed_cost);
    toJSON(reward_account);

    std::size_t index = 0;
    auto arrOwners = bourne::json(bourne::class_type::array);
    for(auto o: owners) {
      arrOwners[index] = o;
      index++;
    }
    object["owners"] = arrOwners;

    index = 0;
    auto arrRegistration = bourne::json(bourne::class_type::array);
    for(auto r: registration) {
      arrRegistration[index] = r;
      index++;
    }
    object["registration"] = arrRegistration;

    index = 0;
    auto arrRetirement = bourne::json(bourne::class_type::array);
    for(auto r: retirement) {
      arrRetirement[index] = r;
      index++;
    }
    object["retirement"] = arrRetirement;

    return object;
}

// PoolHistory

PoolHistory::PoolHistory()
{
  epoch = int(0);
  blocks = int(0);
  active_stake = std::string();
  active_size = double(0);
  delegators_count = int(0);
  rewards = std::string();
  fees = std::string();
}

PoolHistory::PoolHistory(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolHistory::~PoolHistory()
{
}

void
PoolHistory::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(epoch, "int");
    fromJSON(blocks, "int");
    fromJSON(active_stake, "std::string");
    fromJSON(active_size, "double");
    fromJSON(delegators_count, "int");
    fromJSON(rewards, "std::string");
    fromJSON(fees, "std::string");
}

bourne::json
PoolHistory::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(epoch);
    toJSON(blocks);
    toJSON(active_stake);
    toJSON(active_size);
    toJSON(delegators_count);
    toJSON(rewards);
    toJSON(fees);

    return object;
}

// PoolMetadata

PoolMetadata::PoolMetadata()
{
  pool_id = std::string();
  hex = std::string();
  url = std::make_pair(std::string(), false);
  hash = std::make_pair(std::string(), false);
  ticker = std::make_pair(std::string(), false);
  name = std::make_pair(std::string(), false);
  description = std::make_pair(std::string(), false);
  homepage = std::make_pair(std::string(), false);
}

PoolMetadata::PoolMetadata(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolMetadata::~PoolMetadata()
{
}

void
PoolMetadata::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(pool_id, "std::string");
    fromJSON(hex, "std::string");
    fromJSONMay(url, "std::string");
    fromJSONMay(hash, "std::string");
    fromJSONMay(ticker, "std::string");
    fromJSONMay(name, "std::string");
    fromJSONMay(description, "std::string");
    fromJSONMay(homepage, "std::string");
}

bourne::json
PoolMetadata::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(pool_id);
    toJSON(hex);
    toJSONMay(url);
    toJSONMay(hash);
    toJSONMay(ticker);
    toJSONMay(name);
    toJSONMay(description);
    toJSONMay(homepage);

    return object;
}

// PoolRelay

PoolRelay::PoolRelay()
{
  ipv4 = std::make_pair(std::string(), false);
  ipv6 = std::make_pair(std::string(), false);
  dns = std::make_pair(std::string(), false);
  dns_srv = std::make_pair(std::string(), false);
  port = int(0);
}

PoolRelay::PoolRelay(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolRelay::~PoolRelay()
{
}

void
PoolRelay::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSONMay(ipv4, "std::string");
    fromJSONMay(ipv6, "std::string");
    fromJSONMay(dns, "std::string");
    fromJSONMay(dns_srv, "std::string");
    fromJSON(port, "int");
}

bourne::json
PoolRelay::toJson()
{
    bourne::json object = bourne::json::object();

    toJSONMay(ipv4);
    toJSONMay(ipv6);
    toJSONMay(dns);
    toJSONMay(dns_srv);
    toJSON(port);

    return object;
}

// PoolDelegator

PoolDelegator::PoolDelegator()
{
  address = std::string();
  live_stake = std::string();
}

PoolDelegator::PoolDelegator(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolDelegator::~PoolDelegator()
{
}

void
PoolDelegator::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    fromJSON(live_stake, "std::string");
}

bourne::json
PoolDelegator::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    toJSON(live_stake);

    return object;
}

// PoolUpdate

PoolUpdate::PoolUpdate()
{
  tx_hash = std::string();
  cert_index = int(0);
  action = std::string();
}

PoolUpdate::PoolUpdate(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolUpdate::~PoolUpdate()
{
}

void
PoolUpdate::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(cert_index, "int");
    fromJSON(action, "std::string");
}

bourne::json
PoolUpdate::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(cert_index);
    toJSON(action);

    return object;
}
