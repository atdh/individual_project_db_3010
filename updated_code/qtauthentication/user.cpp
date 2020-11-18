#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

class user
{
public:
    user()
    {
        accessGranted = false;
        isAdmin = false;
    }
    void login()
    {
        std::cout << "Enter username" << std::endl;
        std::cin >> userAttempt;
        std::cout << "Enter Password: " << std::endl;
        std::cin >> passwordAttempt;
        readFile();
        //std::cout << it->first << it->second << std::endl;
        if (table[userAttempt] == passwordAttempt)
        {
            accessGranted = true;
            std::cout << "authenticated succesfully";
            if (userAttempt == "donald" && passwordAttempt == "trump")
            {
                std::cout << "\nHas admin access" << std::endl;
                isAdmin = true;
            }
        }
        else
        {
            int choice = 0;
            std::cout << "You have not made an account or incorrect password" << std::endl;
            std::cout << "Retry attempt(1)" << std::endl;
            std::cout << "Signup (2)" << std::endl;
            std::cout << "Exit program(3)" << std::endl;
            std::cin >> choice;

            if (choice == 1)
            {
                login();
            }
            if (choice == 2)
            {
                signUp();
            }
            if (choice == 3)
            {
                exit;
            }
        }
    }
    void readFile()
    {

        std::ifstream fileName;
        //reading do in
        fileName.open("authentication.txt", std::ios::in);
        std::string line = "";
        std::string username = "";
        std::string password = "";
        //file pointer
        while (fileName >> username >> password)
        {
            //std::cout << username << "," << password << std::endl;
            table.insert(std::pair<std::string, std::string>(username, password));
        }
        fileName.close();
    }
    void signUp()
    {

        std::string writeUser = "";
        std::string writePassword = "";

        std::cout << "Signup Form" << std::endl;
        std::cout << "Enter new Username" << std::endl;
        std::cin >> writeUser;
        std::cout << "************" << std::endl;
        for (std::map<std::string, std::string>::iterator it = table.begin(); it != table.end(); it++)
        {
            if (it->first == writeUser)
            {
                std::cout << "User exists. Come up with new name" << std::endl;
                signUp();
            }
        }

        std::cout << "Enter new password" << std::endl;
        std::cin >> writePassword;

        writeFile(writeUser, writePassword);
        std::cout << "Signed up succesfully." << std::endl;
        std::cout << "Run the program again" << std::endl;
        exit;
    }

    void writeFile(std::string writeUser, std::string writePassword)
    {
        std::fstream myfile;
        myfile.open("authentication.txt", std::fstream::app);
        myfile << '\n' + writeUser << " " << writePassword;
    }
    //make an api call, which will in turn call the
    //corresponding Microsoft cpp REST SDK method void
    void makeAPIRequest();

protected:
    bool isAdmin = false;
    std::map<std::string, std::string> table;

private:
    std::string userAttempt;
    std::string passwordAttempt;
    std::string writePassword;
    std::string writeUser;
    bool accessGranted = false;
};

// int main()
// {
//     user logObj;
//     logObj.login();
// }
