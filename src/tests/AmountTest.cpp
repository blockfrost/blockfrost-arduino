#include "types/Amount.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Amount() {

  std::string raw =
    "{"
    "\"quantity\" : \"42000000\","
    "\"unit\" : \"lovelace\""
    "}";

  Amount a1(raw);
  Amount a(a1.toJson().dump());
  TEST_ASSERT_EQUAL_STRING("42000000", a.quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("lovelace", a.unit.c_str());
}
