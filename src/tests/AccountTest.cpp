
#include "types/Account.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Account() {
  std::string raw =
    "{"
    "    \"stake_address\": \"stake1ux3g2c9dx2nhhehyrezyxpkstartcqmu9hk63qgfkccw5rqttygt7\","
    "    \"active\": true,"
    "    \"active_epoch\": 412,"
    "    \"controlled_amount\": \"619154618165\","
    "    \"rewards_sum\": \"319154618165\","
    "    \"withdrawals_sum\": \"12125369253\","
    "    \"reserves_sum\": \"319154618165\","
    "    \"treasury_sum\": \"12000000\","
    "    \"withdrawable_amount\": \"319154618165\","
    "    \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\""
    "}";

  Account a1(raw);
  Account a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("stake1ux3g2c9dx2nhhehyrezyxpkstartcqmu9hk63qgfkccw5rqttygt7", a.stake_address.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.active);
  TEST_ASSERT_EQUAL_INT(412, a.active_epoch);
  TEST_ASSERT_EQUAL_STRING("619154618165", a.controlled_amount.c_str());
  TEST_ASSERT_EQUAL_STRING("319154618165", a.rewards_sum.c_str());
  TEST_ASSERT_EQUAL_STRING("12125369253", a.withdrawals_sum.c_str());
  TEST_ASSERT_EQUAL_STRING("319154618165", a.reserves_sum.c_str());
  TEST_ASSERT_EQUAL_STRING("12000000", a.treasury_sum.c_str());
  TEST_ASSERT_EQUAL_STRING("319154618165", a.withdrawable_amount.c_str());
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.first.c_str());
}

void test_AccountReward() {
  std::string raw =
    "{"
    "    \"epoch\": 215,"
    "    \"amount\": \"12695385\","
    "    \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\""
    "}";

  AccountReward a1(raw);
  AccountReward a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(215, a.epoch);
  TEST_ASSERT_EQUAL_STRING("12695385", a.amount.c_str());
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
}

void test_AccountHistory() {
  std::string raw =
    "{"
    "    \"active_epoch\": 210,"
    "    \"amount\": \"12695385\","
    "    \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\""
    "}";

  AccountHistory a1(raw);
  AccountHistory a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(210, a.active_epoch);
  TEST_ASSERT_EQUAL_STRING("12695385", a.amount.c_str());
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
}

void test_AccountDelegation() {
  std::string raw =
    "{"
    "    \"active_epoch\": 210,"
    "    \"tx_hash\": \"2dd15e0ef6e6a17841cb9541c27724072ce4d4b79b91e58432fbaa32d9572531\","
    "    \"amount\": \"12695385\","
    "    \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\""
    "}";

  AccountDelegation a1(raw);
  AccountDelegation a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(210, a.active_epoch);
  TEST_ASSERT_EQUAL_STRING("2dd15e0ef6e6a17841cb9541c27724072ce4d4b79b91e58432fbaa32d9572531", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("12695385", a.amount.c_str());
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
}

void test_AccountRegistration() {
  std::string raw =
    "{"
    "    \"tx_hash\": \"2dd15e0ef6e6a17841cb9541c27724072ce4d4b79b91e58432fbaa32d9572531\","
    "    \"action\": \"registered\""
    "}";

  AccountRegistration a1(raw);
  AccountRegistration a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("2dd15e0ef6e6a17841cb9541c27724072ce4d4b79b91e58432fbaa32d9572531", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("registered", a.action.c_str());
}

void test_AccountWithdrawal() {
  std::string raw =
    "{"
    "    \"tx_hash\": \"4230b0cbccf6f449f0847d8ad1d634a7a49df60d8c142bb8cc2dbc8ca03d9e34\","
    "    \"amount\": \"97846969\""
    "}";

  AccountWithdrawal a1(raw);
  AccountWithdrawal a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("4230b0cbccf6f449f0847d8ad1d634a7a49df60d8c142bb8cc2dbc8ca03d9e34", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("97846969", a.amount.c_str());
}

void test_AccountMir() {
  std::string raw =
    "{"
    "    \"tx_hash\": \"4230b0cbccf6f449f0847d8ad1d634a7a49df60d8c142bb8cc2dbc8ca03d9e34\","
    "    \"amount\": \"97846969\""
    "}";

  AccountMir a1(raw);
  AccountMir a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("4230b0cbccf6f449f0847d8ad1d634a7a49df60d8c142bb8cc2dbc8ca03d9e34", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("97846969", a.amount.c_str());
}
