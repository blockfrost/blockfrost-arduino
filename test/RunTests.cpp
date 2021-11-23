
#include <tests/BlockTest.cpp>
#include <tests/AccountTest.cpp>
#include <tests/AddressTest.cpp>
#include <tests/AmountTest.cpp>
#include <tests/AssetTest.cpp>
#include <tests/EpochTest.cpp>
#include <tests/GenesisTest.cpp>
#include <tests/MetadataTest.cpp>
#include <tests/NetworkTest.cpp>
#include <tests/PoolTest.cpp>
#include <tests/ScriptTest.cpp>
#include <tests/TransactionTest.cpp>
#include <tests/IPFSTest.cpp>
#include <tests/NutLinkTest.cpp>
#include <tests/CommonTest.cpp>

void setUp(){}

void tearDown(){}

void runTests(){
    RUN_TEST(test_Block);
    RUN_TEST(test_Account);
    RUN_TEST(test_AccountReward);
    RUN_TEST(test_AccountHistory);
    RUN_TEST(test_AccountDelegation);
    RUN_TEST(test_AccountRegistration);
    RUN_TEST(test_AccountWithdrawal);
    RUN_TEST(test_AccountMir);
    RUN_TEST(test_Address);
    RUN_TEST(test_AddressDetails);
    RUN_TEST(test_AddressTransactions);
    RUN_TEST(test_AddressUtxo);
    RUN_TEST(test_Amount);
    RUN_TEST(test_Asset);
    RUN_TEST(test_AssetHistory);
    RUN_TEST(test_AssetTransaction);
    RUN_TEST(test_AssetAddress);
    RUN_TEST(test_Epoch);
    RUN_TEST(test_ProtocolParams);
    RUN_TEST(test_StakeDistribution);
    RUN_TEST(test_PoolStakeDistribution);
    RUN_TEST(test_Genesis);
    RUN_TEST(test_TxMeta);
    RUN_TEST(test_TxMetaJSON);
    RUN_TEST(test_TxMetaCBOR);
    RUN_TEST(test_Network);
    RUN_TEST(test_PoolEpoch);
    RUN_TEST(test_PoolInfo);
    RUN_TEST(test_PoolHistory);
    RUN_TEST(test_PoolMetadata);
    RUN_TEST(test_PoolRelay);
    RUN_TEST(test_PoolDelegator);
    RUN_TEST(test_PoolUpdate);
    RUN_TEST(test_ScriptList);
    RUN_TEST(test_ScriptInfo);
    RUN_TEST(test_ScriptRedeemer);
    RUN_TEST(test_ScriptDatum);
    RUN_TEST(test_Transaction);
    RUN_TEST(test_TransactionUtxos);
    RUN_TEST(test_TransactionRedeemer);
    RUN_TEST(test_TransactionStake);
    RUN_TEST(test_TransactionDelegation);
    RUN_TEST(test_TransactionWithdrawal);
    RUN_TEST(test_TransactionMir);
    RUN_TEST(test_TransactionPoolUpdate);
    RUN_TEST(test_TransactionPoolRetiring);
    RUN_TEST(test_TransactionMetaJSON);
    RUN_TEST(test_TransactionMetaCBOR);
    RUN_TEST(test_IPFSAdd);
    RUN_TEST(test_IPFSPinChange);
    RUN_TEST(test_IPFSPin);
    RUN_TEST(test_NutLinkAddress);
    RUN_TEST(test_NutLinkAddressTicker);
    RUN_TEST(test_NutLinkTicker);
    RUN_TEST(test_NutLinkTickerAddress);
    RUN_TEST(test_URLVersion);
    RUN_TEST(test_Health);
    RUN_TEST(test_ServerTime);
    RUN_TEST(test_Metric);
    RUN_TEST(test_MetricEndpoint);
}

int main(void) {
    UNITY_BEGIN();
    runTests();
    return UNITY_END();
}

void setup() {
    UNITY_BEGIN();
    runTests();
    UNITY_END();
}

void loop() {
}
