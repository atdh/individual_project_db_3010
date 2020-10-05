#include "OurStore.h"
#include <string>
#include <map>

void OurStore::SetKeyValue(std::string key, std::string value) {
    this->hash_map.insert(std::pair<std::string, std::string>(key, value));
}

std::string OurStore::GetKeyValue(std::string key) {
    return this->hash_map.at(key);
}

void OurStore::PrintContents() {
    std::map<std::string, std::string>::iterator itr; 
    std::cout << "\nThe contents of the database: \n"; 
    std::cout << "Keys\tValues\n";

    for (itr = this->hash_map.begin(); itr != hash_map.end(); ++itr) { 
        std::cout << itr->first 
            << "\t"
            << itr->second << '\n'; 
    } 
}