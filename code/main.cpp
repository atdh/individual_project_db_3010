#include <iostream>
#include "ourdb.h"

int main() {
    std::string new_name = "new_db";

    try {
        Database db(OurDB::CreateDB(new_name));
        std::cout << "Successfully created the database" << std::endl;
    }
        
    catch (int x) {
        std::cout << "there was some error";
    }
}