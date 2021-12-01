/*
 * Error.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Error_H_
#define BLOCKFROST_CPP_CLIENT_Error_H_

#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class Error{
  public:
    // \brief Constructor.
    Error();
    Error(std::string jsonString);

    // \brief Destructor.
    virtual ~Error();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string error;
    std::string message;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Error_H_ */
