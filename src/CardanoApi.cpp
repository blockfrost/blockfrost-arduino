#include "CardanoApi.h"

using namespace Blockfrost;

Response<Block>
CardanoApi::getBlock(std::string hashOrNumber)
{
    std::string url =
        basepath
      + "/blocks/"
      + hashOrNumber;

    begin(url);
    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Block obj;

    if (httpCode == 200) {
      obj = Block(output_string);
      Response<Block> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Block> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<Block>>
  CardanoApi::getNextBlocks(std::string hashOrNumber, int count, int page)
{
    std::string url =
        basepath
      + "/blocks/"
      + hashOrNumber
      + "/next"
      + pagination(count, page);

    begin(url);
    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Block> obj = std::vector<Block>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Block(var.dump()));
      }

      Response<std::vector<Block>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Block>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<Block>>
  CardanoApi::getPreviousBlocks(std::string hashOrNumber, int count, int page)
{
    std::string url = basepath
      + "/blocks/"
      + hashOrNumber
      + "/previous"
      + pagination(count, page);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Block> obj = std::vector<Block>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Block(var.dump()));
      }

      Response<std::vector<Block>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Block>> response(obj, httpCode, err);
      return response;
    }
}


Response< std::vector<std::string>>
  CardanoApi::getBlockTxs(std::string hashOrNumber, int count, int page, std::string order)
{
    std::string url = basepath
      + "/blocks"
      + hashOrNumber
      + "/txs"
      + paginationOrder(count, page, order);

    begin(url);
    int httpCode = http.GET();
    String output = http.getString();
    std::string output_string = output.c_str();
    http.end();

    std::vector<std::string> obj = std::vector<std::string>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(var.to_string());
      }

      Response<std::vector<std::string>> response(obj, httpCode);
      return response;

    } else {
      Error err = Error(output_string);
      Response<std::vector<std::string>> response(obj, httpCode, err);
      return response;
    }
}

Response<Block> CardanoApi::getLatestBlock()
{
    std::string url = basepath + "/blocks/latest";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Block obj;

    if (httpCode == 200) {
      obj = Block(output_string);
      Response<Block> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Block> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<std::string>>
CardanoApi::getLatestBlockTxs(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/blocks/latest/txs"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    String output = http.getString();
    std::string output_string = output.c_str();
    http.end();

    std::vector<std::string> obj = std::vector<std::string>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(var.to_string());
      }

      Response<std::vector<std::string>> response(obj, httpCode);
      return response;

    } else {
      Error err = Error(output_string);
      Response<std::vector<std::string>> response(obj, httpCode, err);
      return response;
    }
}

Response<Block> CardanoApi::getBlockSlot(int slotNumber)
{
    std::string url =
        basepath
      + "/blocks/slot/"
      + stringify(slotNumber);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Block obj;

    if (httpCode == 200) {
      obj = Block(output_string);
      Response<Block> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Block> response(obj, httpCode, err);
      return response;
    }
}

Response<Block>
  CardanoApi::getBlockEpochSlot(int epochNumber, int slotNumber)
{
  std::string url =
      basepath
    + "/blocks/epoch/"
    + stringify(epochNumber)
    + "/slot/"
    + stringify(slotNumber);

  begin(url);
  int httpCode = http.GET();
  std::string output_string = http.getString().c_str();
  http.end();
  Block obj;

  if (httpCode == 200) {
    obj = Block(output_string);
    Response<Block> response(obj, httpCode);
    return response;
  } else {
    Error err = Error(output_string);
    Response<Block> response(obj, httpCode, err);
    return response;
  }
}

// Accounts

Response<Account> CardanoApi::getAccount(std::string stakeAddress)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Account obj;

    if (httpCode == 200) {
      obj = Account(output_string);
      Response<Account> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Account> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AccountReward>> CardanoApi::getAccountRewards(std::string stakeAddress, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress
      + "/rewards"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AccountReward> obj = std::vector<AccountReward>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AccountReward(var.dump()));
      }

      Response<std::vector<AccountReward>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AccountReward>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AccountHistory>> CardanoApi::getAccountHistory(std::string stakeAddress, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress
      + "/history"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AccountHistory> obj = std::vector<AccountHistory>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AccountHistory(var.dump()));
      }

      Response<std::vector<AccountHistory>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AccountHistory>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AccountDelegation>> CardanoApi::getAccountDelegations(std::string stakeAddress, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress
      + "/delegations"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AccountDelegation> obj = std::vector<AccountDelegation>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AccountDelegation(var.dump()));
      }

      Response<std::vector<AccountDelegation>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AccountDelegation>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AccountRegistration>> CardanoApi::getAccountRegistrations(std::string stakeAddress, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress
      + "/registrations"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AccountRegistration> obj = std::vector<AccountRegistration>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AccountRegistration(var.dump()));
      }

      Response<std::vector<AccountRegistration>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AccountRegistration>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AccountWithdrawal>> CardanoApi::getAccountWithdrawals(std::string stakeAddress, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress
      + "/withdrawals"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AccountWithdrawal> obj = std::vector<AccountWithdrawal>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AccountWithdrawal(var.dump()));
      }

      Response<std::vector<AccountWithdrawal>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AccountWithdrawal>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AccountMir>> CardanoApi::getAccountMirs(std::string stakeAddress, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/accounts/"
      + stakeAddress
      + "/mirs"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AccountMir> obj = std::vector<AccountMir>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AccountMir(var.dump()));
      }

      Response<std::vector<AccountMir>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AccountMir>> response(obj, httpCode, err);
      return response;
    }
}

// Addresses

Response<Address> CardanoApi::getAddress(std::string address)
{
    std::string url =
        basepath
      + "/addresses/"
      + address;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Address obj;

    if (httpCode == 200) {
      obj = Address(output_string);
      Response<Address> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Address> response(obj, httpCode, err);
      return response;
    }
}

Response<AddressDetails> CardanoApi::getAddressDetails(std::string address)
{
    std::string url =
        basepath
      + "/addresses/"
      + address
      + "/total";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    AddressDetails obj;

    if (httpCode == 200) {
      obj = AddressDetails(output_string);
      Response<AddressDetails> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<AddressDetails> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AddressUtxo>> CardanoApi::getAddressUtxos(std::string address, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/addresses/"
      + address
      + "/utxos"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AddressUtxo> obj = std::vector<AddressUtxo>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AddressUtxo(var.dump()));
      }

      Response<std::vector<AddressUtxo>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AddressUtxo>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AddressUtxo>> CardanoApi::getAddressUtxosAsset(std::string address, std::string asset, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/addresses/"
      + address
      + "/utxos"
      + asset
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AddressUtxo> obj = std::vector<AddressUtxo>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AddressUtxo(var.dump()));
      }

      Response<std::vector<AddressUtxo>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AddressUtxo>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AddressTransaction>> CardanoApi::getAddressTransactions(std::string address, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/addresses/"
      + address
      + "/transactions"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AddressTransaction> obj = std::vector<AddressTransaction>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AddressTransaction(var.dump()));
      }

      Response<std::vector<AddressTransaction>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AddressTransaction>> response(obj, httpCode, err);
      return response;
    }
}
Response<std::vector<AddressTransaction>> CardanoApi::getAddressTransactions(
    std::string address, int count, int page, std::string order
    , std::string from, std::string to)
{
    std::string url =
        basepath
      + "/addresses/"
      + address
      + "/transactions"
      + paginationOrder(count, page, order)
      + "&from=" + from
      + "&to=" + to;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AddressTransaction> obj = std::vector<AddressTransaction>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AddressTransaction(var.dump()));
      }

      Response<std::vector<AddressTransaction>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AddressTransaction>> response(obj, httpCode, err);
      return response;
    }
}

// Assets

Response<std::vector<Asset>> CardanoApi::getAssets(int count, int page, std::string order)

{
    std::string url =
        basepath
      + "/assets"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Asset> obj = std::vector<Asset>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Asset(var.dump()));
      }

      Response<std::vector<Asset>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Asset>> response(obj, httpCode, err);
      return response;
    }
}

// TODO: sad oom
Response<AssetDetail> CardanoApi::getAssetDetails(std::string asset)
{
    std::string url =
        basepath
      + "/assets/"
      + asset;

    begin(url);

    AssetDetail obj;
    int httpCode = http.GET();
    //std::string output_string = http.getString().c_str();
    obj = AssetDetail(http.getString().c_str()); //output_string);
    http.end();
      Response<AssetDetail> response(obj, httpCode);
      return response;

    //DEBUG_MSG("WTF %s\r\n", output_string.c_str());
    /*

    if (httpCode == 200) {
      obj = AssetDetail(output_string);
      Response<AssetDetail> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<AssetDetail> response(obj, httpCode, err);
      return response;
    }
    */
}

Response<std::vector<AssetHistory>> CardanoApi::getAssetHistory(std::string asset, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/assets/"
      + asset
      + "/history";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AssetHistory> obj = std::vector<AssetHistory>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AssetHistory(var.dump()));
      }

      Response<std::vector<AssetHistory>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AssetHistory>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AssetTransaction>> CardanoApi::getAssetTransactions(std::string asset, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/assets/"
      + asset
      + "/transactions";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AssetTransaction> obj = std::vector<AssetTransaction>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AssetTransaction(var.dump()));
      }

      Response<std::vector<AssetTransaction>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AssetTransaction>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<AssetAddress>> CardanoApi::getAssetAddresses(std::string asset, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/assets/"
      + asset
      + "/addresses";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<AssetAddress> obj = std::vector<AssetAddress>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(AssetAddress(var.dump()));
      }

      Response<std::vector<AssetAddress>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<AssetAddress>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<Asset>> CardanoApi::getAssetsByPolicy(std::string policy_id, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/assets/policy/"
      + policy_id
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Asset> obj = std::vector<Asset>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Asset(var.dump()));
      }

      Response<std::vector<Asset>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Asset>> response(obj, httpCode, err);
      return response;
    }
}

// Epochs

Response<Epoch> CardanoApi::getLatestEpoch()
{
    std::string url =
        basepath
      + "/epochs/latest";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Epoch obj;

    if (httpCode == 200) {
      obj = Epoch(output_string);
      Response<Epoch> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Epoch> response(obj, httpCode, err);
      return response;
    }
}

Response<ProtocolParams> CardanoApi::getLatestEpochProtocolParams()
{
    std::string url =
        basepath
      + "/epochs/latest/parameters";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    ProtocolParams obj;

    if (httpCode == 200) {
      obj = ProtocolParams(output_string);
      Response<ProtocolParams> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<ProtocolParams> response(obj, httpCode, err);
      return response;
    }
}

Response<Epoch> CardanoApi::getEpoch(int epoch_number)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Epoch obj;

    if (httpCode == 200) {
      obj = Epoch(output_string);
      Response<Epoch> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Epoch> response(obj, httpCode, err);
      return response;
    }
}

Response<ProtocolParams> CardanoApi::getEpochProtocolParams(int epoch_number)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/parameters";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    ProtocolParams obj;

    if (httpCode == 200) {
      obj = ProtocolParams(output_string);
      Response<ProtocolParams> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<ProtocolParams> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<Epoch>> CardanoApi::getNextEpochs(int epoch_number, int count, int page)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/next"
      + pagination(count, page);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Epoch> obj = std::vector<Epoch>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Epoch(var.dump()));
      }

      Response<std::vector<Epoch>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Epoch>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<Epoch>> CardanoApi::getPreviousEpochs(int epoch_number, int count, int page)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/previous"
      + pagination(count, page);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Epoch> obj = std::vector<Epoch>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Epoch(var.dump()));
      }

      Response<std::vector<Epoch>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Epoch>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<StakeDistribution>> CardanoApi::getEpochStake(int epoch_number, int count, int page)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/stakes"
      + pagination(count, page);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<StakeDistribution> obj = std::vector<StakeDistribution>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(StakeDistribution(var.dump()));
      }

      Response<std::vector<StakeDistribution>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<StakeDistribution>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolStakeDistribution>> CardanoApi::getEpochStakeByPool(int epoch_number, std::string pool_id, int count, int page)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/stakes/"
      + pool_id
      + pagination(count, page);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolStakeDistribution> obj = std::vector<PoolStakeDistribution>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolStakeDistribution(var.dump()));
      }

      Response<std::vector<PoolStakeDistribution>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolStakeDistribution>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<std::string>> CardanoApi::getEpochBlocks(int epoch_number, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/blocks"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<std::string> obj = std::vector<std::string>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(var.to_string());
      }

      Response<std::vector<std::string>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<std::string>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<std::string>> CardanoApi::getEpochBlocksByPool(int epoch_number, std::string pool_id, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/epochs/"
      + stringify(epoch_number)
      + "/blocks/"
      + pool_id
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<std::string> obj = std::vector<std::string>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(var.to_string());
      }

      Response<std::vector<std::string>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<std::string>> response(obj, httpCode, err);
      return response;
    }
}

// Ledger

Response<Genesis> CardanoApi::getLedgerGenesis()
{
    std::string url =
        basepath
      + "/genesis";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Genesis obj;

    if (httpCode == 200) {
      obj = Genesis(output_string);
      Response<Genesis> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Genesis> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TxMeta>> CardanoApi::getTxMetadataLabels(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/metadata/txs/labels"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TxMeta> obj = std::vector<TxMeta>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TxMeta(var.dump()));
      }

      Response<std::vector<TxMeta>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TxMeta>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TxMetaJSON>> CardanoApi::getTxMetadataByLabelJSON(std::string label, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/metadata/txs/labels/"
      + label
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TxMetaJSON> obj = std::vector<TxMetaJSON>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TxMetaJSON(var.dump()));
      }

      Response<std::vector<TxMetaJSON>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TxMetaJSON>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TxMetaCBOR>> CardanoApi::getTxMetadataByLabelCBOR(std::string label, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/metadata/txs/labels/"
      + label
      + "/cbor"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TxMetaCBOR> obj = std::vector<TxMetaCBOR>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TxMetaCBOR(var.dump()));
      }

      Response<std::vector<TxMetaCBOR>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TxMetaCBOR>> response(obj, httpCode, err);
      return response;
    }
}

// Network

Response<Network> CardanoApi::getNetworkInfo()
{
    std::string url =
        basepath
      + "/network";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Network obj;

    if (httpCode == 200) {
      obj = Network(output_string);
      Response<Network> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Network> response(obj, httpCode, err);
      return response;
    }
}

// Pools

Response<std::vector<std::string>> CardanoApi::listPools(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<std::string> obj = std::vector<std::string>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(var.to_string());
      }

      Response<std::vector<std::string>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<std::string>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolEpoch>> CardanoApi::listRetiredPools(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools/retired"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolEpoch> obj = std::vector<PoolEpoch>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolEpoch(var.dump()));
      }

      Response<std::vector<PoolEpoch>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolEpoch>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolEpoch>> CardanoApi::listRetiringPools(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools/retiring"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolEpoch> obj = std::vector<PoolEpoch>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolEpoch(var.dump()));
      }

      Response<std::vector<PoolEpoch>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolEpoch>> response(obj, httpCode, err);
      return response;
    }
}

Response<PoolInfo> CardanoApi::getPool(std::string pool_id)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    PoolInfo obj;

    if (httpCode == 200) {
      obj = PoolInfo(output_string);
      Response<PoolInfo> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<PoolInfo> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolHistory>> CardanoApi::getPoolHistory(std::string pool_id, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id
      + "/history"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolHistory> obj = std::vector<PoolHistory>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolHistory(var.dump()));
      }

      Response<std::vector<PoolHistory>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolHistory>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::pair<PoolMetadata, bool>> CardanoApi::getPoolMetadata(std::string pool_id)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id
      + "/metadata";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::pair<PoolMetadata, bool> obj = std::make_pair(PoolMetadata(), false);

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);
      if(!jsonPayload.is_null()) {
        obj = std::make_pair(PoolMetadata(output_string), true);
      }

      Response<std::pair<PoolMetadata, bool>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::pair<PoolMetadata, bool>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolRelay>> CardanoApi::getPoolRelays(std::string pool_id)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id
      + "/relays";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolRelay> obj = std::vector<PoolRelay>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolRelay(var.dump()));
      }

      Response<std::vector<PoolRelay>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolRelay>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolDelegator>> CardanoApi::getPoolDelegators(std::string pool_id, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id
      + "/delegators"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolDelegator> obj = std::vector<PoolDelegator>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolDelegator(var.dump()));
      }

      Response<std::vector<PoolDelegator>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolDelegator>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<std::string>> CardanoApi::getPoolBlocks(std::string pool_id, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id
      + "/blocks"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<std::string> obj = std::vector<std::string>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(var.to_string());
      }

      Response<std::vector<std::string>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<std::string>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<PoolUpdate>> CardanoApi::getPoolUpdates(std::string pool_id, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/pools/"
      + pool_id
      + "/updates"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<PoolUpdate> obj = std::vector<PoolUpdate>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(PoolUpdate(var.dump()));
      }

      Response<std::vector<PoolUpdate>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<PoolUpdate>> response(obj, httpCode, err);
      return response;
    }
}

// Scripts

Response<std::vector<Script>> CardanoApi::listScripts(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/scripts"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<Script> obj = std::vector<Script>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(Script(var.dump()));
      }

      Response<std::vector<Script>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<Script>> response(obj, httpCode, err);
      return response;
    }
}

Response<ScriptInfo> CardanoApi::getScript(std::string script_hash)
{
    std::string url =
        basepath
      + "/scripts/"
      + script_hash;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    ScriptInfo obj;

    if (httpCode == 200) {
      obj = ScriptInfo(output_string);
      Response<ScriptInfo> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<ScriptInfo> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<ScriptRedeemer>> CardanoApi::getScriptRedeemers(std::string script_hash, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/scripts/"
      + script_hash
      + "/redeemers"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<ScriptRedeemer> obj = std::vector<ScriptRedeemer>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(ScriptRedeemer(var.dump()));
      }

      Response<std::vector<ScriptRedeemer>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<ScriptRedeemer>> response(obj, httpCode, err);
      return response;
    }
}

Response<ScriptDatum> CardanoApi::getScriptDatum(std::string datum_hash)
{
    std::string url =
        basepath
      + "/scripts/datum/"
      + datum_hash;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    ScriptDatum obj;

    if (httpCode == 200) {
      obj = ScriptDatum(output_string);
      Response<ScriptDatum> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<ScriptDatum> response(obj, httpCode, err);
      return response;
    }
}

Response<ScriptJSON> CardanoApi::getScriptJSON(std::string script_hash)
{
    std::string url =
        basepath
      + "/scripts/"
      + script_hash
      + "/json";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    ScriptJSON obj;

    if (httpCode == 200) {
      obj = ScriptJSON(output_string);
      Response<ScriptJSON> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<ScriptJSON> response(obj, httpCode, err);
      return response;
    }
}

Response<ScriptCBOR> CardanoApi::getScriptCBOR(std::string script_hash)
{
    std::string url =
        basepath
      + "/scripts/"
      + script_hash
      + "/cbor";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    ScriptCBOR obj;

    if (httpCode == 200) {
      obj = ScriptCBOR(output_string);
      Response<ScriptCBOR> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<ScriptCBOR> response(obj, httpCode, err);
      return response;
    }
}

// Transactions

Response<Transaction> CardanoApi::getTx(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    Transaction obj;

    if (httpCode == 200) {
      obj = Transaction(output_string);
      Response<Transaction> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<Transaction> response(obj, httpCode, err);
      return response;
    }
}

Response<TransactionUtxos> CardanoApi::getTxUtxos(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/utxos";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    TransactionUtxos obj;

    if (httpCode == 200) {
      obj = TransactionUtxos(output_string);
      Response<TransactionUtxos> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<TransactionUtxos> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionRedeemer>> CardanoApi::getTxRedeemers(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/redeemers";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionRedeemer> obj = std::vector<TransactionRedeemer>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionRedeemer(var.dump()));
      }

      Response<std::vector<TransactionRedeemer>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionRedeemer>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionStake>> CardanoApi::getTxStakes(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/stakes";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionStake> obj = std::vector<TransactionStake>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionStake(var.dump()));
      }

      Response<std::vector<TransactionStake>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionStake>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionDelegation>> CardanoApi::getTxDelegations(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/delegations";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionDelegation> obj = std::vector<TransactionDelegation>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionDelegation(var.dump()));
      }

      Response<std::vector<TransactionDelegation>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionDelegation>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionWithdrawal>> CardanoApi::getTxWithdrawals(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/withdrawals";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionWithdrawal> obj = std::vector<TransactionWithdrawal>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionWithdrawal(var.dump()));
      }

      Response<std::vector<TransactionWithdrawal>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionWithdrawal>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionMir>> CardanoApi::getTxMirs(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/mirs";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionMir> obj = std::vector<TransactionMir>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionMir(var.dump()));
      }

      Response<std::vector<TransactionMir>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionMir>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionPoolUpdate>> CardanoApi::getTxPoolUpdates(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/pool_updates";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionPoolUpdate> obj = std::vector<TransactionPoolUpdate>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionPoolUpdate(var.dump()));
      }

      Response<std::vector<TransactionPoolUpdate>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionPoolUpdate>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionPoolRetiring>> CardanoApi::getTxPoolRetiring(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/pool_retires";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionPoolRetiring> obj = std::vector<TransactionPoolRetiring>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionPoolRetiring(var.dump()));
      }

      Response<std::vector<TransactionPoolRetiring>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionPoolRetiring>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionMetaJSON>> CardanoApi::getTxMetadataJSON(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/metadata";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionMetaJSON> obj = std::vector<TransactionMetaJSON>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionMetaJSON(var.dump()));
      }

      Response<std::vector<TransactionMetaJSON>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionMetaJSON>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<TransactionMetaCBOR>> CardanoApi::getTxMetadataCBOR(std::string tx_hash)
{
    std::string url =
        basepath
      + "/txs/"
      + tx_hash
      + "/metadata/cbor";

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<TransactionMetaCBOR> obj = std::vector<TransactionMetaCBOR>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(TransactionMetaCBOR(var.dump()));
      }

      Response<std::vector<TransactionMetaCBOR>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<TransactionMetaCBOR>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::string> CardanoApi::txSubmit(std::string content) {
    std::string url =
        basepath
      + "/tx/submit";

    begin(url);

    int httpCode = http.POST(reinterpret_cast<uint8_t*>(&content[0]), content.length());
    std::string output_string = http.getString().c_str();
    http.end();

    if (httpCode == 200) {
      Response<std::string> response(output_string, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::string> response(std::string(), httpCode, err);
      return response;
    };
}
