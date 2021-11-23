/*
 * Epoch.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Epoch_H_
#define BLOCKFROST_CPP_CLIENT_Epoch_H_

#include <ctime>
#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Epoch{
public:

    // \brief Constructor.
    Epoch();
    Epoch(std::string jsonString);

    // \brief Destructor.
    virtual ~Epoch();


    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();


    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int epoch;
    time_t start_time;
    time_t end_time;
    time_t first_block_time;
    time_t last_block_time;
    int block_count;
    int tx_count;
    std::string output;
    std::string fees;
    std::pair<std::string, bool> active_stake;
};

class ProtocolParams{
public:

    // \brief Constructor.
    ProtocolParams();
    ProtocolParams(std::string jsonString);

    // \brief Destructor.
    virtual ~ProtocolParams();


    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();


    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int epoch;
    int min_fee_a;
    int min_fee_b;
    int max_block_size;
    int max_tx_size;
    int max_block_header_size;
    std::string key_deposit;
    std::string pool_deposit;
    int e_max;
    int n_opt;
    double a0;
    double rho;
    double tau;
    double decentralisation_param;
    std::pair<bourne::json, bool> extra_entropy;

    int protocol_major_ver;
    int protocol_minor_ver;
    std::string min_utxo;
    std::string min_pool_cost;
    std::string nonce;

    double price_mem;
    double price_step;
    std::string max_tx_ex_mem;
    std::string max_tx_ex_steps;
    std::string max_block_ex_mem;
    std::string max_block_ex_steps;
    std::string max_val_size;
    int collateral_percent;
    int max_collateral_inputs;
    std::string coins_per_utxo_word;
};

// StakeDistribution

class StakeDistribution{
public:

    // \brief Constructor.
    StakeDistribution();
    StakeDistribution(std::string jsonString);

    // \brief Destructor.
    virtual ~StakeDistribution();


    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();


    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string stake_address;
    std::string pool_id;
    std::string amount;
};

// PoolStakeDistribution

class PoolStakeDistribution{
public:

    // \brief Constructor.
    PoolStakeDistribution();
    PoolStakeDistribution(std::string jsonString);

    // \brief Destructor.
    virtual ~PoolStakeDistribution();


    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();


    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string stake_address;
    std::string amount;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Epoch_H_ */
