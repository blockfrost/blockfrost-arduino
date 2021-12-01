
#include "types/Epoch.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Epoch() {
  std::string raw =
    "{"
    "    \"epoch\": 225,"
    "    \"start_time\": 1603403091,"
    "    \"end_time\": 1603835086,"
    "    \"first_block_time\": 1603403092,"
    "    \"last_block_time\": 1603835084,"
    "    \"block_count\": 21298,"
    "    \"tx_count\": 17856,"
    "    \"output\": \"7849943934049314\","
    "    \"fees\": \"4203312194\","
    "    \"active_stake\": \"784953934049314\""
    "}";

  Epoch a1(raw);
  Epoch a(a1.toJson().dump());
  TEST_ASSERT_EQUAL_INT(225, a.epoch);
  TEST_ASSERT_EQUAL_INT(1603403091, a.start_time);
  TEST_ASSERT_EQUAL_INT(1603835086, a.end_time);
  TEST_ASSERT_EQUAL_INT(1603403092, a.first_block_time);
  TEST_ASSERT_EQUAL_INT(1603835084, a.last_block_time);
  TEST_ASSERT_EQUAL_INT(21298, a.block_count);
  TEST_ASSERT_EQUAL_INT(17856, a.tx_count);
  TEST_ASSERT_EQUAL_STRING("7849943934049314", a.output.c_str());
  TEST_ASSERT_EQUAL_STRING("4203312194", a.fees.c_str());
  TEST_ASSERT_EQUAL_STRING("784953934049314", a.active_stake.first.c_str());
}

void test_ProtocolParams() {
  std::string raw =
    "{"
    "    \"epoch\": 225,"
    "    \"min_fee_a\": 44,"
    "    \"min_fee_b\": 155381,"
    "    \"max_block_size\": 65536,"
    "    \"max_tx_size\": 16384,"
    "    \"max_block_header_size\": 1100,"
    "    \"key_deposit\": \"2000000\","
    "    \"pool_deposit\": \"500000000\","
    "    \"e_max\": 18,"
    "    \"n_opt\": 150,"
    "    \"a0\": 0.3,"
    "    \"rho\": 0.003,"
    "    \"tau\": 0.2,"
    "    \"decentralisation_param\": 0.5,"
    "    \"extra_entropy\": null,"
    "    \"protocol_major_ver\": 2,"
    "    \"protocol_minor_ver\": 0,"
    "    \"min_utxo\": \"1000000\","
    "    \"min_pool_cost\": \"340000000\","
    "    \"nonce\": \"1a3be38bcbb7911969283716ad7aa550250226b76a61fc51cc9a9a35d9276d81\","
    "    \"price_mem\": 0.0577,"
    "    \"price_step\": 0.0000721,"
    "    \"max_tx_ex_mem\": \"10000000\","
    "    \"max_tx_ex_steps\": \"10000000000\","
    "    \"max_block_ex_mem\": \"50000000\","
    "    \"max_block_ex_steps\": \"40000000000\","
    "    \"max_val_size\": \"5000\","
    "    \"collateral_percent\": 150,"
    "    \"max_collateral_inputs\": 3,"
    "    \"coins_per_utxo_word\": \"34482\""
    "}";

  ProtocolParams a(raw);
  // this one won't roundtrip due to price_step float
  // being dumped via std::to_string
  // which truncates 0.0000721 to 0.000072
  // but parsing is fine
  //ProtocolParams a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(225, a.epoch);
  TEST_ASSERT_EQUAL_INT(44, a.min_fee_a);
  TEST_ASSERT_EQUAL_INT(155381, a.min_fee_b);
  TEST_ASSERT_EQUAL_INT(65536, a.max_block_size);
  TEST_ASSERT_EQUAL_INT(16384, a.max_tx_size);
  TEST_ASSERT_EQUAL_INT(1100, a.max_block_header_size);
  TEST_ASSERT_EQUAL_STRING("2000000", a.key_deposit.c_str());
  TEST_ASSERT_EQUAL_STRING("500000000", a.pool_deposit.c_str());
  TEST_ASSERT_EQUAL_INT(18, a.e_max);
  TEST_ASSERT_EQUAL_INT(150, a.n_opt);
  TEST_ASSERT_EQUAL_DOUBLE(0.3, a.a0);
  TEST_ASSERT_EQUAL_DOUBLE(0.003, a.rho);
  TEST_ASSERT_EQUAL_DOUBLE(0.2, a.tau);
  TEST_ASSERT_EQUAL_DOUBLE(0.5, a.decentralisation_param);
  TEST_ASSERT_EQUAL_INT(false, a.extra_entropy.second);
  TEST_ASSERT_EQUAL_INT(2, a.protocol_major_ver);
  TEST_ASSERT_EQUAL_INT(0, a.protocol_minor_ver);
  TEST_ASSERT_EQUAL_STRING("1000000", a.min_utxo.c_str());
  TEST_ASSERT_EQUAL_STRING("340000000", a.min_pool_cost.c_str());
  TEST_ASSERT_EQUAL_STRING("1a3be38bcbb7911969283716ad7aa550250226b76a61fc51cc9a9a35d9276d81", a.nonce.c_str());
  TEST_ASSERT_EQUAL_DOUBLE(0.0577, a.price_mem);
  TEST_ASSERT_EQUAL_DOUBLE(0.0000721, a.price_step);
  TEST_ASSERT_EQUAL_STRING("34482", a.coins_per_utxo_word.c_str());
  TEST_ASSERT_EQUAL_STRING("10000000", a.max_tx_ex_mem.c_str());
  TEST_ASSERT_EQUAL_STRING("10000000000", a.max_tx_ex_steps.c_str());
  TEST_ASSERT_EQUAL_STRING("50000000", a.max_block_ex_mem.c_str());
  TEST_ASSERT_EQUAL_STRING("40000000000", a.max_block_ex_steps.c_str());
  TEST_ASSERT_EQUAL_STRING("5000", a.max_val_size.c_str());
  TEST_ASSERT_EQUAL_INT(150, a.collateral_percent);
  TEST_ASSERT_EQUAL_INT(3, a.max_collateral_inputs);
  TEST_ASSERT_EQUAL_STRING("34482", a.coins_per_utxo_word.c_str());
}

void test_StakeDistribution() {
  std::string raw =
    "{"
    "  \"stake_address\": \"stake1u9l5q5jwgelgagzyt6nuaasefgmn8pd25c8e9qpeprq0tdcp0e3uk\","
    "  \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\","
    "  \"amount\": \"4440295078\""
    "}";

  StakeDistribution a1(raw);
  StakeDistribution a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("stake1u9l5q5jwgelgagzyt6nuaasefgmn8pd25c8e9qpeprq0tdcp0e3uk", a.stake_address.c_str());
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_STRING("4440295078", a.amount.c_str());
}

void test_PoolStakeDistribution() {
  std::string raw =
    "{"
    "  \"stake_address\": \"stake1u9l5q5jwgelgagzyt6nuaasefgmn8pd25c8e9qpeprq0tdcp0e3uk\","
    "  \"amount\": \"4440295078\""
    "}";

  PoolStakeDistribution a1(raw);
  PoolStakeDistribution a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("stake1u9l5q5jwgelgagzyt6nuaasefgmn8pd25c8e9qpeprq0tdcp0e3uk", a.stake_address.c_str());
  TEST_ASSERT_EQUAL_STRING("4440295078", a.amount.c_str());
}
