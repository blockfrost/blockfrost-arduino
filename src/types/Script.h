/*
 * Script.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Script_H_
#define BLOCKFROST_CPP_CLIENT_Script_H_

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

class Script{
public:

    // \brief Constructor.
    Script();
    Script(std::string jsonString);

    // \brief Destructor.
    virtual ~Script();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string script_hash;
};

class ScriptInfo{
public:

    // \brief Constructor.
    ScriptInfo();
    ScriptInfo(std::string jsonString);

    // \brief Destructor.
    virtual ~ScriptInfo();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string script_hash;
    std::string type;
    std::pair<int, bool> serialised_size;
};

class ScriptRedeemer{
public:

    // \brief Constructor.
    ScriptRedeemer();
    ScriptRedeemer(std::string jsonString);

    // \brief Destructor.
    virtual ~ScriptRedeemer();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string tx_hash;
    int tx_index;
    std::string purpose;
    std::string datum_hash;
    std::string unit_mem;
    std::string unit_steps;
    std::string fee;
};

class ScriptDatum{
public:

    // \brief Constructor.
    ScriptDatum();
    ScriptDatum(std::string jsonString);

    // \brief Destructor.
    virtual ~ScriptDatum();

    // \brief Retrieve a bourne Datum representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::pair<bourne::json, bool> json_value;
};

class ScriptCBOR{
public:

    // \brief Constructor.
    ScriptCBOR();
    ScriptCBOR(std::string jsonString);

    // \brief Destructor.
    virtual ~ScriptCBOR();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::pair<std::string, bool> cbor;
};

class ScriptJSON{
public:

    // \brief Constructor.
    ScriptJSON();
    ScriptJSON(std::string jsonString);

    // \brief Destructor.
    virtual ~ScriptJSON();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::pair<bourne::json, bool> json;
};

}

#endif /* BLOCKFROST_CPP_CLIENT_Script_H_ */
