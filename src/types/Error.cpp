#include "Error.h"

using namespace Blockfrost;

// Error

Error::Error()
{
  error = std::string();
  message = std::string();
}

Error::Error(std::string jsonString)
{
  this->fromJson(jsonString);
}

Error::~Error()
{
}

void
Error::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(error, "std::string");
    fromJSON(message, "std::string");
}

bourne::json
Error::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(error);
    toJSON(message);

    return object;
}
