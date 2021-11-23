
#include "types/Genesis.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Genesis() {
  std::string raw =
    "{"
    "    \"active_slots_coefficient\": 0.05,"
    "    \"update_quorum\": 5,"
    "    \"max_lovelace_supply\": \"45000000000000000\","
    "    \"network_magic\": 764824073,"
    "    \"epoch_length\": 432000,"
    "    \"system_start\": 1506203091,"
    "    \"slots_per_kes_period\": 129600,"
    "    \"slot_length\": 1,"
    "    \"max_kes_evolutions\": 62,"
    "    \"security_param\": 2160"
    "}";

  Genesis a1(raw);
  Genesis a(a1.toJson().dump());
  TEST_ASSERT_EQUAL_DOUBLE(0.05, a.active_slots_coefficient);
  TEST_ASSERT_EQUAL_INT(5, a.update_quorum);
  TEST_ASSERT_EQUAL_STRING("45000000000000000", a.max_lovelace_supply.c_str());
  TEST_ASSERT_EQUAL_INT(764824073, a.network_magic);
  TEST_ASSERT_EQUAL_INT(432000, a.epoch_length);
  TEST_ASSERT_EQUAL_INT(1506203091, a.system_start);
  TEST_ASSERT_EQUAL_INT(129600, a.slots_per_kes_period);
  TEST_ASSERT_EQUAL_INT(1, a.slot_length);
  TEST_ASSERT_EQUAL_INT(62, a.max_kes_evolutions);
  TEST_ASSERT_EQUAL_INT(2160, a.security_param);
}

