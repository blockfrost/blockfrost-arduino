#include "Account.h"

using namespace Blockfrost;

// Account

Account::Account()
{
  stake_address = std::string();
  active = false;
  active_epoch = int(0);

  controlled_amount = std::string();
  rewards_sum = std::string();
  withdrawals_sum = std::string();
  reserves_sum = std::string();
  treasury_sum = std::string();
  withdrawable_amount = std::string();
  pool_id = std::make_pair(std::string(), false);
}

Account::Account(std::string jsonString)
{
  this->fromJson(jsonString);
}

Account::~Account()
{
}

void
Account::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(stake_address, "std::string");
    fromJSON(active, "bool");
    fromJSON(active_epoch, "int");
    fromJSON(controlled_amount, "std::string");
    fromJSON(rewards_sum, "std::string");
    fromJSON(withdrawals_sum, "std::string");
    fromJSON(reserves_sum, "std::string");
    fromJSON(treasury_sum, "std::string");
    fromJSON(withdrawable_amount, "std::string");
    fromJSONMay(pool_id, "std::string");
}

bourne::json
Account::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(stake_address);
    toJSON(active);
    toJSON(active_epoch);
    toJSON(controlled_amount);
    toJSON(rewards_sum);
    toJSON(withdrawals_sum);
    toJSON(reserves_sum);
    toJSON(treasury_sum);
    toJSON(withdrawable_amount);
    toJSONMay(pool_id);

    return object;
}

// AccountReward

AccountReward::AccountReward()
{
  epoch = int(0);
  amount = std::string();
  pool_id = std::string();
}

AccountReward::AccountReward(std::string jsonString)
{
  this->fromJson(jsonString);
}

AccountReward::~AccountReward()
{
}

void
AccountReward::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(epoch, "int");
    fromJSON(amount, "std::string");
    fromJSON(pool_id, "std::string");
}

bourne::json
AccountReward::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(epoch);
    toJSON(amount);
    toJSON(pool_id);

    return object;
}

// AccountHistory

AccountHistory::AccountHistory()
{
  active_epoch = int(0);
  amount = std::string();
  pool_id = std::string();
}

AccountHistory::AccountHistory(std::string jsonString)
{
  this->fromJson(jsonString);
}

AccountHistory::~AccountHistory()
{
}

void
AccountHistory::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(active_epoch, "int");
    fromJSON(amount, "std::string");
    fromJSON(pool_id, "std::string");
}

bourne::json
AccountHistory::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(active_epoch);
    toJSON(amount);
    toJSON(pool_id);

    return object;
}

// AccountDelegation

AccountDelegation::AccountDelegation()
{
  active_epoch = int(0);
  tx_hash = std::string();
  amount = std::string();
  pool_id = std::string();
}

AccountDelegation::AccountDelegation(std::string jsonString)
{
  this->fromJson(jsonString);
}

AccountDelegation::~AccountDelegation()
{
}

void
AccountDelegation::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(active_epoch, "int");
    fromJSON(tx_hash, "std::string");
    fromJSON(amount, "std::string");
    fromJSON(pool_id, "std::string");
}

bourne::json
AccountDelegation::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(active_epoch);
    toJSON(tx_hash);
    toJSON(amount);
    toJSON(pool_id);

    return object;
}

// AccountRegistration

AccountRegistration::AccountRegistration()
{
  action = std::string();
  tx_hash = std::string();
}

AccountRegistration::AccountRegistration(std::string jsonString)
{
  this->fromJson(jsonString);
}

AccountRegistration::~AccountRegistration()
{
}

void
AccountRegistration::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(action, "std::string");
    fromJSON(tx_hash, "std::string");
}

bourne::json
AccountRegistration::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(action);
    toJSON(tx_hash);

    return object;
}

// AccountWithdrawal

AccountWithdrawal::AccountWithdrawal()
{
  amount = std::string();
  tx_hash = std::string();
}

AccountWithdrawal::AccountWithdrawal(std::string jsonString)
{
  this->fromJson(jsonString);
}

AccountWithdrawal::~AccountWithdrawal()
{
}

void
AccountWithdrawal::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(amount, "std::string");
    fromJSON(tx_hash, "std::string");
}

bourne::json
AccountWithdrawal::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(amount);
    toJSON(tx_hash);

    return object;
}

// AccountMir

AccountMir::AccountMir()
{
  amount = std::string();
  tx_hash = std::string();
}

AccountMir::AccountMir(std::string jsonString)
{
  this->fromJson(jsonString);
}

AccountMir::~AccountMir()
{
}

void
AccountMir::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(amount, "std::string");
    fromJSON(tx_hash, "std::string");
}

bourne::json
AccountMir::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(amount);
    toJSON(tx_hash);

    return object;
}
