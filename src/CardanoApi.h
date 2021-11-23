#ifndef BLOCKFROST_CPP_CLIENT_CardanoApi_H_
#define BLOCKFROST_CPP_CLIENT_CardanoApi_H_

#include "AbstractService.h"
#include "types/Response.h"
#include "types/Helpers.h"
#include <list>

#include "types/Account.h"
#include "types/Address.h"
#include "types/Asset.h"
#include "types/Block.h"
#include "types/Epoch.h"
#include "types/Genesis.h"
#include "types/Metadata.h"
#include "types/Network.h"
#include "types/Pool.h"
#include "types/Script.h"
#include "types/Transaction.h"

#if defined(ESP8266)
#include <WiFiClientSecureBearSSL.h>
#endif


namespace Blockfrost {

class CardanoApi : public AbstractService {

using AbstractService::AbstractService;
public:
    CardanoApi() = default;
    virtual ~CardanoApi() = default;

    /**
    * Specific block.
    *
    * Return the content of a requested block.
    * \param hashOrNumber Hash or number of the requested block. *Required*
    */
    Response<Block>
      getBlock(std::string hashOrNumber);

    /**
    * Listing of next blocks.
    *
    * Return the list of blocks following a specific block.
    * \param hashOrNumber Hash of the requested block. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    */
    Response<std::vector<Block>>
      getNextBlocks(std::string hashOrNumber, int count, int page);

    /**
    * Listing of previous blocks.
    *
    * Return the list of blocks preceding a specific block.
    * \param hashOrNumber Hash of the requested block *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    */
    Response<std::vector<Block>>
      getPreviousBlocks(std::string hashOrNumber, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE);

    /**
    * Block transactions.
    *
    * Return the transactions within the block.
    * \param hashOrNumber Hash of the requested block. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order Ordered by tx index in the block. The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last. 
    */
    Response<std::vector<std::string>>
      getBlockTxs(std::string hashOrNumber, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Latest block.
    *
    * Return the latest block available to the backends, also known as the tip of the blockchain.
    */
    Response<Block>
      getLatestBlock();

    /**
    * Latest block transactions.
    *
    * Return the transactions within the latest block.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order Ordered by tx index in the block. The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<std::string>>
      getLatestBlockTxs(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Specific block in a slot.
    *
    * Return the content of a requested block for a specific slot.
    * \param slotNumber Slot position for requested block. *Required*
    */
    Response<Block>
      getBlockSlot(int slotNumber);

    /**
    * Specific block in a slot in an epoch.
    *
    * Return the content of a requested block for a specific slot in an epoch. 
    * \param epochNumber Epoch for specific epoch slot. *Required*
    * \param slotNumber Slot position for requested block. *Required*
    */
    Response<Block>
      getBlockEpochSlot(int epochNumber, int slotNumber);

    // Accounts

    /**
    * Specific account address.
    *
    * Obtain information about a specific stake account.
    * \param stakeAddress Bech32 stake address.
    */
    Response<Account>
      getAccount(std::string stakeAddress);

    /**
    * Account reward history.
    *
    * Obtain information about the reward history of a specific account.
    * \param stakeAddress Bech32 stake address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AccountReward>>
      getAccountRewards(std::string stakeAddress, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Account history.
    *
    * Obtain information about the history of a specific account.
    * \param stakeAddress Bech32 stake address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AccountHistory>>
      getAccountHistory(std::string stakeAddress, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Account delegation history.
    *
    * Obtain information about the delegation of a specific account.
    * \param stakeAddress Bech32 stake address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AccountDelegation>>
      getAccountDelegations(std::string stakeAddress, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Account registration history.
    *
    * Obtain information about the registrations and deregistrations of a specific account.
    * \param stakeAddress Bech32 stake address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AccountRegistration>>
      getAccountRegistrations(std::string stakeAddress, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Account withdrawal history.
    *
    * Obtain information about the withdrawals of a specific account.
    * \param stakeAddress Bech32 stake address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AccountWithdrawal>>
      getAccountWithdrawals(std::string stakeAddress, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Account MIR history.
    *
    * Obtain information about the MIRs of a specific account.
    * \param stakeAddress Bech32 stake address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AccountMir>>
      getAccountMirs(std::string stakeAddress, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Specific address.
    *
    * Obtain information about a specific address.
    * \param address Bech32 address.
    */
    Response<Address>
      getAddress(std::string address);

    /**
    * Address details.
    *
    * Obtain details about an address.
    * \param address Bech32 address.
    */
    Response<AddressDetails>
      getAddressDetails(std::string address);

    /**
    * Address UTXOs.
    *
    * UTXOs of the address.
    * \param address Bech32 address.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order Ordered by tx index in the block. The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AddressUtxo>>
      getAddressUtxos(std::string address, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Address UTXOs of a given asset.
    *
    * UTXOs of the address.
    * \param address Bech32 address.
    * \param asset Concatenation of the policy_id and hex-encoded asset_name.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order Ordered by tx index in the block. The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AddressUtxo>>
      getAddressUtxosAsset(std::string address, std::string asset, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Address transactions.
    *
    * Transactions on the address.
    * \param address Bech32 address.
    * \param count The numbers of pools per page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    * \param from The block number and optionally also index from which (inclusive) to start search for results, concatenated using colon. Has to be lower than or equal to `to` parameter.
    * \param to The block number and optionally also index where (inclusive) to end the search for results, concatenated using colon. Has to be higher than or equal to `from` parameter.
    */
    Response<std::vector<AddressTransaction>>
      getAddressTransactions(
          std::string address
          , int count = DEFAULT_COUNT
          , int page = DEFAULT_PAGE
          , std::string order = DEFAULT_ORDER);

    /**
    * Address transactions. (from-to block)
    *
    * Transactions on the address.
    * \param address Bech32 address.
    * \param count The numbers of pools per page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    * \param from The block number and optionally also index from which (inclusive) to start search for results, concatenated using colon. Has to be lower than or equal to `to` parameter.
    * \param to The block number and optionally also index where (inclusive) to end the search for results, concatenated using colon. Has to be higher than or equal to `from` parameter.
    */
    Response<std::vector<AddressTransaction>>
      getAddressTransactions(
          std::string address
          , int count
          , int page
          , std::string order
          , std::string from
          , std::string to);

    // Assets

    /**
    * Assets.
    *
    * List of assets.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */

    Response<std::vector<Asset>>
      getAssets(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Specific asset.
    *
    * Information about a specific asset
    * \param asset Concatenation of the policy_id and hex-encoded asset_name.
    */
    Response<AssetDetail>
      getAssetDetails(std::string asset);

    /**
    * Asset history.
    *
    * History of a specific asset
    * \param asset Concatenation of the policy_id and hex-encoded asset_name.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AssetHistory>>
      getAssetHistory(std::string asset, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Asset transactions.
    *
    * List of a specific asset transactions
    * \param asset Concatenation of the policy_id and hex-encoded asset_name.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AssetTransaction>>
      getAssetTransactions(std::string asset, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Asset addresses.
    *
    * List of a addresses containing a specific asset
    * \param asset Concatenation of the policy_id and hex-encoded asset_name.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<AssetAddress>>
      getAssetAddresses(std::string asset, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Assets of a specific policy.
    *
    * List of asset minted under a specific policy
    * \param policy_id Specific policy_id
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<Asset>>
      getAssetsByPolicy(std::string policy_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    // Epochs

    /**
    * Latest epoch.
    *
    * Return the information about the latest, therefore current, epoch.
    */
    Response<Epoch>
      getLatestEpoch();

    /**
    * Latest epoch protocol parameters.
    *
    * Return the protocol parameters for the latest epoch.
    */
    Response<ProtocolParams>
      getLatestEpochProtocolParams();

    /**
    * Specific epoch.
    *
    * Return the content of the requested epoch.
    * \param number Number of the epoch *Required*
    */
    Response<Epoch>
      getEpoch(int epoch_number);

    /**
    * Protocol parameters.
    *
    * Return the protocol parameters for the epoch specified.
    * \param number Number of the epoch *Required*
    */
    Response<ProtocolParams>
      getEpochProtocolParams(int epoch_number);

    /**
    * Listing of next epochs.
    *
    * Return the list of epochs following a specific epoch.
    * \param number Number of the requested epoch. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    */
    Response<std::vector<Epoch>>
      getNextEpochs(int epoch_number, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE);

    /**
    * Listing of previous epochs.
    *
    * Return the list of epochs preceding a specific epoch.
    * \param number Number of the epoch *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results
    */
    Response<std::vector<Epoch>>
      getPreviousEpochs(int epoch_number, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE);

    /**
    * Stake distribution.
    *
    * Return the active stake distribution for the specified epoch.
    * \param number Number of the epoch *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    */
    Response<std::vector<StakeDistribution>>
      getEpochStake(int epoch_number, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE);

    /**
    * Stake distribution by pool.
    *
    * Return the active stake distribution for the epoch specified by stake pool.
    * \param number Number of the epoch *Required*
    * \param poolId Stake pool ID to filter *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    */
    Response<std::vector<PoolStakeDistribution>>
      getEpochStakeByPool(int epoch_number, std::string pool_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE);

    /**
    * Block distribution.
    *
    * Return the blocks minted for the epoch specified.
    * \param number Number of the epoch *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<std::string>>
      getEpochBlocks(int epoch_number, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Block distribution.
    *
    * Return the block minted for the epoch specified by stake pool.
    * \param number Number of the epoch *Required*
    * \param poolId Stake pool ID to filter *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<std::string>>
      getEpochBlocksByPool(int epoch_number, std::string pool_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    // Ledger

    /**
    * Blockchain genesis.
    *
    * Return the information about blockchain genesis.
    */
    Response<Genesis>
      getLedgerGenesis();

    // Metadata

    /**
    * Transaction metadata labels.
    *
    * List of all used transaction metadata labels.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<TxMeta>>
      getTxMetadataLabels(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);


    /**
    * Transaction metadata content in JSON.
    *
    * Transaction metadata per label.
    * \param label Metadata label.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<TxMetaJSON>>
      getTxMetadataByLabelJSON(std::string label, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Transaction metadata content in CBOR.
    *
    * Transaction metadata per label.
    * \param label Metadata label.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<TxMetaCBOR>>
      getTxMetadataByLabelCBOR(std::string label, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    // Network

    /**
    * Network information.
    *
    * Return detailed network information.
    */
    Response<Network>
      getNetworkInfo();

    // Pools

    Response<std::vector<std::string>>
      listPools(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * List of retired stake pools.
    *
    * List of already retired pools.
    * \param count The numbers of pools per page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<PoolEpoch>>
      listRetiredPools(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * List of retiring stake pools.
    *
    * List of stake pools retiring in the upcoming epochs
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<PoolEpoch>>
      listRetiringPools(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Specific stake pool.
    *
    * Pool information.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    */
    Response<PoolInfo>
      getPool(std::string pool_id);

    /**
    * Stake pool history.
    *
    * History of stake pool parameters over epochs.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<PoolHistory>>
      getPoolHistory(std::string pool_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Stake pool metadata.
    *
    * Stake pool registration metadata.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    */
    Response<std::pair<PoolMetadata, bool>>
      getPoolMetadata(std::string pool_id);

    /**
    * Stake pool relays.
    *
    * Relays of a stake pool.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    */
    Response<std::vector<PoolRelay>>
      getPoolRelays(std::string pool_id);

    /**
    * Stake pool delegators.
    *
    * List of current stake pools delegators.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<PoolDelegator>>
      getPoolDelegators(std::string pool_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Stake pool blocks.
    *
    * List of stake pools blocks.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<std::string>>
      getPoolBlocks(std::string pool_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Stake pool updates.
    *
    * List of certificate updates to the stake pool.
    * \param poolId Bech32 or hexadecimal pool ID. *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<PoolUpdate>>
      getPoolUpdates(std::string pool_id, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    // Scripts

    /**
    * Scripts.
    *
    * List of scripts.
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<Script>>
      listScripts(int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Specific script.
    *
    * Information about a specific script
    * \param scriptHash Hash of the script *Required*
    */
    Response<ScriptInfo>
      getScript(std::string script_hash);

    /**
    * Redeemers of a specific script.
    *
    * List of redeemers of a specific script
    * \param scriptHash Hash of the script *Required*
    * \param count The number of results displayed on one page.
    * \param page The page number for listing the results.
    * \param order The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last.
    */
    Response<std::vector<ScriptRedeemer>>
      getScriptRedeemers(std::string script_hash, int count = DEFAULT_COUNT, int page = DEFAULT_PAGE, std::string order = DEFAULT_ORDER);

    /**
    * Datum value.
    *
    * Query JSON value of a datum by its hash
    * \param datumHash Hash of the datum *Required*
    */
    Response<ScriptDatum>
      getScriptDatum(std::string datum_hash);

    /**
    * Script JSON.
    *
    * JSON representation of a `timelock` script
    * \param scriptHash Hash of the script *Required*
    */
    Response<ScriptJSON>
      getScriptJSON(std::string script_hash);

    /**
    * Script CBOR.
    *
    * CBOR representation of a `plutus` script
    * \param scriptHash Hash of the script *Required*
    */
    Response<ScriptCBOR>
      getScriptCBOR(std::string script_hash);

    // Transactions

    /**
    * Specific transaction.
    *
    * Return content of the requested transaction.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<Transaction>
      getTx(std::string tx_hash);

    /**
    * Transaction UTXOs.
    *
    * Return the inputs and UTXOs of the specific transaction.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<TransactionUtxos>
      getTxUtxos(std::string tx_hash);

    /**
    * Transaction redeemers.
    *
    * Obtain the transaction redeemers.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<std::vector<TransactionRedeemer>>
      getTxRedeemers(std::string tx_hash);

    /**
    * Transaction stake addresses certificates.
    *
    * Obtain information about (de)registration of stake addresses within a transaction.
    * \param hash Hash of the requested transaction. *Required*
    */
    Response<std::vector<TransactionStake>>
      getTxStakes(std::string tx_hash);

    /**
    * Transaction delegation certificates.
    *
    * Obtain information about delegation certificates of a specific transaction.
    * \param hash Hash of the requested transaction. *Required*
    */
    Response<std::vector<TransactionDelegation>>
      getTxDelegations(std::string tx_hash);

    /**
    * Transaction withdrawal.
    *
    * Obtain information about withdrawals of a specific transaction.
    * \param hash Hash of the requested transaction. *Required*
    */
    Response<std::vector<TransactionWithdrawal>>
      getTxWithdrawals(std::string tx_hash);

    /**
    * Transaction MIRs.
    *
    * Obtain information about Move Instantaneous Rewards (MIRs) of a specific transaction.
    * \param hash Hash of the requested transaction. *Required*
    */
    Response<std::vector<TransactionMir>>
      getTxMirs(std::string tx_hash);

    /**
    * Transaction stake pool registration and update certificates.
    *
    * Obtain information about stake pool registration and update certificates of a specific transaction.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<std::vector<TransactionPoolUpdate>>
      getTxPoolUpdates(std::string tx_hash);

    /**
    * Transaction stake pool retirement certificates.
    *
    * Obtain information about stake pool retirements within a specific transaction.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<std::vector<TransactionPoolRetiring>>
      getTxPoolRetiring(std::string tx_hash);

    /**
    * Transaction metadata.
    *
    * Obtain the transaction metadata.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<std::vector<TransactionMetaJSON>>
      getTxMetadataJSON(std::string tx_hash);

    /**
    * Transaction metadata in CBOR.
    *
    * Obtain the transaction metadata in CBOR.
    * \param hash Hash of the requested transaction *Required*
    */
    Response<std::vector<TransactionMetaCBOR>>
      getTxMetadataCBOR(std::string tx_hash);


    /**
    * Submit a transaction.
    *
    * Submit an already serialized transaction to the network.
    * \param content *Required*
    */
    Response<std::string>
      txSubmit(std::string content);
};


}

#endif /* BLOCKFROST_CPP_CLIENT_CardanoApi_H_ */
