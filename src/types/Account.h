/*
 * Account.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Account_H_
#define BLOCKFROST_CPP_CLIENT_Account_H_

#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Account{
  public:
    // \brief Constructor.
    Account();
    Account(std::string jsonString);

    // \brief Destructor.
    virtual ~Account();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string stake_address;
    bool active;
    int active_epoch;

    std::string controlled_amount;
    std::string rewards_sum;
    std::string withdrawals_sum;
    std::string reserves_sum;
    std::string treasury_sum;
    std::string withdrawable_amount;
    std::pair<std::string, bool> pool_id;
};

class AccountReward{
  public:
    // \brief Constructor.
    AccountReward();
    AccountReward(std::string jsonString);

    // \brief Destructor.
    virtual ~AccountReward();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int epoch;
    std::string amount;
    std::string pool_id;
};

class AccountHistory{
  public:
    // \brief Constructor.
    AccountHistory();
    AccountHistory(std::string jsonString);

    // \brief Destructor.
    virtual ~AccountHistory();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int active_epoch;
    std::string amount;
    std::string pool_id;
};

class AccountDelegation{
  public:
    // \brief Constructor.
    AccountDelegation();
    AccountDelegation(std::string jsonString);

    // \brief Destructor.
    virtual ~AccountDelegation();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int active_epoch;
    std::string tx_hash;
    std::string amount;
    std::string pool_id;
};

class AccountRegistration{
  public:
    // \brief Constructor.
    AccountRegistration();
    AccountRegistration(std::string jsonString);

    // \brief Destructor.
    virtual ~AccountRegistration();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    // TODO: Enum for registration action - registered | deregistered
    std::string action;
    std::string tx_hash;
};

class AccountWithdrawal{
  public:
    // \brief Constructor.
    AccountWithdrawal();
    AccountWithdrawal(std::string jsonString);

    // \brief Destructor.
    virtual ~AccountWithdrawal();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string amount;
    std::string tx_hash;
};

class AccountMir{
  public:
    // \brief Constructor.
    AccountMir();
    AccountMir(std::string jsonString);

    // \brief Destructor.
    virtual ~AccountMir();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string amount;
    std::string tx_hash;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Account_H_ */
