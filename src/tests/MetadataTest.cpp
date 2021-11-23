
#include "types/Metadata.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_TxMeta() {
  std::string raw =
    "{"
    "  \"label\": \"1967\","
    "  \"cip10\": \"nut.link metadata oracles registry\","
    "  \"count\": \"3\""
    "}";

  TxMeta a1(raw);
  TxMeta a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("1967", a.label.c_str());
  TEST_ASSERT_EQUAL_STRING("nut.link metadata oracles registry", a.cip10.first.c_str());
  TEST_ASSERT_EQUAL_STRING("3", a.count.c_str());
}

void test_TxMetaJSON() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"e865f2cc01ca7381cf98dcdc4de07a5e8674b8ea16e6a18e3ed60c186fde2b9c\","
    "  \"json_metadata\": {"
    "    \"ADAUSD\": ["
    "      {"
    "        \"value\": \"0.15409850555139935\","
    "        \"source\": \"ergoOracles\""
    "      }"
    "    ]"
    "  }"
    "}";

  TxMetaJSON a1(raw);
  TxMetaJSON a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("e865f2cc01ca7381cf98dcdc4de07a5e8674b8ea16e6a18e3ed60c186fde2b9c", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.json_metadata.second);
  TEST_ASSERT_EQUAL_INT(true, a.json_metadata.first.has_key("ADAUSD"));
}

void test_TxMetaCBOR() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"4237501da3cfdd53ade91e8911e764bd0699d88fd43b12f44a1f459b89bc91be\","
    "  \"cbor_metadata\": \"\\xa100a16b436f6d62696e6174696f6e8601010101010c\","
    "  \"metadata\": \"a100a16b436f6d62696e6174696f6e8601010101010c\""
    "}";

  TxMetaCBOR a1(raw);
  TxMetaCBOR a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("4237501da3cfdd53ade91e8911e764bd0699d88fd43b12f44a1f459b89bc91be", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("a100a16b436f6d62696e6174696f6e8601010101010c", a.metadata.first.c_str());
}
