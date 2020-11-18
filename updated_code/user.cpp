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
    //user constructor that initializes the boolean accessgranted and isadmin to false. accessgranted will be true if succefully
    //logged in. isAdmin will be true if a proper credential for an admin is identified. isadmin will be superuser class
    //if isadmin then they can delete tables
    user()
    {
        accessGranted = false;
        isAdmin = false;
    }
    //logs in.if not succesful then gives option to try again or sign up
    void login()
    {
        std::cout << "Enter username" << std::endl;
        std::cin >> userAttempt;
        std::cout << "Enter Password: " << std::endl;
        std::cin >> passwordAttempt;

        //reads file and puts things in hash table as it does so
        readFile();
        //std::cout << it->first << it->second << std::endl;

        //if it finds correct user name and password user logged in succesfully
        if (table[userAttempt] == passwordAttempt)
        {
            accessGranted = true;
            std::cout << "authenticated succesfully";

            //if its an admin then I will print options that the admin has
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
            /*if (choice == 3)
            {
                exit;
            }*/
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
        //exit;
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

    //protected:
    bool isAdmin = false;
    std::map<std::string, std::string> table;

    //private:
    std::string userAttempt;
    std::string passwordAttempt;
    std::string writePassword;
    std::string writeUser;
    bool accessGranted = false;
};