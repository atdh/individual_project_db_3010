#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    //split string into username, password pair and store them in map and access this via map.find(). I dont need to tore the map for more than the duration of the login process so i can discard the map
    map<string, string> table;

    ifstream myFile;
    myFile.open("info.txt");
    string line = "";
    string username = "";
    string password = "";
    //file pointer
    while (myFile >> username >> password)
    {
        cout << username << "," << password << endl;
        table.insert(std::pair<string, std::string>(username, password));
    }
    myFile.close();

    for (map<string, string>::iterator it = table.begin(); it != table.end(); it++)
    {
        cout << it->first << it->second << endl;
    }

    return 0;
}

/*
        map.find(input username) == input password.
        if (userAttempt == userName)
        {
            std::cout << "Password: " << std::endl;
            std::cin >> passwordAttempt;
            if (passwordAttempt == passWord)
            {
                accessGranted = true;
                std::cout << "Succesful!" << std::endl;
            }
            else
            {
                int choice = 0;
                std::cout << "You have not made an account or incorrect password" << std::endl;
                std::cout << "Retry attempt(1)";
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
        else
        {
            int choice = 0;
            std::cout << "You have not made an account or incorrect username" << std::endl;
            std::cout << "Retry attempt(1)";
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
}*/
