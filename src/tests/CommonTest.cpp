
#include "types/Common.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_URLVersion() {
  std::string raw =
    "{"
    "  \"url\": \"https://blockfrost.io/\","
    "  \"version\": \"0.1.0\""
    "}";

  URLVersion a1(raw);
  URLVersion a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("https://blockfrost.io/", a.url.c_str());
  TEST_ASSERT_EQUAL_STRING("0.1.0", a.version.c_str());
}

void test_Health() {
  std::string raw = "{ \"is_healthy\": true }";

  Health a1(raw);
  Health a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(true, a.is_healthy);
}

void test_ServerTime() {
  std::string raw = "{ \"server_time\": 1603400958947 }";

  ServerTime a1(raw);
  // won't roundtrip
  //ServerTime a(a.toJson().dump());

  TEST_ASSERT_EQUAL_INT(1603400958947, a1.server_time);
}

void test_Metric() {
  std::string raw =
    "{"
    "  \"time\": 1612543884,"
    "  \"calls\": 42"
    "}";

  Metric a1(raw);
  Metric a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(1612543884, a.time);
  TEST_ASSERT_EQUAL_INT(42, a.calls);
}

void test_MetricEndpoint() {
  std::string raw =
    "{"
    "  \"time\": 1612543884,"
    "  \"calls\": 42,"
    "  \"endpoint\": \"block\""
    "}";

  MetricEndpoint a1(raw);
  MetricEndpoint a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(1612543884, a.time);
  TEST_ASSERT_EQUAL_INT(42, a.calls);
}
