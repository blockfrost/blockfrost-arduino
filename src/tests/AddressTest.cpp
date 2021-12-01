
#include "types/Address.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Address() {
  std::string raw =
    "{"
    " \"address\": \"addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz\","
    " \"amount\": ["
    "   {"
    "     \"unit\": \"lovelace\","
    "     \"quantity\": \"42000000\""
    "   },"
    "   {"
    "     \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "     \"quantity\": \"12\""
    "   }"
    " ],"
    " \"stake_address\": \"stake1ux3g2c9dx2nhhehyrezyxpkstartcqmu9hk63qgfkccw5rqttygt7\","
    " \"type\": \"shelley\","
    " \"script\": false"
    "}";

  Address a1(raw);
  Address a(a1.toJson().dump());
  TEST_ASSERT_EQUAL_STRING("addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("stake1ux3g2c9dx2nhhehyrezyxpkstartcqmu9hk63qgfkccw5rqttygt7", a.stake_address.first.c_str());
  TEST_ASSERT_EQUAL_STRING("shelley", a.type.c_str());
  TEST_ASSERT_EQUAL_INT(false, a.script);

  TEST_ASSERT_EQUAL_STRING("lovelace", a.amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", a.amount.at(0).quantity.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.amount.at(0).is_lovelaces());

  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.amount.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", a.amount.at(1).quantity.c_str());
}

void test_AddressDetails() {
  std::string raw =
    "{"
    "  \"address\": \"addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz\","
    "  \"received_sum\": ["
    "    {"
    "      \"unit\": \"lovelace\","
    "      \"quantity\": \"42000000\""
    "    },"
    "    {"
    "      \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "      \"quantity\": \"12\""
    "    }"
    "  ],"
    "  \"sent_sum\": ["
    "    {"
    "      \"unit\": \"lovelace\","
    "      \"quantity\": \"42000000\""
    "    },"
    "    {"
    "      \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "      \"quantity\": \"12\""
    "    }"
    "  ],"
    "  \"tx_count\": 12"
    "}";

  AddressDetails a1(raw);
  AddressDetails a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz", a.address.c_str());
  TEST_ASSERT_EQUAL_INT(12, a.tx_count);

  TEST_ASSERT_EQUAL_STRING("lovelace", a.received_sum.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", a.received_sum.at(0).quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.received_sum.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", a.received_sum.at(1).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("lovelace", a.sent_sum.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", a.sent_sum.at(0).quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.sent_sum.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", a.sent_sum.at(1).quantity.c_str());
}

void test_AddressUtxo() {
  std::string raw =
    "["
    "    {"
    "        \"tx_hash\": \"39a7a284c2a0948189dc45dec670211cd4d72f7b66c5726c08d9b3df11e44d58\","
    "        \"output_index\": 0,"
    "        \"amount\":"
    "        ["
    "            {"
    "                \"unit\": \"lovelace\","
    "                \"quantity\": \"42000000\""
    "            }"
    "        ],"
    "        \"block\": \"7eb8e27d18686c7db9a18f8bbcfe34e3fed6e047afaa2d969904d15e934847e6\","
    "        \"data_hash\": \"9e478573ab81ea7a8e31891ce0648b81229f408d596a3483e6f4f9b92d3cf710\""
    "    },"
    "    {"
    "        \"tx_hash\": \"4c4e67bafa15e742c13c592b65c8f74c769cd7d9af04c848099672d1ba391b49\","
    "        \"output_index\": 0,"
    "        \"amount\":"
    "        ["
    "            {"
    "                \"unit\": \"lovelace\","
    "                \"quantity\": \"729235000\""
    "            }"
    "        ],"
    "        \"block\": \"953f1b80eb7c11a7ffcd67cbd4fde66e824a451aca5a4065725e5174b81685b7\","
    "        \"data_hash\": null"
    "    },"
    "    {"
    "        \"tx_hash\": \"768c63e27a1c816a83dc7b07e78af673b2400de8849ea7e7b734ae1333d100d2\","
    "        \"output_index\": 1,"
    "        \"amount\":"
    "        ["
    "            {"
    "                \"unit\": \"lovelace\","
    "                \"quantity\": \"42000000\""
    "            },"
    "            {"
    "                \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "                \"quantity\": \"12\""
    "            }"
    "        ],"
    "        \"block\": \"5c571f83fe6c784d3fbc223792627ccf0eea96773100f9aedecf8b1eda4544d7\","
    "        \"data_hash\": null"
    "    }"
    "]";

  bourne::json aulist = bourne::json::parse(raw);
  std::vector<AddressUtxo> utxos;

  for(auto& var: aulist.array_range()) {
    AddressUtxo a1(var.dump());
    AddressUtxo a(a1.toJson().dump());
    utxos.push_back(a);
  }

  // 0
  TEST_ASSERT_EQUAL_STRING("39a7a284c2a0948189dc45dec670211cd4d72f7b66c5726c08d9b3df11e44d58", utxos.at(0).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, utxos.at(0).output_index);
  TEST_ASSERT_EQUAL_STRING("lovelace", utxos.at(0).amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", utxos.at(0).amount.at(0).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("7eb8e27d18686c7db9a18f8bbcfe34e3fed6e047afaa2d969904d15e934847e6", utxos.at(0).block.c_str());
  TEST_ASSERT_EQUAL_STRING("9e478573ab81ea7a8e31891ce0648b81229f408d596a3483e6f4f9b92d3cf710", utxos.at(0).data_hash.first.c_str());
  TEST_ASSERT_EQUAL_INT(true, utxos.at(0).data_hash.second);

  // 1
  TEST_ASSERT_EQUAL_STRING("4c4e67bafa15e742c13c592b65c8f74c769cd7d9af04c848099672d1ba391b49", utxos.at(1).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, utxos.at(1).output_index);
  TEST_ASSERT_EQUAL_STRING("lovelace", utxos.at(1).amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("729235000", utxos.at(1).amount.at(0).quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("953f1b80eb7c11a7ffcd67cbd4fde66e824a451aca5a4065725e5174b81685b7", utxos.at(1).block.c_str());
  TEST_ASSERT_EQUAL_INT(false, utxos.at(1).data_hash.second);

  // 2
  TEST_ASSERT_EQUAL_STRING("768c63e27a1c816a83dc7b07e78af673b2400de8849ea7e7b734ae1333d100d2", utxos.at(2).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(1, utxos.at(2).output_index);
  TEST_ASSERT_EQUAL_STRING("lovelace", utxos.at(2).amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", utxos.at(2).amount.at(0).quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", utxos.at(2).amount.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", utxos.at(2).amount.at(1).quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("5c571f83fe6c784d3fbc223792627ccf0eea96773100f9aedecf8b1eda4544d7", utxos.at(2).block.c_str());
  TEST_ASSERT_EQUAL_INT(false, utxos.at(2).data_hash.second);
}

void test_AddressTransactions() {
  std::string raw =
    "["
    "    {"
    "        \"tx_hash\": \"8788591983aa73981fc92d6cddbbe643959f5a784e84b8bee0db15823f575a5b\","
    "        \"tx_index\": 6,"
    "        \"block_height\": 69"
    "    },"
    "    {"
    "        \"tx_hash\": \"52e748c4dec58b687b90b0b40d383b9fe1f24c1a833b7395cdf07dd67859f46f\","
    "        \"tx_index\": 9,"
    "        \"block_height\": 4547"
    "    },"
    "    {"
    "        \"tx_hash\": \"e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b\","
    "        \"tx_index\": 0,"
    "        \"block_height\": 564654"
    "    }"
    "]";

  bourne::json txlist = bourne::json::parse(raw);
  std::vector<AddressTransaction> txs;

  for(auto& var: txlist.array_range()) {
    AddressTransaction a1(var.dump());
    AddressTransaction a(a1.toJson().dump());
    txs.push_back(a);
  }

  // 0
  TEST_ASSERT_EQUAL_STRING("8788591983aa73981fc92d6cddbbe643959f5a784e84b8bee0db15823f575a5b", txs.at(0).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(6, txs.at(0).tx_index);
  TEST_ASSERT_EQUAL_INT(69, txs.at(0).block_height);

  // 1
  TEST_ASSERT_EQUAL_STRING("52e748c4dec58b687b90b0b40d383b9fe1f24c1a833b7395cdf07dd67859f46f", txs.at(1).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(9, txs.at(1).tx_index);
  TEST_ASSERT_EQUAL_INT(4547, txs.at(1).block_height);

  // 2
  TEST_ASSERT_EQUAL_STRING("e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b", txs.at(2).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, txs.at(2).tx_index);
  TEST_ASSERT_EQUAL_INT(564654, txs.at(2).block_height);
}

