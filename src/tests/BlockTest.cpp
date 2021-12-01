
#include "types/Block.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Block() {
  std::string raw =
    "{\n"
    " \"time\": 1641338934,"
    " \"height\": 15243593,"
    " \"hash\": \"4ea1ba291e8eef538635a53e59fddba7810d1679631cc3aed7c8e6c4091a516a\","
    " \"slot\": 412162133,"
    " \"epoch\": 425,"
    " \"epoch_slot\": 12,"
    " \"slot_leader\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2qnikdy\","
    " \"size\": 3,"
    " \"tx_count\": 1,"
    " \"output\": \"128314491794\","
    " \"fees\": \"592661\","
    " \"block_vrf\": \"vrf_vk1wf2k6lhujezqcfe00l6zetxpnmh9n6mwhpmhm0dvfh3fxgmdnrfqkms8ty\","
    " \"previous_block\": \"43ebccb3ac72c7cebd0d9b755a4b08412c9f5dcb81b8a0ad1e3c197d29d47b05\","
    " \"next_block\": null,"
    " \"confirmations\": 4698"
    "}";

  Block b1(raw);
  Block b(b1.toJson().dump());
  TEST_ASSERT_EQUAL_INT(1641338934, b.time);
  TEST_ASSERT_EQUAL_INT(15243593, b.height.first);
  TEST_ASSERT_EQUAL_STRING("4ea1ba291e8eef538635a53e59fddba7810d1679631cc3aed7c8e6c4091a516a", b.hash.c_str());
  TEST_ASSERT_EQUAL_INT(412162133, b.slot.first);
  TEST_ASSERT_EQUAL_INT(425, b.epoch.first);
  TEST_ASSERT_EQUAL_INT(12, b.epoch_slot.first);
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2qnikdy", b.slot_leader.c_str());
  TEST_ASSERT_EQUAL_INT(3, b.size);
  TEST_ASSERT_EQUAL_INT(1, b.tx_count);
  TEST_ASSERT_EQUAL_STRING("128314491794", b.output.first.c_str());
  TEST_ASSERT_EQUAL_STRING("592661", b.fees.first.c_str());
  TEST_ASSERT_EQUAL_STRING("vrf_vk1wf2k6lhujezqcfe00l6zetxpnmh9n6mwhpmhm0dvfh3fxgmdnrfqkms8ty", b.block_vrf.first.c_str());
  TEST_ASSERT_EQUAL_STRING("43ebccb3ac72c7cebd0d9b755a4b08412c9f5dcb81b8a0ad1e3c197d29d47b05", b.previous_block.first.c_str());
  TEST_ASSERT_EQUAL_INT(true, b.previous_block.second);
  TEST_ASSERT_EQUAL_INT(false, b.next_block.second);
  TEST_ASSERT_EQUAL_INT(4698, b.confirmations);
}
