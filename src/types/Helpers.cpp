#include "Helpers.h"
#include <string>
#include <sstream>

bool isprimitive(std::string type){
  if(type == "std::string" ||
    type == "int" ||
    type == "int64_t" ||
    type == "float" ||
    type == "long" ||
    type == "double" ||
    type == "bool" ||
    type == "std::map" ||
    type == "std::list")
    {
    return true;
  }
  return false;
}

std::string stringify(long input){
    std::stringstream stream;
    stream << input;
    return stream.str();
};

std::string stringify(int input){
  std::stringstream stream;
  stream << input;
  return stream.str();
};

std::string stringify(double input){
  std::stringstream stream;
  stream << input;
  return stream.str();
};

std::string stringify(float input){
  std::stringstream stream;
  stream << input;
  return stream.str();
};

std::string stringify(std::string input){
  std::stringstream stream;
  stream << input;
  return stream.str();
};

bool jsonToValueMay(void* target, std::string key, bourne::json const object, std::string type)
{
  bourne::json value = object[key];
  if (value.is_null()) {
    return false;
  }
  else if (type.compare("bool") == 0) 
  {
    bool* val = static_cast<bool*> (target);
    *val = value.to_bool();
  }
  else if (type.compare("int") == 0)
  {
    int* val = static_cast<int*> (target);
    *val = value.to_int();
  }
  else if (type.compare("int64_t") == 0)
  {
    int64_t* val = static_cast<int64_t*> (target);
    *val = value.to_int();
  }
  else if (type.compare("time_t") == 0)
  {
    time_t* val = static_cast<time_t*> (target);
    *val = value.to_int();
  }

  else if (type.compare("float") == 0)
  {
    float* val = static_cast<float*> (target);
    *val = (float)(value.to_float());
  }
  else if (type.compare("long") == 0)
  {
    long* val = static_cast<long*> (target);
    *val = (long)(value.to_int());
  }
  else if (type.compare("double") == 0)
  {
    double* val = static_cast<double*> (target);
    *val = value.to_float();
  }
  else if (type.compare("std::string") == 0) 
  {
    std::string* val = static_cast<std::string*> (target);
    *val = value.to_string();
  }
  else {
    return false;
  }
  return true;
}

void jsonToValue(void* target, std::string key, bourne::json const object, std::string type)
{
  jsonToValueMay(target, key, object, type);
}

std::string pagination(int count, int page) {
  return
    "?count="
      + stringify(count)
      + "&page="
      + stringify(page);
}
std::string paginationOrder(int count, int page, std::string order) {
  return
    "?count="
      + stringify(count)
      + "&page="
      + stringify(page)
      + "&order="
      + order;
}
