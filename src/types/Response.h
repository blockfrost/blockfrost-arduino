#ifndef BLOCKFROST_CPP_CLIENT_RESPONSE_H_
#define BLOCKFROST_CPP_CLIENT_RESPONSE_H_
#include <string>
#include "Error.h"

namespace Blockfrost {

template <typename T = std::string>
    class Response {
    public:

    Response(T _obj, int _code, Error _err = Error()){
        obj = _obj;
        code = _code;
        err = _err;
    }

    int code;
    T obj;
    Error err;
    };
}

#endif /* BLOCKFROST_CPP_CLIENT_RESPONSE_H_ */
