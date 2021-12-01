/*
 * Transaction.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Transaction_H_
#define BLOCKFROST_CPP_CLIENT_Transaction_H_

#include <ctime>
#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"
#include "Amount.h"
#include "Pool.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Transaction{
public:

    // \brief Constructor.
    Transaction();
    Transaction(std::string jsonString);

    // \brief Destructor.
    virtual ~Transaction();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string hash;
    std::string block;
    int block_height;
    int slot;
    int index;
    std::vector<Amount> output_amount;
    std::string fees;
    std::string deposit;
    int size;
    std::pair<std::string, bool> invalid_before;
    std::pair<std::string, bool> invalid_hereafter;
    int utxo_count;
    int withdrawal_count;
    int mir_cert_count;
    int delegation_count;
    int stake_cert_count;
    int pool_update_count;
    int pool_retire_count;
    int asset_mint_or_burn_count;
    int redeemer_count;
};

class UtxoInput{
public:

    // \brief Constructor.
    UtxoInput();
    UtxoInput(std::string jsonString);

    // \brief Destructor.
    virtual ~UtxoInput();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::vector<Amount> amount;
    std::string tx_hash;
    int output_index;
    bool collateral;
    std::pair<std::string, bool> data_hash;
};

class UtxoOutput{
public:

    // \brief Constructor.
    UtxoOutput();
    UtxoOutput(std::string jsonString);

    // \brief Destructor.
    virtual ~UtxoOutput();

    // \brief Retrieve a bourne Datum representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::vector<Amount> amount;
    std::pair<std::string, bool> data_hash;
    int output_index;
};

class TransactionUtxos{
public:

    // \brief Constructor.
    TransactionUtxos();
    TransactionUtxos(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionUtxos();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string hash;
    std::vector<UtxoInput> inputs;
    std::vector<UtxoOutput> outputs;
};

class TransactionRedeemer{
public:

    // \brief Constructor.
    TransactionRedeemer();
    TransactionRedeemer(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionRedeemer();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int tx_index;
    std::string purpose;
    std::string script_hash;
    std::string datum_hash;
    std::string unit_mem;
    std::string unit_steps;
    std::string fee;
};

class TransactionStake{
public:

    // \brief Constructor.
    TransactionStake();
    TransactionStake(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionStake();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int cert_index;
    std::string address;
    bool registration;
};

class TransactionDelegation{
public:

    // \brief Constructor.
    TransactionDelegation();
    TransactionDelegation(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionDelegation();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int cert_index;
    std::string address;
    std::string pool_id;
    int active_epoch;
};

class TransactionWithdrawal{
public:

    // \brief Constructor.
    TransactionWithdrawal();
    TransactionWithdrawal(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionWithdrawal();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string address;
    std::string amount;
};

class TransactionMir{
public:

    // \brief Constructor.
    TransactionMir();
    TransactionMir(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionMir();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string pot;
    int cert_index;
    std::string address;
    std::string amount;
};

class PoolUpdateMetadata{
public:

    // \brief Constructor.
    PoolUpdateMetadata();
    PoolUpdateMetadata(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolUpdateMetadata();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::pair<std::string, bool> url;
    std::pair<std::string, bool> hash;
    std::pair<std::string, bool> ticker;
    std::pair<std::string, bool> name;
    std::pair<std::string, bool> description;
    std::pair<std::string, bool> homepage;
};

class TransactionPoolUpdate{
public:

    // \brief Constructor.
    TransactionPoolUpdate();
    TransactionPoolUpdate(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionPoolUpdate();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int cert_index;
    std::string pool_id;
    std::string vrf_key;
    std::string pledge;
    double margin_cost;
    std::string fixed_cost;
    std::string reward_account;
    std::vector<std::string> owners;
    std::pair<PoolUpdateMetadata, bool> metadata;
    std::vector<PoolRelay> relays;
    int active_epoch;
};


class TransactionPoolRetiring{
public:

    // \brief Constructor.
    TransactionPoolRetiring();
    TransactionPoolRetiring(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionPoolRetiring();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int cert_index;
    std::string pool_id;
    int retiring_epoch;
};

class TransactionMetaJSON{
public:

    // \brief Constructor.
    TransactionMetaJSON();
    TransactionMetaJSON(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionMetaJSON();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string label;
    std::pair<bourne::json, bool> json_metadata;
};

class TransactionMetaCBOR{
public:

    // \brief Constructor.
    TransactionMetaCBOR();
    TransactionMetaCBOR(std::string jsonString);

    // \brief Destructor.
    virtual ~TransactionMetaCBOR();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string label;
    std::pair<std::string, bool> metadata;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Transaction_H_ */
