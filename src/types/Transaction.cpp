#include "Transaction.h"

using namespace Blockfrost;

Transaction::Transaction()
{
    hash = std::string();
    block = std::string();
    block_height = int(0);
    slot = int(0);
    index = int(0);
    output_amount = std::vector<Amount>();
    fees = std::string();
    deposit = std::string();
    size = int(0);
    invalid_before = std::make_pair(std::string(), false);
    invalid_hereafter = std::make_pair(std::string(), false);
    utxo_count = int(0);
    withdrawal_count = int(0);
    mir_cert_count = int(0);
    delegation_count = int(0);
    stake_cert_count = int(0);
    pool_update_count = int(0);
    pool_retire_count = int(0);
    asset_mint_or_burn_count = int(0);
    redeemer_count = int(0);
}

Transaction::Transaction(std::string jsonString)
{
    this->fromJson(jsonString);

}

Transaction::~Transaction()
{
}

void
Transaction::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(hash, "std::string");
    fromJSON(block, "std::string");
    fromJSON(block_height, "int");
    fromJSON(slot, "int");
    fromJSON(index, "int");

    for(auto& var: object["output_amount"].array_range()) {
      Amount tmp(var.dump());
      output_amount.push_back(tmp);
    }

    fromJSON(fees, "std::string");
    fromJSON(deposit, "std::string");
    fromJSON(size, "int");
    fromJSONMay(invalid_before, "std::string");
    fromJSONMay(invalid_hereafter, "std::string");
    fromJSON(utxo_count, "int");
    fromJSON(withdrawal_count, "int");
    fromJSON(mir_cert_count, "int");
    fromJSON(delegation_count, "int");
    fromJSON(stake_cert_count, "int");
    fromJSON(pool_update_count, "int");
    fromJSON(pool_retire_count, "int");
    fromJSON(asset_mint_or_burn_count, "int");
    fromJSON(redeemer_count, "int");
}

bourne::json
Transaction::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(hash);
    toJSON(block);
    toJSON(block_height);
    toJSON(slot);
    toJSON(index);

    std::size_t i = 0;
    auto arr = bourne::json(bourne::class_type::array);
    for(auto amt: output_amount) {
      arr[i] = amt.toJson();
      i++;
    }
    object["output_amount"] = arr;

    toJSON(fees);
    toJSON(deposit);
    toJSON(size);
    toJSONMay(invalid_before);
    toJSONMay(invalid_hereafter);
    toJSON(utxo_count);
    toJSON(withdrawal_count);
    toJSON(mir_cert_count);
    toJSON(delegation_count);
    toJSON(stake_cert_count);
    toJSON(pool_update_count);
    toJSON(pool_retire_count);
    toJSON(asset_mint_or_burn_count);
    toJSON(redeemer_count);

    return object;
}

// UtxoInput

UtxoInput::UtxoInput()
{
  address = std::string();
  amount = std::vector<Amount>();
  tx_hash = std::string();
  output_index = int(0);
  collateral = false;
  data_hash = std::make_pair(std::string(), false);
}

UtxoInput::UtxoInput(std::string jsonString)
{
  this->fromJson(jsonString);
}

UtxoInput::~UtxoInput()
{
}

void
UtxoInput::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");

    for(auto& var: object["amount"].array_range()) {
      Amount tmp(var.dump());
      amount.push_back(tmp);
    }

    fromJSON(tx_hash, "std::string");
    fromJSON(output_index, "int");
    fromJSON(collateral, "bool");
    fromJSONMay(data_hash, "std::string");
}

bourne::json
UtxoInput::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);

    std::size_t i = 0;
    auto arr = bourne::json(bourne::class_type::array);
    for(auto amt: amount) {
      arr[i] = amt.toJson();
      i++;
    }
    object["amount"] = arr;

    toJSON(tx_hash);
    toJSON(output_index);
    toJSON(collateral);
    toJSONMay(data_hash);

    return object;
}

// UtxoOutput

UtxoOutput::UtxoOutput()
{
  address = std::string();
  amount = std::vector<Amount>();
  data_hash = std::make_pair(std::string(), false);
  output_index = int(0);
}

UtxoOutput::UtxoOutput(std::string jsonString)
{
  this->fromJson(jsonString);
}

UtxoOutput::~UtxoOutput()
{
}

void
UtxoOutput::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");

    for(auto& var: object["amount"].array_range()) {
      Amount tmp(var.dump());
      amount.push_back(tmp);
    }

    fromJSONMay(data_hash, "std::string");
    fromJSON(output_index, "int");
}

bourne::json
UtxoOutput::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);

    std::size_t i = 0;
    auto arr = bourne::json(bourne::class_type::array);
    for(auto amt: amount) {
      arr[i] = amt.toJson();
      i++;
    }
    object["amount"] = arr;

    toJSONMay(data_hash);
    toJSON(output_index);

    return object;
}

// TransactionUtxos

TransactionUtxos::TransactionUtxos()
{
  hash = std::string();
  inputs = std::vector<UtxoInput>();
  outputs = std::vector<UtxoOutput>();
}

TransactionUtxos::TransactionUtxos(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionUtxos::~TransactionUtxos()
{
}

void
TransactionUtxos::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(hash, "std::string");

    for(auto& var: object["inputs"].array_range()) {
      UtxoInput tmp(var.dump());
      inputs.push_back(tmp);
    }

    for(auto& var: object["outputs"].array_range()) {
      UtxoOutput tmp(var.dump());
      outputs.push_back(tmp);
    }
}

bourne::json
TransactionUtxos::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(hash);

    std::size_t i = 0;
    auto arrIns = bourne::json(bourne::class_type::array);
    for(auto inp: inputs) {
      arrIns[i] = inp.toJson();
      i++;
    }
    object["inputs"] = arrIns;

    i = 0;
    auto arrOuts = bourne::json(bourne::class_type::array);
    for(auto out: outputs) {
      arrOuts[i] = out.toJson();
      i++;
    }
    object["outputs"] = arrOuts;

    return object;
}

// TransactionRedeemer

TransactionRedeemer::TransactionRedeemer()
{
  tx_index = int(0);
  purpose = std::string();
  script_hash = std::string();
  datum_hash = std::string();
  unit_mem = std::string();
  unit_steps = std::string();
  fee = std::string();
}

TransactionRedeemer::TransactionRedeemer(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionRedeemer::~TransactionRedeemer()
{
}

void
TransactionRedeemer::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_index, "int");
    fromJSON(purpose, "std::string");
    fromJSON(script_hash, "std::string");
    fromJSON(datum_hash, "std::string");
    fromJSON(unit_mem, "std::string");
    fromJSON(unit_steps, "std::string");
    fromJSON(fee, "std::string");
}

bourne::json
TransactionRedeemer::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_index);
    toJSON(purpose);
    toJSON(script_hash);
    toJSON(datum_hash);
    toJSON(unit_mem);
    toJSON(unit_steps);
    toJSON(fee);

    return object;
}

// TransactionStake

TransactionStake::TransactionStake()
{
  cert_index = int(0);
  address = std::string();
  registration = false;
}

TransactionStake::TransactionStake(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionStake::~TransactionStake()
{
}

void
TransactionStake::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(cert_index, "int");
    fromJSON(address, "std::string");
    fromJSON(registration, "bool");
}

bourne::json
TransactionStake::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(cert_index);
    toJSON(address);
    toJSON(registration);

    return object;
}

// TransactionDelegation

TransactionDelegation::TransactionDelegation()
{
  cert_index = int(0);
  address = std::string();
  pool_id = std::string();
  active_epoch = int(0);
}

TransactionDelegation::TransactionDelegation(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionDelegation::~TransactionDelegation()
{
}

void
TransactionDelegation::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(cert_index, "int");
    fromJSON(address, "std::string");
    fromJSON(pool_id, "std::string");
    fromJSON(active_epoch, "int");
}

bourne::json
TransactionDelegation::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(cert_index);
    toJSON(address);
    toJSON(pool_id);
    toJSON(active_epoch);

    return object;
}

// TransactionWithdrawal

TransactionWithdrawal::TransactionWithdrawal()
{
  address = std::string();
  amount = std::string();
}

TransactionWithdrawal::TransactionWithdrawal(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionWithdrawal::~TransactionWithdrawal()
{
}

void
TransactionWithdrawal::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(address, "std::string");
    fromJSON(amount, "std::string");
}

bourne::json
TransactionWithdrawal::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(address);
    toJSON(amount);

    return object;
}

// TransactionMir

TransactionMir::TransactionMir()
{
  pot = std::string();
  cert_index = int(0);
  address = std::string();
  amount = std::string();
}

TransactionMir::TransactionMir(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionMir::~TransactionMir()
{
}

void
TransactionMir::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(pot, "std::string");
    fromJSON(cert_index, "int");
    fromJSON(address, "std::string");
    fromJSON(amount, "std::string");
}

bourne::json
TransactionMir::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(pot);
    toJSON(cert_index);
    toJSON(address);
    toJSON(amount);

    return object;
}

// PoolUpdateMetadata

PoolUpdateMetadata::PoolUpdateMetadata()
{
  url = std::make_pair(std::string(), false);
  hash = std::make_pair(std::string(), false);
  ticker = std::make_pair(std::string(), false);
  name = std::make_pair(std::string(), false);
  description = std::make_pair(std::string(), false);
  homepage = std::make_pair(std::string(), false);
}

PoolUpdateMetadata::PoolUpdateMetadata(std::string jsonString)
{
  this->fromJson(jsonString);
}

PoolUpdateMetadata::~PoolUpdateMetadata()
{
}

void
PoolUpdateMetadata::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSONMay(url, "std::string");
    fromJSONMay(hash, "std::string");
    fromJSONMay(ticker, "std::string");
    fromJSONMay(name, "std::string");
    fromJSONMay(description, "std::string");
    fromJSONMay(homepage, "std::string");
}

bourne::json
PoolUpdateMetadata::toJson()
{
    bourne::json object = bourne::json::object();

    toJSONMay(url);
    toJSONMay(hash);
    toJSONMay(ticker);
    toJSONMay(name);
    toJSONMay(description);
    toJSONMay(homepage);

    return object;
}

// TransactionPoolUpdate

TransactionPoolUpdate::TransactionPoolUpdate()
{
    cert_index = int(0);
    pool_id = std::string();
    vrf_key = std::string();
    pledge = std::string();
    margin_cost = double(0);
    fixed_cost = std::string();
    reward_account = std::string();
    owners = std::vector<std::string>();
    metadata = std::make_pair(PoolUpdateMetadata(), false);
    relays = std::vector<PoolRelay>();
    active_epoch = int(0);
}

TransactionPoolUpdate::TransactionPoolUpdate(std::string jsonString)
{
    this->fromJson(jsonString);

}

TransactionPoolUpdate::~TransactionPoolUpdate()
{
}

void
TransactionPoolUpdate::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(cert_index, "int");
    fromJSON(pool_id, "std::string");
    fromJSON(vrf_key, "std::string");
    fromJSON(pledge, "std::string");
    fromJSON(margin_cost, "double");
    fromJSON(fixed_cost, "std::string");
    fromJSON(reward_account, "std::string");

    for(auto& var: object["owners"].array_range()) {
      owners.push_back(var.to_string());
    }

    if(!object["metadata"].is_null()) {
      PoolUpdateMetadata tmp(object["metadata"].dump());
      metadata.first = tmp;
      metadata.second = true;
    }

    for(auto& var: object["relays"].array_range()) {
      PoolRelay tmp(var.dump());
      relays.push_back(tmp);
    }

    fromJSON(active_epoch, "int");
}

bourne::json
TransactionPoolUpdate::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(cert_index);
    toJSON(pool_id);
    toJSON(vrf_key);
    toJSON(pledge);
    toJSON(margin_cost);
    toJSON(fixed_cost);
    toJSON(reward_account);

    std::size_t i = 0;
    auto arrOwners = bourne::json(bourne::class_type::array);
    for(auto o: owners) {
      arrOwners[i] = o;
      i++;
    }
    object["owners"] = arrOwners;

    if(metadata.second) {
      object["metadata"] = metadata.first.toJson();
    }

    i = 0;
    auto arrRelays = bourne::json(bourne::class_type::array);
    for(auto relay: relays) {
      arrRelays[i] = relay.toJson();
      i++;
    }
    object["relays"] = arrRelays;

    toJSON(active_epoch);

    return object;
}

// TransactionPoolRetiring

TransactionPoolRetiring::TransactionPoolRetiring()
{
  cert_index = int(0);
  pool_id = std::string();
  retiring_epoch = int(0);
}

TransactionPoolRetiring::TransactionPoolRetiring(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionPoolRetiring::~TransactionPoolRetiring()
{
}

void
TransactionPoolRetiring::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(cert_index, "int");
    fromJSON(pool_id, "std::string");
    fromJSON(retiring_epoch, "int");
}

bourne::json
TransactionPoolRetiring::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(cert_index);
    toJSON(pool_id);
    toJSON(retiring_epoch);

    return object;
}

// TransactionMetaJSON

TransactionMetaJSON::TransactionMetaJSON()
{
    label = std::string();
    json_metadata = std::make_pair(bourne::json(), false);
}

TransactionMetaJSON::TransactionMetaJSON(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionMetaJSON::~TransactionMetaJSON()
{
}

void
TransactionMetaJSON::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(label, "std::string");
    if(!object["json_metadata"].is_null()) {
      json_metadata.first = object["json_metadata"];
      json_metadata.second = true;
    }
}

bourne::json
TransactionMetaJSON::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(label);
    if(json_metadata.second) {
      object["json_metadata"] = json_metadata.first;
    } else {
      object["json_metadata"] = nullptr;
    };

    return object;
}

// TransactionMetaCBOR

TransactionMetaCBOR::TransactionMetaCBOR()
{
    label = std::string();
    metadata = std::make_pair(std::string(), false);
}

TransactionMetaCBOR::TransactionMetaCBOR(std::string jsonString)
{
  this->fromJson(jsonString);
}

TransactionMetaCBOR::~TransactionMetaCBOR()
{
}

void
TransactionMetaCBOR::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(label, "std::string");
    fromJSONMay(metadata, "std::string");
}

bourne::json
TransactionMetaCBOR::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(label);
    toJSONMay(metadata);

    return object;
}
