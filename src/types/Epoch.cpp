#include "Epoch.h"

using namespace Blockfrost;

Epoch::Epoch()
{
  epoch = int(0);
  start_time = time_t(0);
  end_time = time_t(0);
  first_block_time = time_t(0);
  last_block_time = time_t(0);
  block_count = int(0);
  tx_count = int(0);
  output = std::string();
  fees = std::string();
  active_stake = std::make_pair(std::string(), false);
}

Epoch::Epoch(std::string jsonString)
{
  this->fromJson(jsonString);
}

Epoch::~Epoch()
{
}

void
Epoch::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(epoch, "int");
    fromJSON(start_time, "time_t");
    fromJSON(end_time, "time_t");
    fromJSON(first_block_time, "time_t");
    fromJSON(last_block_time, "time_t");
    fromJSON(block_count, "int");
    fromJSON(tx_count, "int");
    fromJSON(output, "std::string");
    fromJSON(fees, "std::string");
    fromJSONMay(active_stake, "std::string");
}

bourne::json
Epoch::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(epoch);
    toJSON(start_time);
    toJSON(end_time);
    toJSON(first_block_time);
    toJSON(last_block_time);
    toJSON(block_count);
    toJSON(tx_count);
    toJSON(output);
    toJSON(fees);
    toJSONMay(active_stake);

    return object;
}

// ProtocolParams

ProtocolParams::ProtocolParams()
{
  epoch = int(0);
  min_fee_a = int(0);
  min_fee_b = int(0);
  max_block_size = int(0);
  max_tx_size = int(0);
  max_block_header_size = int(0);
  key_deposit = std::string();
  pool_deposit = std::string();
  e_max = int(0);
  n_opt = int(0);
  a0 = double(0);
  rho = double(0);
  tau = double(0);
  decentralisation_param = double(0);
  extra_entropy = std::make_pair(bourne::json(), false);

  protocol_major_ver = int(0);
  protocol_minor_ver = int(0);
  min_utxo = std::string();
  min_pool_cost = std::string();
  nonce = std::string();

  price_mem = double(0);
  price_step = double(0);
  max_tx_ex_mem = std::string();
  max_tx_ex_steps = std::string();
  max_block_ex_mem = std::string();
  max_block_ex_steps = std::string();
  max_val_size = std::string();
  collateral_percent = int(0);
  max_collateral_inputs = int(0);
  coins_per_utxo_word = std::string();
}

ProtocolParams::ProtocolParams(std::string jsonString)
{
  this->fromJson(jsonString);
}

ProtocolParams::~ProtocolParams()
{
}

void
ProtocolParams::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(epoch, "int");
    fromJSON(min_fee_a, "int");
    fromJSON(min_fee_b, "int");
    fromJSON(max_block_size, "int");
    fromJSON(max_tx_size, "int");
    fromJSON(max_block_header_size, "int");
    fromJSON(key_deposit, "std::string");
    fromJSON(pool_deposit, "std::string");
    fromJSON(e_max, "int");
    fromJSON(n_opt, "int");
    fromJSON(a0, "double");
    fromJSON(rho, "double");
    fromJSON(tau, "double");
    fromJSON(decentralisation_param, "double");
    if(!object["extra_entropy"].is_null()) {
      extra_entropy.first = object["extra_entropy"];
      extra_entropy.second = true;
    }
    fromJSON(protocol_major_ver, "int");
    fromJSON(protocol_minor_ver, "int");
    fromJSON(min_utxo, "std::string");
    fromJSON(min_pool_cost, "std::string");
    fromJSON(nonce, "std::string");

    fromJSON(price_mem, "double");
    fromJSON(price_step, "double");
    fromJSON(max_tx_ex_mem, "std::string");
    fromJSON(max_tx_ex_steps, "std::string");
    fromJSON(max_block_ex_mem, "std::string");
    fromJSON(max_block_ex_steps, "std::string");
    fromJSON(max_val_size, "std::string");
    fromJSON(collateral_percent, "int");
    fromJSON(max_collateral_inputs, "int");
    fromJSON(coins_per_utxo_word, "std::string");
}

bourne::json
ProtocolParams::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(epoch);
    toJSON(min_fee_a);
    toJSON(min_fee_b);
    toJSON(max_block_size);
    toJSON(max_tx_size);
    toJSON(max_block_header_size);
    toJSON(key_deposit);
    toJSON(pool_deposit);
    toJSON(e_max);
    toJSON(n_opt);
    toJSON(a0);
    toJSON(rho);
    toJSON(tau);
    toJSON(decentralisation_param);
    if(extra_entropy.second) {
      object["extra_entropy"] = extra_entropy.first;
    } else {
      object["extra_entropy"] = nullptr;
    };
    toJSON(protocol_major_ver);
    toJSON(protocol_minor_ver);
    toJSON(min_utxo);
    toJSON(min_pool_cost);
    toJSON(nonce);

    toJSON(price_mem);
    toJSON(price_step);
    toJSON(max_tx_ex_mem);
    toJSON(max_tx_ex_steps);
    toJSON(max_block_ex_mem);
    toJSON(max_block_ex_steps);
    toJSON(max_val_size);
    toJSON(collateral_percent);
    toJSON(max_collateral_inputs);
    toJSON(coins_per_utxo_word);

    return object;
}

// StakeDistribution

StakeDistribution::StakeDistribution()
{
  stake_address = std::string();
  pool_id = std::string();
  amount = std::string();
}

StakeDistribution::StakeDistribution(std::string jsonString)
{
  this->fromJson(jsonString);
}

StakeDistribution::~StakeDistribution()
{
}

void
StakeDistribution::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(stake_address, "std::string");
    fromJSON(pool_id, "std::string");
    fromJSON(amount, "std::string");
}

bourne::json
StakeDistribution::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(stake_address);
    toJSON(pool_id);
    toJSON(amount);

    return object;
}

// PoolStakeDistribution

PoolStakeDistribution::PoolStakeDistribution()
{
  stake_address = std::string();
  amount = std::string();
}

PoolStakeDistribution::PoolStakeDistribution(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolStakeDistribution::~PoolStakeDistribution()
{
}

void
PoolStakeDistribution::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(stake_address, "std::string");
    fromJSON(amount, "std::string");
}

bourne::json
PoolStakeDistribution::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(stake_address);
    toJSON(amount);

    return object;
}

