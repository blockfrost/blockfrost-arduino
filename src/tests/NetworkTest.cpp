
#include "types/Network.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Network() {
  std::string raw =
    "{"
    "  \"supply\": {"
    "    \"max\": \"45000000000000000\","
    "    \"total\": \"32890715183299160\","
    "    \"circulating\": \"32412601976210393\","
    "    \"locked\": \"125006953355\","
    "    \"treasury\": \"98635632000000\","
    "    \"reserves\": \"46635632000000\""
    "  },"
    "  \"stake\": {"
    "    \"live\": \"23204950463991654\","
    "    \"active\": \"22210233523456321\""
    "  }"
    "}";

  Network a1(raw);
  Network a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("45000000000000000", a.supply.max.c_str());
  TEST_ASSERT_EQUAL_STRING("32890715183299160", a.supply.total.c_str());
  TEST_ASSERT_EQUAL_STRING("32412601976210393", a.supply.circulating.c_str());
  TEST_ASSERT_EQUAL_STRING("125006953355", a.supply.locked.c_str());
  TEST_ASSERT_EQUAL_STRING("98635632000000", a.supply.treasury.c_str());
  TEST_ASSERT_EQUAL_STRING("46635632000000", a.supply.reserves.c_str());

  TEST_ASSERT_EQUAL_STRING("23204950463991654", a.stake.live.c_str());
  TEST_ASSERT_EQUAL_STRING("22210233523456321", a.stake.active.c_str());
}
