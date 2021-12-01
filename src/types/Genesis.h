/*
 * Genesis.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Genesis_H_
#define BLOCKFROST_CPP_CLIENT_Genesis_H_

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

class Genesis{
public:

    // \brief Constructor.
    Genesis();
    Genesis(std::string jsonString);

    // \brief Destructor.
    virtual ~Genesis();


    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();


    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    double active_slots_coefficient;
    int update_quorum;
    std::string max_lovelace_supply;
    int network_magic;
    int epoch_length;
    time_t system_start;
    int slots_per_kes_period;
    int slot_length;
    int max_kes_evolutions;
    int security_param;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Genesis_H_ */
