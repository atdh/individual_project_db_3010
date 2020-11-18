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
class superuser : public user
{
public:
    superuser()
    {
        userDeleted = false;
    }
    void options()
    {
        std::cout << "Choose an option" << std::endl;
        std::cout << "Option 1: Delete user(1)" << std::endl;
        std::cout << "Option 2: exit (2)" << std::endl;
    }
    void deleteUser()
    {
        std::string userToDelete = "";
        std::map<std::string, std::string>::iterator it;

        if (isAdmin == true)
        {
            std::cout << "Which user do you want to delete?" << std::endl;
            std::cin >> userToDelete;
            it = table.find(userToDelete);
            //if it finds the user before it reaches end of table,remove
            if (it != table.end())
            {
                table.erase(it);
            }

            //if ()
        }
    }

private:
    bool userDeleted;
};
