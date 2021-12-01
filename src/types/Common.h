/*
 * Common.h
 *
 */

#ifndef BLOCKFROST_CPP_CLIENT_Common_H_
#define BLOCKFROST_CPP_CLIENT_Common_H_

#include <ctime>
#include <string>
#include "bourne/json.hpp"
#include "Helpers.h"

namespace Blockfrost {

/*! \brief
 *
 *  \ingroup Models
 *
 */

class URLVersion{
public:

    // \brief Constructor.
    URLVersion();
    URLVersion(std::string jsonString);

    // \brief Destructor.
    virtual ~URLVersion();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    std::string url;
    std::string version;
};

class Health{
public:

    // \brief Constructor.
    Health();
    Health(std::string jsonString);

    // \brief Destructor.
    virtual ~Health();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    bool is_healthy;
};

class ServerTime{
public:

    // \brief Constructor.
    ServerTime();
    ServerTime(std::string jsonString);

    // \brief Destructor.
    virtual ~ServerTime();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    int64_t server_time;
};

class Metric{
public:

    // \brief Constructor.
    Metric();
    Metric(std::string jsonString);

    // \brief Destructor.
    virtual ~Metric();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    time_t time;
    int calls;
};

class MetricEndpoint{
public:

    // \brief Constructor.
    MetricEndpoint();
    MetricEndpoint(std::string jsonString);

    // \brief Destructor.
    virtual ~MetricEndpoint();

    // \brief Retrieve a bourne JSON representation of this class.
    bourne::json toJson();

    // \brief Fills in members of this class from bourne JSON object representing it.
    void fromJson(std::string jsonObj);

    time_t time;
    int calls;
    std::string endpoint;
};



}

#endif /* BLOCKFROST_CPP_CLIENT_Common_H_ */
