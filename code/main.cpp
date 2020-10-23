#include <iostream>
#include "OurDB.h"


int main() {
    std::string new_name = "new_db";

    try {
        Database db(OurDB::CreateDB(new_name));
        std::cout << "Successfully created the database" << std::endl;

        std::string user_input_key;
        std::string user_input_value;

        for (int i = 0; i < 2; i++) {
            std::cout << "Please enter a key" << std::endl;
            std::cin >> user_input_key;
            std::cout << "Please enter a value"  << std::endl;
            std::cin >> user_input_value;

            db.SetKV(user_input_key, user_input_value);
        }

    }
        
    catch (int x) {
        std::cout << "There was some error";
    }
}