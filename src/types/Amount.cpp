#include "Amount.h"

using namespace Blockfrost;

// Amount

Amount::Amount()
{
  unit = std::string();
  quantity = std::string();
}

Amount::Amount(std::string jsonString)
{
  this->fromJson(jsonString);
}

Amount::~Amount()
{
}

void
Amount::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(unit, "std::string");
    fromJSON(quantity, "std::string");
}

bourne::json
Amount::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(unit);
    toJSON(quantity);

    return object;
}
