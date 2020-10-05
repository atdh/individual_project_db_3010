#include "OurDB.h"
#include <iostream>

OurDB::OurDB() {

}

Database OurDB::CreateDB(std::string name) {
    return Database::CreateEmpty(name);
}