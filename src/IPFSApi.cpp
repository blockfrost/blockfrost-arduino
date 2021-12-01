#include "IPFSApi.h"

using namespace Blockfrost;

Response<std::vector<IPFSPin>> IPFSApi::listPins(int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/ipsf/list"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<IPFSPin> obj = std::vector<IPFSPin>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(IPFSPin(var.dump()));
      }

      Response<std::vector<IPFSPin>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<IPFSPin>> response(obj, httpCode, err);
      return response;
    }
}

Response<IPFSPin> IPFSApi::getPin(std::string ipfs_path)
{
    std::string url =
        basepath
      + "/ipfs/list/"
      + ipfs_path;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    IPFSPin obj;

    if (httpCode == 200) {
      obj = IPFSPin(output_string);
      Response<IPFSPin> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<IPFSPin> response(obj, httpCode, err);
      return response;
    }
}

Response<IPFSPinChange> IPFSApi::addPin(std::string ipfs_path)
{
    std::string url =
        basepath
      + "/ipfs/pin/add/"
      + ipfs_path;

    begin(url);

    int httpCode = http.POST(nullptr, 0);
    std::string output_string = http.getString().c_str();
    http.end();
    IPFSPinChange obj;

    if (httpCode == 200) {
      obj = IPFSPinChange(output_string);
      Response<IPFSPinChange> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<IPFSPinChange> response(obj, httpCode, err);
      return response;
    }
}

Response<IPFSPinChange> IPFSApi::removePin(std::string ipfs_path)
{
    std::string url =
        basepath
      + "/ipfs/pin/remove/"
      + ipfs_path;

    begin(url);

    int httpCode = http.POST(nullptr, 0);
    std::string output_string = http.getString().c_str();
    http.end();
    IPFSPinChange obj;

    if (httpCode == 200) {
      obj = IPFSPinChange(output_string);
      Response<IPFSPinChange> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<IPFSPinChange> response(obj, httpCode, err);
      return response;
    }
}
