#include "NutLinkApi.h"

using namespace Blockfrost;

Response<NutLinkAddress>
  NutLinkApi::nutlinkListAddress(std::string address)
{
    std::string url =
        basepath
      + "/nutlink/"
      + address;

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();
    NutLinkAddress obj;

    if (httpCode == 200) {
      obj = NutLinkAddress(output_string);
      Response<NutLinkAddress> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<NutLinkAddress> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<NutLinkAddressTicker>>
  NutLinkApi::nutlinkListAddressTickers(std::string address, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/nutlink/"
      + address
      + "/tickers"
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<NutLinkAddressTicker> obj = std::vector<NutLinkAddressTicker>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(NutLinkAddressTicker(var.dump()));
      }

      Response<std::vector<NutLinkAddressTicker>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<NutLinkAddressTicker>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<NutLinkTicker>>
  NutLinkApi::nutlinkAddressTickers(std::string address, std::string ticker, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/nutlink/"
      + address
      + "/tickers/"
      + ticker
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<NutLinkTicker> obj = std::vector<NutLinkTicker>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(NutLinkTicker(var.dump()));
      }

      Response<std::vector<NutLinkTicker>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<NutLinkTicker>> response(obj, httpCode, err);
      return response;
    }
}

Response<std::vector<NutLinkTickerAddress>>
  NutLinkApi::nutlinkTickers(std::string ticker, int count, int page, std::string order)
{
    std::string url =
        basepath
      + "/nutlink/tickers/"
      + ticker
      + paginationOrder(count, page, order);

    begin(url);

    int httpCode = http.GET();
    std::string output_string = http.getString().c_str();
    http.end();

    std::vector<NutLinkTickerAddress> obj = std::vector<NutLinkTickerAddress>();

    if (httpCode == 200) {

      bourne::json jsonPayload = bourne::json::parse(output_string);

      for(auto& var : jsonPayload.array_range())
      {
          obj.push_back(NutLinkTickerAddress(var.dump()));
      }

      Response<std::vector<NutLinkTickerAddress>> response(obj, httpCode);
      return response;
    } else {
      Error err = Error(output_string);
      Response<std::vector<NutLinkTickerAddress>> response(obj, httpCode, err);
      return response;
    }
}
