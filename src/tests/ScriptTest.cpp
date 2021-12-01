
#include "types/Script.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_ScriptList() {
  std::string raw =
    "["
    "  {"
    "    \"script_hash\": \"67f33146617a5e61936081db3b2117cbf59bd2123748f58ac9678656\""
    "  },"
    "  {"
    "    \"script_hash\": \"e1457a0c47dfb7a2f6b8fbb059bdceab163c05d34f195b87b9f2b30e\""
    "  },"
    "  {"
    "    \"script_hash\": \"a6e63c0ff05c96943d1cc30bf53112ffff0f34b45986021ca058ec54\""
    "  }"
    "]";

  bourne::json slist = bourne::json::parse(raw);
  std::vector<Script> scripts;
  for(auto& var: slist.array_range()) {
    Script a1(var.dump());
    Script a(a1.toJson().dump());
    scripts.push_back(a);
  }

  TEST_ASSERT_EQUAL_STRING("67f33146617a5e61936081db3b2117cbf59bd2123748f58ac9678656", scripts.at(0).script_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("e1457a0c47dfb7a2f6b8fbb059bdceab163c05d34f195b87b9f2b30e", scripts.at(1).script_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("a6e63c0ff05c96943d1cc30bf53112ffff0f34b45986021ca058ec54", scripts.at(2).script_hash.c_str());
}

void test_ScriptInfo() {
  std::string raw =
    "{"
    "  \"script_hash\": \"67f33146617a5e61936081db3b2117cbf59bd2123748f58ac9678656\","
    "  \"type\": \"plutus\","
    "  \"serialised_size\": 3119"
    "}";

  ScriptInfo a1(raw);
  ScriptInfo a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("67f33146617a5e61936081db3b2117cbf59bd2123748f58ac9678656", a.script_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("plutus", a.type.c_str());
  TEST_ASSERT_EQUAL_INT(3119, a.serialised_size.first);
}

void test_ScriptRedeemer() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"1a0570af966fb355a7160e4f82d5a80b8681b7955f5d44bec0dce628516157f0\","
    "  \"tx_index\": 0,"
    "  \"purpose\": \"spend\","
    "  \"datum_hash\": \"923918e403bf43c34b4ef6b48eb2ee04babed17320d8d1b9ff9ad086e86f44ec\","
    "  \"unit_mem\": \"1700\","
    "  \"unit_steps\": \"476468\","
    "  \"fee\": \"172033\""
    "}";

  ScriptRedeemer a1(raw);
  ScriptRedeemer a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("1a0570af966fb355a7160e4f82d5a80b8681b7955f5d44bec0dce628516157f0", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, a.tx_index);
  TEST_ASSERT_EQUAL_STRING("spend", a.purpose.c_str());
  TEST_ASSERT_EQUAL_STRING("923918e403bf43c34b4ef6b48eb2ee04babed17320d8d1b9ff9ad086e86f44ec", a.datum_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("1700", a.unit_mem.c_str());
  TEST_ASSERT_EQUAL_STRING("476468", a.unit_steps.c_str());
  TEST_ASSERT_EQUAL_STRING("172033", a.fee.c_str());
}

void test_ScriptDatum() {
  std::string raw =
    "{"
    "  \"json_value\": {"
    "    \"int\": 42"
    "  }"
    "}";

  ScriptDatum a1(raw);
  ScriptDatum a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(true, a.json_value.first.has_key("int"));
}

void test_ScriptJSON() {
  std::string raw =
    "{"
    "  \"json\": {"
    "    \"type\": \"sig\","
    "    \"keyHash\": \"8ed9e675aaf99868736c372d5eac9f5b3deae4568f0cde6a7d9e1422\""
    "  }"
    "}";

  ScriptJSON a1(raw);
  ScriptJSON a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(true, a.json.first.has_key("keyHash"));
}

void test_ScriptCBOR() {
  std::string raw =
    "{"
    "  \"cbor\": \"4e4d01000033222220051200120011\","
    "}";

  ScriptCBOR a1(raw);
  ScriptCBOR a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("4e4d01000033222220051200120011", a.cbor.first.c_str());
}
