
#include "types/Asset.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Asset() {
  std::string raw =
    "{"
    "  \"asset\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "  \"quantity\": \"1\""
    "}";

  Asset a1(raw);
  Asset a(a1.toJson().dump());
  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.asset.c_str());
  TEST_ASSERT_EQUAL_STRING("1", a.quantity.c_str());
}

void test_AssetDetail() {
  std::string raw =
    "{"
    "  \"asset\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "  \"policy_id\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a7\","
    "  \"asset_name\": \"6e7574636f696e\","
    "  \"fingerprint\": \"asset1pkpwyknlvul7az0xx8czhl60pyel45rpje4z8w\","
    "  \"quantity\": \"12000\","
    "  \"initial_mint_tx_hash\": \"6804edf9712d2b619edb6ac86861fe93a730693183a262b165fcc1ba1bc99cad\","
    "  \"mint_or_burn_count\": 1,"
    "  \"onchain_metadata\": {"
    "    \"name\": \"My NFT token\","
    "    \"image\": \"ipfs://ipfs/QmfKyJ4tuvHowwKQCbCHj4L5T3fSj8cjs7Aau8V7BWv226\""
    "  },"
    "  \"metadata\": {"
    "    \"name\": \"nutcoin\","
    "    \"description\": \"The Nut Coin\","
    "    \"ticker\": \"nutc\","
    "    \"url\": \"https://www.stakenuts.com/\","
    "    \"logo\": \"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\","
    "    \"decimals\": 6"
    "  }"
    "}";

  AssetDetail a1(raw);
  AssetDetail a(a1.toJson().dump());
  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.asset.c_str());
  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a7", a.policy_id.c_str());
  TEST_ASSERT_EQUAL_STRING("6e7574636f696e", a.asset_name.c_str());
  TEST_ASSERT_EQUAL_STRING("asset1pkpwyknlvul7az0xx8czhl60pyel45rpje4z8w", a.fingerprint.c_str());
  TEST_ASSERT_EQUAL_STRING("12000", a.quantity.c_str());
  TEST_ASSERT_EQUAL_STRING("6804edf9712d2b619edb6ac86861fe93a730693183a262b165fcc1ba1bc99cad", a.initial_mint_tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(1, a.mint_or_burn_count);

  TEST_ASSERT_EQUAL_INT(true, a.onchain_metadata.second);
  TEST_ASSERT_EQUAL_STRING("My NFT token", a.onchain_metadata.first.name.c_str());
  TEST_ASSERT_EQUAL_STRING("ipfs://ipfs/QmfKyJ4tuvHowwKQCbCHj4L5T3fSj8cjs7Aau8V7BWv226", a.onchain_metadata.first.image.c_str());

  TEST_ASSERT_EQUAL_INT(true, a.metadata.second);
  TEST_ASSERT_EQUAL_STRING("nutcoin", a.metadata.first.name.c_str());
  TEST_ASSERT_EQUAL_STRING("The Nut Coint", a.metadata.first.description.c_str());
  TEST_ASSERT_EQUAL_STRING("nutc", a.metadata.first.ticker.first.c_str());
  TEST_ASSERT_EQUAL_STRING("https://www.stakenuts.com/", a.metadata.first.url.first.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.metadata.first.logo.second);
  TEST_ASSERT_EQUAL_INT(6, a.metadata.first.decimals.first);
}

void test_AssetHistory() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"2dd15e0ef6e6a17841cb9541c27724072ce4d4b79b91e58432fbaa32d9572531\","
    "  \"amount\": \"10\","
    "  \"action\": \"minted\""
    "}";

  AssetHistory a1(raw);
  AssetHistory a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("2dd15e0ef6e6a17841cb9541c27724072ce4d4b79b91e58432fbaa32d9572531", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("10", a.amount.c_str());
  TEST_ASSERT_EQUAL_STRING("minted", a.action.c_str());
};

void test_AssetTransaction() {
  std::string raw =
    "{"
    "  \"tx_hash\": \"e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b\","
    "  \"tx_index\": 0,"
    "  \"block_height\": 564654"
    "}";

  AssetTransaction a1(raw);
  AssetTransaction a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("e8073fd5318ff43eca18a852527166aa8008bee9ee9e891f585612b7e4ba700b", a.tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, a.tx_index);
  TEST_ASSERT_EQUAL_INT(564654, a.block_height);
};

void test_AssetAddress() {
  std::string raw =
    "{"
    "  \"address\": \"addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz\","
    "  \"quantity\": \"1\""
    "}";

  AssetAddress a1(raw);
  AssetAddress a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("addr1qxqs59lphg8g6qndelq8xwqn60ag3aeyfcp33c2kdp46a09re5df3pzwwmyq946axfcejy5n4x0y99wqpgtp2gd0k09qsgy6pz", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("1", a.quantity.c_str());
}
