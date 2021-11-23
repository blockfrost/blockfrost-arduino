/*
 * Address.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Address_H_
#define BLOCKFROST_CPP_CLIENT_Address_H_

#include <list>
#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"
#include "Amount.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Address{
  public:
    // \brief Constructor.
    Address();
    Address(std::string jsonString);

    // \brief Destructor.
    virtual ~Address();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::vector<Amount> amount;
    std::pair<std::string, bool> stake_address;

    std::string type;
    bool script;
};

class AddressDetails{
  public:
    // \brief Constructor.
    AddressDetails();
    AddressDetails(std::string jsonString);

    // \brief Destructor.
    virtual ~AddressDetails();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::vector<Amount> received_sum;
    std::vector<Amount> sent_sum;
    int tx_count;
};

class AddressUtxo{
  public:
    // \brief Constructor.
    AddressUtxo();
    AddressUtxo(std::string jsonString);

    // \brief Destructor.
    virtual ~AddressUtxo();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    int output_index;
    std::vector<Amount> amount;
    std::string block;
    std::pair<std::string, bool> data_hash;
};

class AddressTransaction{
  public:
    // \brief Constructor.
    AddressTransaction();
    AddressTransaction(std::string jsonString);

    // \brief Destructor.
    virtual ~AddressTransaction();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    int tx_index;
    int block_height;
};


}

#endif /* BLOCKFROST_CPP_CLIENT_Address_H_ */
