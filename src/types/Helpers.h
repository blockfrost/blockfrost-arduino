#ifndef BLOCKFROST_CPP_CLIENT_HELPERS_H_
#define BLOCKFROST_CPP_CLIENT_HELPERS_H_

#include <string>
#include "bourne/json.hpp"

bool isprimitive(std::string type);

void jsonToValue(void* target, std::string key, bourne::json const object, std::string type);
bool jsonToValueMay(void* target, std::string key, bourne::json const object, std::string type);

#define fromJSON(var, typ) jsonToValue(&var, #var, object, typ);
#define fromJSONMay(var, typ) var.second = jsonToValueMay(&var.first, #var, object, typ);

#define toJSON(var) object[#var] = var;
#define toJSONMay(var) if(var.second) { object[#var] = var.first; } else { object[#var] = nullptr; }

std::string stringify(long input);

std::string stringify(int input);

std::string stringify(double input);

std::string stringify(float input);

std::string stringify(std::string input);

std::string pagination(int count, int page);
std::string paginationOrder(int count, int page, std::string order);

#endif /* BLOCKFROST_CPP_CLIENT_HELPERS_H_ */

