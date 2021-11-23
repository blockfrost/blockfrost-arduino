
#include "types/NutLink.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_NutLinkAddress() {
  std::string raw =
      "{"
    "  \"address\": \"addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz\","
    "  \"metadata_url\": \"https://nut.link/metadata.json\","
    "  \"metadata_hash\": \"6bf124f217d0e5a0a8adb1dbd8540e1334280d49ab861127868339f43b3948af\","
    "  \"metadata\": {}"
    "}";

  NutLinkAddress a1(raw);
  NutLinkAddress a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("https://nut.link/metadata.json", a.metadata_url.c_str());
  TEST_ASSERT_EQUAL_STRING("6bf124f217d0e5a0a8adb1dbd8540e1334280d49ab861127868339f43b3948af", a.metadata_hash.c_str());
}

void test_NutLinkAddressTicker() {
  std::string raw =
    "{"
    "  \"name\": \"ADAUSD\","
    "  \"count\": 1980038,"
    "  \"latest_block\": 2657092"
    "}";

  NutLinkAddressTicker a1(raw);
  NutLinkAddressTicker a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("ADAUSD", a.name.c_str());
  TEST_ASSERT_EQUAL_INT(1980038, a.count);
  TEST_ASSERT_EQUAL_INT(2657092, a.latest_block);
}

void test_NutLinkTicker() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b\","
    "  \"block_height\": 2657092,"
    "  \"tx_index\": 8,"
    "  \"payload\": ["
    "    {"
    "      \"source\": \"coinGecko\","
    "      \"value\": \"1.29\""
    "    },"
    "    {"
    "      \"source\": \"cryptoCompare\","
    "      \"value\": \"1.283\""
    "    }"
    "  ]"
    "}";

  NutLinkTicker a1(raw);
  NutLinkTicker a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(2657092, a.block_height);
  TEST_ASSERT_EQUAL_INT(8, a.tx_index);

  TEST_ASSERT_EQUAL_INT(true, a.payload.is_array());
}

void test_NutLinkTickerAddress() {
  std::string raw =
    "{"
    "  \"address\": \"addr_test1qpmtp5t0t5y6cqkaz7rfsyrx7mld77kpvksgkwm0p7en7qum7a589n30e80tclzrrnj8qr4qvzj6al0vpgtnmrkkksnqd8upj0\","
    "  \"tx_hash\": \"e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b\","
    "  \"block_height\": 2657092,"
    "  \"tx_index\": 8,"
    "  \"payload\": ["
    "    {"
    "      \"source\": \"coinGecko\","
    "      \"value\": \"1.29\""
    "    },"
    "    {"
    "      \"source\": \"cryptoCompare\","
    "      \"value\": \"1.283\""
    "    }"
    "  ]"
    "}";

  NutLinkTickerAddress a1(raw);
  NutLinkTickerAddress a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("addr_test1qpmtp5t0t5y6cqkaz7rfsyrx7mld77kpvksgkwm0p7en7qum7a589n30e80tclzrrnj8qr4qvzj6al0vpgtnmrkkksnqd8upj0", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(2657092, a.block_height);
  TEST_ASSERT_EQUAL_INT(8, a.tx_index);

  TEST_ASSERT_EQUAL_INT(true, a.payload.is_array());
}
