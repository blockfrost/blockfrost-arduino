
#include "types/Transaction.h"

using namespace Blockfrost;

#include <string>
#include <list>
#include <unity.h>
#include "bourne/json.hpp"

void test_Transaction() {
  std::string raw =
    "{"
    "  \"hash\": \"1e043f100dce12d107f679685acd2fc0610e10f72a92d412794c9773d11d8477\","
    "  \"block\": \"356b7d7dbb696ccd12775c016941057a9dc70898d87a63fc752271bb46856940\","
    "  \"block_height\": 123456,"
    "  \"slot\": 42000000,"
    "  \"index\": 1,"
    "  \"output_amount\": ["
    "    {"
    "      \"unit\": \"lovelace\","
    "      \"quantity\": \"42000000\""
    "    },"
    "    {"
    "      \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "      \"quantity\": \"12\""
    "    }"
    "  ],"
    "  \"fees\": \"182485\","
    "  \"deposit\": \"0\","
    "  \"size\": 433,"
    "  \"invalid_before\": null,"
    "  \"invalid_hereafter\": \"13885913\","
    "  \"utxo_count\": 4,"
    "  \"withdrawal_count\": 0,"
    "  \"mir_cert_count\": 0,"
    "  \"delegation_count\": 0,"
    "  \"stake_cert_count\": 0,"
    "  \"pool_update_count\": 0,"
    "  \"pool_retire_count\": 0,"
    "  \"asset_mint_or_burn_count\": 0,"
    "  \"redeemer_count\": 0"
    "}";

  Transaction a1(raw);
  Transaction a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("1e043f100dce12d107f679685acd2fc0610e10f72a92d412794c9773d11d8477", a.hash.c_str());
  TEST_ASSERT_EQUAL_STRING("356b7d7dbb696ccd12775c016941057a9dc70898d87a63fc752271bb46856940", a.block.c_str());
  TEST_ASSERT_EQUAL_INT(123456, a.block_height);
  TEST_ASSERT_EQUAL_INT(42000000, a.slot);
  TEST_ASSERT_EQUAL_INT(1, a.index);

  TEST_ASSERT_EQUAL_STRING("lovelace", a.output_amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", a.output_amount.at(0).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.output_amount.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", a.output_amount.at(1).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("182485", a.fees.c_str());
  TEST_ASSERT_EQUAL_STRING("0", a.deposit.c_str());
  TEST_ASSERT_EQUAL_INT(433, a.size);
  TEST_ASSERT_EQUAL_INT(false, a.invalid_before.second);
  TEST_ASSERT_EQUAL_STRING("13885913", a.invalid_hereafter.first.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.invalid_hereafter.second);

  TEST_ASSERT_EQUAL_INT(4, a.utxo_count);
  TEST_ASSERT_EQUAL_INT(0, a.withdrawal_count);
  TEST_ASSERT_EQUAL_INT(0, a.mir_cert_count);
  TEST_ASSERT_EQUAL_INT(0, a.delegation_count);
  TEST_ASSERT_EQUAL_INT(0, a.stake_cert_count);
  TEST_ASSERT_EQUAL_INT(0, a.pool_update_count);
  TEST_ASSERT_EQUAL_INT(0, a.pool_retire_count);
  TEST_ASSERT_EQUAL_INT(0, a.asset_mint_or_burn_count);
  TEST_ASSERT_EQUAL_INT(0, a.redeemer_count);
}

void test_TransactionUtxos() {
  std::string raw =
    "{"
    "  \"hash\": \"1e043f100dce12d107f679685acd2fc0610e10f72a92d412794c9773d11d8477\","
    "  \"inputs\": ["
    "    {"
    "      \"address\": \"addr1q9ld26v2lv8wvrxxmvg90pn8n8n5k6tdst06q2s856rwmvnueldzuuqmnsye359fqrk8hwvenjnqultn7djtrlft7jnq7dy7wv\","
    "      \"amount\": ["
    "        {"
    "          \"unit\": \"lovelace\","
    "          \"quantity\": \"42000000\""
    "        },"
    "        {"
    "          \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "          \"quantity\": \"12\""
    "        }"
    "      ],"
    "      \"tx_hash\": \"1a0570af966fb355a7160e4f82d5a80b8681b7955f5d44bec0dce628516157f0\","
    "      \"output_index\": 0,"
    "      \"collateral\": false,"
    "      \"data_hash\": \"9e478573ab81ea7a8e31891ce0648b81229f408d596a3483e6f4f9b92d3cf710\""
    "    }"
    "  ],"
    "  \"outputs\": ["
    "    {"
    "      \"address\": \"addr1q9ld26v2lv8wvrxxmvg90pn8n8n5k6tdst06q2s856rwmvnueldzuuqmnsye359fqrk8hwvenjnqultn7djtrlft7jnq7dy7wv\","
    "      \"amount\": ["
    "        {"
    "          \"unit\": \"lovelace\","
    "          \"quantity\": \"42000000\""
    "        },"
    "        {"
    "          \"unit\": \"b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e\","
    "          \"quantity\": \"12\""
    "        }"
    "      ],"
    "      \"data_hash\": \"9e478573ab81ea7a8e31891ce0648b81229f408d596a3483e6f4f9b92d3cf710\","
    "      \"output_index\": 0"
    "    }"
    "  ]"
    "}";

  TransactionUtxos a1(raw);
  TransactionUtxos a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("1e043f100dce12d107f679685acd2fc0610e10f72a92d412794c9773d11d8477", a.hash.c_str());

  // inputs
  TEST_ASSERT_EQUAL_STRING("addr1q9ld26v2lv8wvrxxmvg90pn8n8n5k6tdst06q2s856rwmvnueldzuuqmnsye359fqrk8hwvenjnqultn7djtrlft7jnq7dy7wv", a.inputs.at(0).address.c_str());

  TEST_ASSERT_EQUAL_STRING("lovelace", a.inputs.at(0).amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", a.inputs.at(0).amount.at(0).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.inputs.at(0).amount.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", a.inputs.at(0).amount.at(1).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("1a0570af966fb355a7160e4f82d5a80b8681b7955f5d44bec0dce628516157f0", a.inputs.at(0).tx_hash.c_str());
  TEST_ASSERT_EQUAL_INT(0, a.inputs.at(0).output_index);
  TEST_ASSERT_EQUAL_INT(false, a.inputs.at(0).collateral);
  TEST_ASSERT_EQUAL_STRING("9e478573ab81ea7a8e31891ce0648b81229f408d596a3483e6f4f9b92d3cf710", a.inputs.at(0).data_hash.first.c_str());

  // outputs
  TEST_ASSERT_EQUAL_STRING("addr1q9ld26v2lv8wvrxxmvg90pn8n8n5k6tdst06q2s856rwmvnueldzuuqmnsye359fqrk8hwvenjnqultn7djtrlft7jnq7dy7wv", a.outputs.at(0).address.c_str());

  TEST_ASSERT_EQUAL_STRING("lovelace", a.outputs.at(0).amount.at(0).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("42000000", a.outputs.at(0).amount.at(0).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("b0d07d45fe9514f80213f4020e5a61241458be626841cde717cb38a76e7574636f696e", a.outputs.at(0).amount.at(1).unit.c_str());
  TEST_ASSERT_EQUAL_STRING("12", a.outputs.at(0).amount.at(1).quantity.c_str());

  TEST_ASSERT_EQUAL_STRING("9e478573ab81ea7a8e31891ce0648b81229f408d596a3483e6f4f9b92d3cf710", a.outputs.at(0).data_hash.first.c_str());
  TEST_ASSERT_EQUAL_INT(0, a.outputs.at(0).output_index);

}

void test_TransactionRedeemer() {
  std::string raw =
    "{"
    "  \"tx_index\": 0,"
    "  \"purpose\": \"spend\","
    "  \"script_hash\": \"ec26b89af41bef0f7585353831cb5da42b5b37185e0c8a526143b824\","
    "  \"datum_hash\": \"923918e403bf43c34b4ef6b48eb2ee04babed17320d8d1b9ff9ad086e86f44ec\","
    "  \"unit_mem\": \"1700\","
    "  \"unit_steps\": \"476468\","
    "  \"fee\": \"172033\""
    "}";

  TransactionRedeemer a1(raw);
  TransactionRedeemer a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(0, a.tx_index);
  TEST_ASSERT_EQUAL_STRING("spend", a.purpose.c_str());
  TEST_ASSERT_EQUAL_STRING("ec26b89af41bef0f7585353831cb5da42b5b37185e0c8a526143b824", a.script_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("923918e403bf43c34b4ef6b48eb2ee04babed17320d8d1b9ff9ad086e86f44ec", a.datum_hash.c_str());
  TEST_ASSERT_EQUAL_STRING("1700", a.unit_mem.c_str());
  TEST_ASSERT_EQUAL_STRING("476468", a.unit_steps.c_str());
  TEST_ASSERT_EQUAL_STRING("172033", a.fee.c_str());
}

void test_TransactionStake() {
  std::string raw =
    "{"
    "  \"cert_index\": 1,"
    "  \"address\": \"stake1u9t3a0tcwune5xrnfjg4q7cpvjlgx9lcv0cuqf5mhfjwrvcwrulda\","
    "  \"registration\": true"
    "}";

  TransactionStake a1(raw);
  TransactionStake a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(1, a.cert_index);
  TEST_ASSERT_EQUAL_STRING("stake1u9t3a0tcwune5xrnfjg4q7cpvjlgx9lcv0cuqf5mhfjwrvcwrulda", a.address.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.registration);
}

void test_TransactionDelegation() {
  std::string raw =
    "{"
    "  \"index\": 4,"
    "  \"cert_index\": 2,"
    "  \"address\": \"stake1u9r76ypf5fskppa0cmttas05cgcswrttn6jrq4yd7jpdnvc7gt0yc\","
    "  \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\","
    "  \"active_epoch\": 210"
    "}";

  TransactionDelegation a1(raw);
  TransactionDelegation a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(2, a.cert_index);
  TEST_ASSERT_EQUAL_STRING("stake1u9r76ypf5fskppa0cmttas05cgcswrttn6jrq4yd7jpdnvc7gt0yc", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_INT(210, a.active_epoch);
}

void test_TransactionWithdrawal() {
  std::string raw =
    "{"
    "  \"address\": \"stake1u9r76ypf5fskppa0cmttas05cgcswrttn6jrq4yd7jpdnvc7gt0yc\","
    "  \"amount\": \"431833601\""
    "}";

  TransactionWithdrawal a1(raw);
  TransactionWithdrawal a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("stake1u9r76ypf5fskppa0cmttas05cgcswrttn6jrq4yd7jpdnvc7gt0yc", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("431833601", a.amount.c_str());
}

void test_TransactionMir() {
  std::string raw =
    "{"
    "  \"pot\": \"reserve\","
    "  \"cert_index\": 3,"
    "  \"address\": \"stake1u9r76ypf5fskppa0cmttas05cgcswrttn6jrq4yd7jpdnvc7gt0yc\","
    "  \"amount\": \"431833601\""
    "}";

  TransactionMir a1(raw);
  TransactionMir a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("reserve", a.pot.c_str());
  TEST_ASSERT_EQUAL_INT(3, a.cert_index);
  TEST_ASSERT_EQUAL_STRING("stake1u9r76ypf5fskppa0cmttas05cgcswrttn6jrq4yd7jpdnvc7gt0yc", a.address.c_str());
  TEST_ASSERT_EQUAL_STRING("431833601", a.amount.c_str());
}

void test_TransactionPoolUpdate() {
  std::string raw =
    "{"
    "  \"cert_index\": 6,"
    "  \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\","
    "  \"vrf_key\": \"0b5245f9934ec2151116fb8ec00f35fd00e0aa3b075c4ed12cce440f999d8233\","
    "  \"pledge\": \"5000000000\","
    "  \"margin_cost\": 0.05,"
    "  \"fixed_cost\": \"340000000\","
    "  \"reward_account\": \"stake1uxkptsa4lkr55jleztw43t37vgdn88l6ghclfwuxld2eykgpgvg3f\","
    "  \"owners\": ["
    "    \"stake1u98nnlkvkk23vtvf9273uq7cph5ww6u2yq2389psuqet90sv4xv9v\""
    "  ],"
    "  \"metadata\": {"
    "    \"url\": \"https://stakenuts.com/mainnet.json\","
    "    \"hash\": \"47c0c68cb57f4a5b4a87bad896fc274678e7aea98e200fa14a1cb40c0cab1d8c\","
    "    \"ticker\": \"NUTS\","
    "    \"name\": \"Stake Nuts\","
    "    \"description\": \"The best pool ever\","
    "    \"homepage\": \"https://stakentus.com/\""
    "  },"
    "  \"relays\": ["
    "    {"
    "      \"ipv4\": \"4.4.4.4\","
    "      \"ipv6\": \"https://stakenuts.com/mainnet.json\","
    "      \"dns\": \"relay1.stakenuts.com\","
    "      \"dns_srv\": \"_relays._tcp.relays.stakenuts.com\","
    "      \"port\": 3001"
    "    }"
    "  ],"
    "  \"active_epoch\": 210"
    "}";

  TransactionPoolUpdate a1(raw);
  TransactionPoolUpdate a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(6, a.cert_index);
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_STRING("0b5245f9934ec2151116fb8ec00f35fd00e0aa3b075c4ed12cce440f999d8233", a.vrf_key.c_str());
  TEST_ASSERT_EQUAL_STRING("5000000000", a.pledge.c_str());
  TEST_ASSERT_EQUAL_DOUBLE(0.05, a.margin_cost);
  TEST_ASSERT_EQUAL_STRING("340000000", a.fixed_cost.c_str());
  TEST_ASSERT_EQUAL_STRING("stake1uxkptsa4lkr55jleztw43t37vgdn88l6ghclfwuxld2eykgpgvg3f", a.reward_account.c_str());
  TEST_ASSERT_EQUAL_STRING("stake1u98nnlkvkk23vtvf9273uq7cph5ww6u2yq2389psuqet90sv4xv9v", a.owners.at(0).c_str());

  TEST_ASSERT_EQUAL_STRING("https://stakenuts.com/mainnet.json", a.metadata.first.url.first.c_str());
  TEST_ASSERT_EQUAL_STRING("47c0c68cb57f4a5b4a87bad896fc274678e7aea98e200fa14a1cb40c0cab1d8c", a.metadata.first.hash.first.c_str());
  TEST_ASSERT_EQUAL_STRING("NUTS", a.metadata.first.ticker.first.c_str());
  TEST_ASSERT_EQUAL_STRING("Stake Nuts", a.metadata.first.name.first.c_str());
  TEST_ASSERT_EQUAL_STRING("The best pool ever", a.metadata.first.description.first.c_str());
  TEST_ASSERT_EQUAL_STRING("https://stakentus.com/", a.metadata.first.homepage.first.c_str());

  TEST_ASSERT_EQUAL_STRING("4.4.4.4", a.relays.at(0).ipv4.first.c_str());
  TEST_ASSERT_EQUAL_STRING("https://stakenuts.com/mainnet.json", a.relays.at(0).ipv6.first.c_str());
  TEST_ASSERT_EQUAL_STRING("relay1.stakenuts.com", a.relays.at(0).dns.first.c_str());
  TEST_ASSERT_EQUAL_STRING("_relays._tcp.relays.stakenuts.com", a.relays.at(0).dns_srv.first.c_str());
  TEST_ASSERT_EQUAL_INT(3001, a.relays.at(0).port);

  TEST_ASSERT_EQUAL_INT(210, a.active_epoch);
}

void test_TransactionPoolRetiring() {
  std::string raw =
    "{"
    "  \"cert_index\": 1,"
    "  \"pool_id\": \"pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy\","
    "  \"retiring_epoch\": 216"
    "}";

  TransactionPoolRetiring a1(raw);
  TransactionPoolRetiring a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_INT(1, a.cert_index);
  TEST_ASSERT_EQUAL_STRING("pool1pu5jlj4q9w9jlxeu370a3c9myx47md5j5m2str0naunn2q3lkdy", a.pool_id.c_str());
  TEST_ASSERT_EQUAL_INT(216, a.retiring_epoch);
}

void test_TransactionMetaJSON() {
  std::string raw =
    "{"
    "  \"label\": \"1967\","
    "  \"json_metadata\": {"
    "    \"metadata\": \"https://nut.link/metadata.json\","
    "    \"hash\": \"6bf124f217d0e5a0a8adb1dbd8540e1334280d49ab861127868339f43b3948af\""
    "  }"
    "}";

  TransactionMetaJSON a1(raw);
  TransactionMetaJSON a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("1967", a.label.c_str());
  TEST_ASSERT_EQUAL_INT(true, a.json_metadata.first.has_key("hash"));
}

void test_TransactionMetaCBOR() {
  std::string raw =
    "{"
    "  \"label\": \"1968\","
    "  \"metadata\": \"a100a16b436f6d62696e6174696f6e8601010101010c\""
    "}";

  TransactionMetaCBOR a1(raw);
  TransactionMetaCBOR a(a1.toJson().dump());

  TEST_ASSERT_EQUAL_STRING("1968", a.label.c_str());
  TEST_ASSERT_EQUAL_STRING("a100a16b436f6d62696e6174696f6e8601010101010c", a.metadata.first.c_str());
}
