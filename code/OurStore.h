#ifndef OURSTORE_H
#define OURSTORE_H
#include <iostream>
#include <string>
#include <map>

class OurStore
{
public:
    void setKeyValue(std::string key, std::string value);
    std::string getKeyValue(std::string key);

private:
    std::string key;
    std::string value;
    std::map<std::string, int> hash_map;
};

#endif
