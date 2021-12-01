
#include "types/Pool.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_PoolEpoch() {
  std::string raw =
    "{"
    "  \"pool_id\": \"pool19u64770wqp6s95gkajc8udheske5e6ljmpq33awxk326zjaza0q\","
    "  \"epoch\": 225"
    "}";

  PoolEpoch a1(raw);
  PoolEpoch a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("pool19u64770wqp6s95gkajc8udheske5e6ljmpq33awxk326zjaza0q", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_INT(225, a.epoch);
}

void test_PoolInfo() {
  std::string raw =
    "{"
    "  \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\","
    "  \"hex\": \"0f292fcaa02b8b2f9b3c8f9fd8e0bb21abedb692a6d5058df3ef2735\","
    "  \"vrf_key\": \"0b5245f9934ec2151116fb8ec00f35fd00e0aa3b075c4ed12cce440f999d8233\","
    "  \"blocks_minted\": 69,"
    "  \"live_stake\": \"6900000000\","
    "  \"live_size\": 0.42,"
    "  \"live_saturation\": 0.93,"
    "  \"live_delegators\": 127,"
    "  \"active_stake\": \"4200000000\","
    "  \"active_size\": 0.43,"
    "  \"declared_pledge\": \"5000000000\","
    "  \"live_pledge\": \"5000000001\","
    "  \"margin_cost\": 0.05,"
    "  \"fixed_cost\": \"340000000\","
    "  \"reward_account\": \"stake1uxkptsa4lkr55jleztw43t37vgdn88l6ghclfwuxld2eykgpgvg3f\","
    "  \"owners\": ["
    "    \"stake1u98nnlkvkk23vtvf9273uq7cph5ww6u2yq2389psuqet90sv4xv9v\""
    "  ],"
    "  \"registration\": ["
    "    \"9f83e5484f543e05b52e99988272a31da373f3aab4c064c76db96643a355d9dc\","
    "    \"7ce3b8c433bf401a190d58c8c483d8e3564dfd29ae8633c8b1b3e6c814403e95\","
    "    \"3e6e1200ce92977c3fe5996bd4d7d7e192bcb7e231bc762f9f240c76766535b9\""
    "  ],"
    "  \"retirement\": ["
    "    \"252f622976d39e646815db75a77289cf16df4ad2b287dd8e3a889ce14c13d1a8\""
    "  ]"
    "}";

  PoolInfo a1(raw);
  PoolInfo a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_STRING("0f292fcaa02b8b2f9b3c8f9fd8e0bb21abedb692a6d5058df3ef2735", a.hex.c_str());
  TEST_ASSERT_EQUAL_STRING("0b5245f9934ec2151116fb8ec00f35fd00e0aa3b075c4ed12cce440f999d8233", a.vrf_key.c_str());
  TEST_ASSERT_EQUAL_INT(69, a.blocks_minted);
  TEST_ASSERT_EQUAL_STRING("6900000000", a.live_stake.c_str());
  TEST_ASSERT_EQUAL_DOUBLE(0.42, a.live_size);
  TEST_ASSERT_EQUAL_DOUBLE(0.93, a.live_saturation);
  TEST_ASSERT_EQUAL_DOUBLE(127, a.live_delegators);
  TEST_ASSERT_EQUAL_STRING("4200000000", a.active_stake.c_str());
  TEST_ASSERT_EQUAL_DOUBLE(0.43, a.active_size);
  TEST_ASSERT_EQUAL_STRING("5000000000", a.declared_pledge.c_str());
  TEST_ASSERT_EQUAL_STRING("5000000001", a.live_pledge.c_str());
  TEST_ASSERT_EQUAL_DOUBLE(0.05, a.margin_cost);
  TEST_ASSERT_EQUAL_STRING("340000000", a.fixed_cost.c_str());
  TEST_ASSERT_EQUAL_STRING("stake1uxkptsa4lkr55jleztw43t37vgdn88l6ghclfwuxld2eykgpgvg3f", a.reward_account.c_str());
  TEST_ASSERT_EQUAL_INT(1, a.owners.size());
  TEST_ASSERT_EQUAL_INT(3, a.registration.size());
  TEST_ASSERT_EQUAL_INT(1, a.retirement.size());
}

void test_PoolHistory() {
  std::string raw =
    "{"
    "  \"epoch\": 233,"
    "  \"blocks\": 22,"
    "  \"active_stake\": \"20485965693569\","
    "  \"active_size\": 1.2345,"
    "  \"delegators_count\": 115,"
    "  \"rewards\": \"206936253674159\","
    "  \"fees\": \"1290968354\""
    "}";

  PoolHistory a1(raw);
  PoolHistory a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(233, a.epoch);
  TEST_ASSERT_EQUAL_INT(22, a.blocks);
  TEST_ASSERT_EQUAL_STRING("20485965693569", a.active_stake.c_str());
  TEST_ASSERT_EQUAL_DOUBLE(1.2345, a.active_size);
  TEST_ASSERT_EQUAL_INT(115, a.delegators_count);
  TEST_ASSERT_EQUAL_STRING("206936253674159", a.rewards.c_str());
  TEST_ASSERT_EQUAL_STRING("1290968354", a.fees.c_str());
}

void test_PoolMetadata() {
  std::string raw =
    "{"
    "  \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\","
    "  \"hex\": \"0f292fcaa02b8b2f9b3c8f9fd8e0bb21abedb692a6d5058df3ef2735\","
    "  \"url\": \"https://stakenuts.com/mainnet.json\","
    "  \"hash\": \"47c0c68cb57f4a5b4a87bad896fc274678e7aea98e200fa14a1cb40c0cab1d8c\","
    "  \"ticker\": \"NUTS\","
    "  \"name\": \"Stake Nuts\","
    "  \"description\": \"The best pool ever\","
    "  \"homepage\": \"https://stakentus.com/\""
    "}";

  PoolMetadata a1(raw);
  PoolMetadata a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_STRING("0f292fcaa02b8b2f9b3c8f9fd8e0bb21abedb692a6d5058df3ef2735", a.hex.c_str());
  TEST_ASSERT_EQUAL_STRING("https://stakenuts.com/mainnet.json", a.url.first.c_str());
  TEST_ASSERT_EQUAL_STRING("47c0c68cb57f4a5b4a87bad896fc274678e7aea98e200fa14a1cb40c0cab1d8c", a.hash.first.c_str());
  TEST_ASSERT_EQUAL_STRING("NUTS", a.ticker.first.c_str());
  TEST_ASSERT_EQUAL_STRING("Stake Nuts", a.name.first.c_str());
  TEST_ASSERT_EQUAL_STRING("The best pool ever", a.description.first.c_str());
  TEST_ASSERT_EQUAL_STRING("https://stakentus.com/", a.homepage.first.c_str());
}

void test_PoolRelay() {
  std::string raw =
    "{"
    "  \"ipv4\": \"4.4.4.4\","
    "  \"ipv6\": \"https://stakenuts.com/mainnet.json\","
    "  \"dns\": \"relay1.stakenuts.com\","
    "  \"dns_srv\": \"_relays._tcp.relays.stakenuts.com\","
    "  \"port\": 3001"
    "}";

  PoolRelay a1(raw);
  PoolRelay a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("4.4.4.4", a.ipv4.first.c_str());
  TEST_ASSERT_EQUAL_STRING("https://stakenuts.com/mainnet.json", a.ipv6.first.c_str());
  TEST_ASSERT_EQUAL_STRING("relay1.stakenuts.com", a.dns.first.c_str());
  TEST_ASSERT_EQUAL_STRING("_relays._tcp.relays.stakenuts.com", a.dns_srv.first.c_str());
  TEST_ASSERT_EQUAL_INT(3001, a.port);
}

void test_PoolDelegator() {
  std::string raw =
    "{"
    "  \"address\": \"stake1ux4vspfvwuus9uwyp5p3f0ky7a30jq5j80jxse0fr7pa56sgn8kha\","
    "  \"live_stake\": \"1137959159981411\""
    "}";

  PoolDelegator a1(raw);
  PoolDelegator a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("stake1ux4vspfvwuus9uwyp5p3f0ky7a30jq5j80jxse0fr7pa56sgn8kha", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("1137959159981411", a.live_stake.c_str());
}

void test_PoolUpdate() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"6804edf9712d2b619edb6ac86861fe93a730693183a262b165fcc1ba1bc99cad\","
    "  \"cert_index\": 0,"
    "  \"action\": \"registered\""
    "}";

  PoolUpdate a1(raw);
  PoolUpdate a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("6804edf9712d2b619edb6ac86861fe93a730693183a262b165fcc1ba1bc99cad", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, a.cert_index);
  TEST_ASSERT_EQUAL_STRING("registered", a.action.c_str());
}
