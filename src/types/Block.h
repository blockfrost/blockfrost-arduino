/*
 * Block.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Block_H_
#define BLOCKFROST_CPP_CLIENT_Block_H_

#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Block{
public:

    // \brief Constructor.
    Block();
    Block(std::string jsonString);

    // \brief Destructor.
    virtual ~Block();


    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();


    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int time;
    std::pair<int, bool> height;
    std::string hash;
    std::pair<int, bool> slot;
    std::pair<int, bool> epoch;
    std::pair<int, bool> epoch_slot;
    std::string slot_leader;
    int size;
    int tx_count;
    std::pair<std::string, bool> output;
    std::pair<std::string, bool> fees;
    std::pair<std::string, bool> block_vrf;
    std::pair<std::string, bool> previous_block;
    std::pair<std::string, bool> next_block;
    int confirmations;
};
}

#endif /* BLOCKFROST_CPP_CLIENT_Block_H_ */
