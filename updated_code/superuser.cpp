#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include "user.cpp"

//super user can delete users from file
//super user can log in

/*
Holders of the DBA privilege can perform the following functions: Execute the DROP DATABASE, START DATABASE, and ROLLFORWARD DATABASE statements. Drop or alter any object regardless of who owns it. Create tables, views, and indexes to be owned by other users. Grant database privileges, including the DBA privilege, to another user.
*/
class superuser : public user
{
public:
    superuser()
    {
        userDeleted = false;
    }

    void options()
    {
        std::string choice = "";
        std::cout << "Choose an option" << std::endl;
        //
        std::cout << "Option 1: Delete user(1)" << std::endl;
        std::cout << "Option 2: Post Request(2)" << std::endl;
        std::cout << "Option 3: Get Request(3)" << std::endl;
        std::cout << "Option 4: Put Request(4)" << std::endl;
        std::cout << "Option 5: Delete key(5)" << std::endl;

        //add = post request
        //get shit get request
        std::cin >> choice;
        if (choice == "1")
        {
            deleteUser();
        }
    }
    void deleteUser()
    {
        std::cout << "debug check" << std::endl;
        std::string userToDelete = "";
        std::map<std::string, std::string>::iterator it;

        if (isAdmin == true)
        {
            for (std::map<std::string, std::string>::iterator it = table.begin(); it != table.end(); it++)
            {
                std::cout << it->first << std::endl;
            }

            std::cout << "Which user do you want to delete?" << std::endl;
            std::cin >> userToDelete;

            std::cout << "Deleting " + userToDelete << std::endl;
            std::cout << "\n";

            it = table.find(userToDelete);
            //if it finds the user before it reaches end of table,remove
            if (it != table.end())
            {
                table.erase(it);
            }

            for (std::map<std::string, std::string>::iterator it = table.begin(); it != table.end(); it++)
            {
                std::cout << it->first << std::endl;
            }

            //if ()
        }
    }

private:
    bool userDeleted;
};

int main()
{
    superuser logObj;
    logObj.login();
    if (logObj.isAdmin == true)
    {
        logObj.options();
    }
}