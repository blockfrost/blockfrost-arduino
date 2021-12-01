/*
 * Amount.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Amount_H_
#define BLOCKFROST_CPP_CLIENT_Amount_H_

#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Amount{
  public:
    // \brief Constructor.
    Amount();
    Amount(std::string jsonString);

    // \brief Destructor.
    virtual ~Amount();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    bool is_lovelaces() { return unit == "lovelace"; };

    std::string unit;
    std::string quantity;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Amount_H_ */
