#include "Common.h"

using namespace Blockfrost;

URLVersion::URLVersion()
{
  url = std::string();
  version = std::string();
}

URLVersion::URLVersion(std::string jsonString)
{
  this->fromJson(jsonString);
}

URLVersion::~URLVersion()
{
}

void
URLVersion::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(url, "std::string");
    fromJSON(version, "std::string");
}

bourne::json
URLVersion::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(url);
    toJSON(version);

    return object;
}

// Health

Health::Health()
{
  is_healthy = false;
}

Health::Health(std::string jsonString)
{
  this->fromJson(jsonString);
}

Health::~Health()
{
}

void
Health::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(is_healthy, "bool");
}

bourne::json
Health::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(is_healthy);

    return object;
}

// ServerTime

ServerTime::ServerTime()
{
  server_time = int64_t(0);
}

ServerTime::ServerTime(std::string jsonString)
{
  this->fromJson(jsonString);
}

ServerTime::~ServerTime()
{
}

void
ServerTime::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(server_time, "int64_t");
}

bourne::json
ServerTime::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(server_time);

    return object;
}

// Metric

Metric::Metric()
{
  time = time_t(0);
  calls = int(0);
}

Metric::Metric(std::string jsonString)
{
  this->fromJson(jsonString);
}

Metric::~Metric()
{
}

void
Metric::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(time, "time_t");
    fromJSON(calls, "int");
}

bourne::json
Metric::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(time);
    toJSON(calls);

    return object;
}

// Metric endpoint

MetricEndpoint::MetricEndpoint()
{
  time = time_t(0);
  calls = int(0);
  endpoint = std::string();
}

MetricEndpoint::MetricEndpoint(std::string jsonString)
{
  this->fromJson(jsonString);
}

MetricEndpoint::~MetricEndpoint()
{
}

void
MetricEndpoint::fromJson(std::string jsonObj)
{
    bourne::json object = bourne::json::parse(jsonObj);

    fromJSON(time, "time_t");
    fromJSON(calls, "int");
    fromJSON(endpoint, "std::string");
}

bourne::json
MetricEndpoint::toJson()
{
    bourne::json object = bourne::json::object();

    toJSON(time);
    toJSON(calls);
    toJSON(endpoint);

    return object;
}
