#include "CommonApi.h"

using namespace Blockfrost;

Response<URLVersion>
  CommonApi::getRoot()
{
  begin(basepath + "/");
  int httpCode = http.GET();
  URLVersion obj(http.getString().c_str());
  http.end();

  Response<URLVersion> response(obj, httpCode);
  return response;
}

Response<Health>
  CommonApi::getHealth()
{
  std::string url = basepath + "/health";
  begin(url);
  int httpCode = http.GET();
  Health obj(http.getString().c_str());
  http.end();

  Response<Health> response(obj, httpCode);
  return response;
}

Response<ServerTime>
  CommonApi::getClock()
{
  std::string url = basepath + "/health/clock";
  begin(url);
  int httpCode = http.GET();
  ServerTime obj(http.getString().c_str());
  http.end();

  Response<ServerTime> response(obj, httpCode);
  return response;
}

Response<std::vector<Metric>>
  CommonApi::getMetrics()
{
  std::string url = basepath + "/metrics";
  begin(url);
  int httpCode = http.GET();

  bourne::json jsonPayload = bourne::json::parse(http.getString().c_str());
  http.end();
  std::vector<Metric> vec = std::vector<Metric>();
  for(auto& var : jsonPayload.array_range())
  {
      Metric tmp(var.dump());
      vec.push_back(tmp);
  }

  Response<std::vector<Metric>> response(vec, httpCode);
  return response;
}

Response<std::vector<MetricEndpoint>>
  CommonApi::getMetricsEndpoints()
{
  std::string url = basepath + "/metrics/endpoints";
  begin(url);
  int httpCode = http.GET();

  bourne::json jsonPayload = bourne::json::parse(http.getString().c_str());
  http.end();
  std::vector<MetricEndpoint> vec = std::vector<MetricEndpoint>();
  for(auto& var : jsonPayload.array_range())
  {
      MetricEndpoint tmp(var.dump());
      vec.push_back(tmp);
  }

  Response<std::vector<MetricEndpoint>> response(vec, httpCode);
  return response;
}


