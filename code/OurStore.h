#ifndef OURSTORE_H
#define OURSTORE_H
#include <iostream>
#include <string>
#include <map>

class OurStore
{
public:
    void SetKeyValue(std::string key, std::string value);
    std::string GetKeyValue(std::string key);
    void PrintContents();

private:
    std::string key;
    std::string value;
    std::map<std::string, std::string> hash_map;
};

#endif // OURSTORE_H
