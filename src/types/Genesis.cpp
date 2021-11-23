#include "Genesis.h"

using namespace Blockfrost;

Genesis::Genesis()
{
  active_slots_coefficient = double(0);
  update_quorum = int(0);
  max_lovelace_supply = std::string();
  network_magic = int(0);
  epoch_length = int(0);
  system_start = time_t(0);
  slots_per_kes_period = int(0);
  slot_length = int(0);
  max_kes_evolutions = int(0);
  security_param = int(0);
}

Genesis::Genesis(std::string jsonString)
{
  this->fromJson(jsonString);
}

Genesis::~Genesis()
{
}

void
Genesis::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(active_slots_coefficient, "double");
    fromJSON(update_quorum, "int");
    fromJSON(max_lovelace_supply, "std::string");
    fromJSON(network_magic, "int");
    fromJSON(epoch_length, "int");
    fromJSON(system_start, "time_t");
    fromJSON(slots_per_kes_period, "int");
    fromJSON(slot_length, "int");
    fromJSON(max_kes_evolutions, "int");
    fromJSON(security_param, "int");
}

bourne::json
Genesis::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(active_slots_coefficient);
    toJSON(update_quorum);
    toJSON(max_lovelace_supply);
    toJSON(network_magic);
    toJSON(epoch_length);
    toJSON(system_start);
    toJSON(slots_per_kes_period);
    toJSON(slot_length);
    toJSON(max_kes_evolutions);
    toJSON(security_param);

    return object;
}
