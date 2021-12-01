
#include "types/IPFS.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_IPFSAdd() {
  std::string raw =
    "{"
    "  \"name\": \"README.md\","
    "  \"ipfs_hash\": \"QmZbHqiCxKEVX7QfijzJTkZiSi3WEVTcvANgNAWzDYgZDr\","
    "  \"size\": \"125297\""
    "}";

  IPFSAdd a1(raw);
  IPFSAdd a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("README.md", a.name.c_str());
  TEST_ASSERT_EQUAL_STRING("QmZbHqiCxKEVX7QfijzJTkZiSi3WEVTcvANgNAWzDYgZDr", a.ipfs_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("125297", a.size.c_str());
}

void test_IPFSPinChange() {
  std::string raw =
    "{"
    "  \"ipfs_hash\": \"QmPojRfAXYAXV92Dof7gtSgaVuxEk64xx9CKvprqu9VwA8\","
    "  \"state\": \"queued\""
    "}";

  IPFSPinChange a1(raw);
  IPFSPinChange a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("QmPojRfAXYAXV92Dof7gtSgaVuxEk64xx9CKvprqu9VwA8", a.ipfs_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("queued", a.state.c_str());
}

void test_IPFSPin() {
  std::string raw =
    "{"
    "  \"time_created\": 1615551024,"
    "  \"time_pinned\": 1615671024,"
    "  \"ipfs_hash\": \"QmdVMnULrY95mth2XkwjxDtMHvzuzmvUPTotKE1tgqKbCx\","
    "  \"size\": \"1615551024\","
    "  \"state\": \"pinned\""
    "}";

  IPFSPin a1(raw);
  IPFSPin a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(1615551024, a.time_created);
  TEST_ASSERT_EQUAL_INT(1615671024, a.time_pinned);
  TEST_ASSERT_EQUAL_STRING("QmdVMnULrY95mth2XkwjxDtMHvzuzmvUPTotKE1tgqKbCx", a.ipfs_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("1615551024", a.size.c_str());
  TEST_ASSERT_EQUAL_STRING("pinned", a.state.c_str());
}


