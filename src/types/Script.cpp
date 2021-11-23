#include "Script.h"

using namespace Blockfrost;

Script::Script()
{
  script_hash = std::string();
}

Script::Script(std::string jsonString)
{
  this->fromJson(jsonString);
}

Script::~Script()
{
}

void
Script::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(script_hash, "std::string");
}

bourne::json
Script::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(script_hash);

    return object;
}

// ScriptInfo

ScriptInfo::ScriptInfo()
{
  script_hash = std::string();
  type = std::string();
  serialised_size = std::make_pair(int(0), false);
}

ScriptInfo::ScriptInfo(std::string jsonString)
{
  this->fromJson(jsonString);
}

ScriptInfo::~ScriptInfo()
{
}

void
ScriptInfo::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(script_hash, "std::string");
    fromJSON(type, "std::string");
    fromJSONMay(serialised_size, "int");
}

bourne::json
ScriptInfo::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(script_hash);
    toJSON(type);
    toJSONMay(serialised_size);

    return object;
}

// ScriptRedeemer

ScriptRedeemer::ScriptRedeemer()
{
  tx_hash = std::string();
  tx_index = int(0);
  purpose = std::string();
  datum_hash = std::string();
  unit_mem = std::string();
  unit_steps = std::string();
  fee = std::string();
}

ScriptRedeemer::ScriptRedeemer(std::string jsonString)
{
  this->fromJson(jsonString);
}

ScriptRedeemer::~ScriptRedeemer()
{
}

void
ScriptRedeemer::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(tx_hash, "std::string");
    fromJSON(tx_index, "int");
    fromJSON(purpose, "std::string");
    fromJSON(datum_hash, "std::string");
    fromJSON(unit_mem, "std::string");
    fromJSON(unit_steps, "std::string");
    fromJSON(fee, "std::string");
}

bourne::json
ScriptRedeemer::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(tx_hash);
    toJSON(tx_index);
    toJSON(purpose);
    toJSON(datum_hash);
    toJSON(unit_mem);
    toJSON(unit_steps);
    toJSON(fee);

    return object;
}

// ScriptDatum

ScriptDatum::ScriptDatum()
{
  json_value = std::make_pair(bourne::json(), false);
}

ScriptDatum::ScriptDatum(std::string jsonString)
{
  this->fromJson(jsonString);
}

ScriptDatum::~ScriptDatum()
{
}

void
ScriptDatum::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    if(!object["json_value"].is_null()) {
      json_value.first = object["json_value"];
      json_value.second = true;
    }
}

bourne::json
ScriptDatum::toJson()
{
    bourne::json object = bourne::json::object();

    if(json_value.second) {
      object["json_value"] = json_value.first;
    } else {
      object["json_value"] = nullptr;
    };

    return object;
}

// ScriptCBOR

ScriptCBOR::ScriptCBOR()
{
  cbor = std::make_pair(std::string(), false);
}

ScriptCBOR::ScriptCBOR(std::string jsonString)
{
  this->fromJson(jsonString);
}

ScriptCBOR::~ScriptCBOR()
{
}

void
ScriptCBOR::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSONMay(cbor, "std::string");
}

bourne::json
ScriptCBOR::toJson()
{
    bourne::json object = bourne::json::object();

    toJSONMay(cbor);

    return object;
}

// ScriptJSON

ScriptJSON::ScriptJSON()
{
  json = std::make_pair(bourne::json(), false);
}

ScriptJSON::ScriptJSON(std::string jsonString)
{
  this->fromJson(jsonString);
}

ScriptJSON::~ScriptJSON()
{
}

void
ScriptJSON::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    if(!object["json"].is_null()) {
      json.first = object["json"];
      json.second = true;
    }
}

bourne::json
ScriptJSON::toJson()
{
    bourne::json object = bourne::json::object();

    if(json.second) {
      object["json"] = json.first;
    } else {
      object["json"] = nullptr;
    };

    return object;
}
