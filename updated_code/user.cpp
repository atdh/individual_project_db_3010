#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class user
{
public:
    user()
    {
        accessGranted = false;
    }
    void login()
    {
        std::cout << "Enter username" << std::endl;
        std::cin >> userAttempt;
        std::cout << "Enter Password: " << std::endl;
        std::cin >> passwordAttempt;
        readFile(userAttempt, passwordAttempt);

        //std::cout << it->first << it->second << std::endl;
        if (table[userAttempt] == passwordAttempt)
        {
            accessGranted = true;
            std::cout << "authenticated succesfully";
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
    void readFile(std::string userAttempt, std::string passwordAttempt)
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

    std::string writeFile(const char *fileName)
    {
        std::ofstream myfile;
        myfile.open("authentication.txt");
        myfile << "Writing to a file" << std::endl;
        myfile.close();
    }

    void signUp()
    {
        std::string username = "";
        std::string password = "";
        std::cout << "Signup Form" << std::endl;
        std::cout << "Enter new Username" << std::endl;
        std::cin >> username;
        std::cout << "Enter new password" << std::endl;
        std::cin >> password;
    }

private:
    std::string userAttempt;
    std::string passwordAttempt;
    std::string passWord;
    std::string userName;
    std::map<std::string, std::string> table;
    bool accessGranted = false;
};

int main()
{
    user logObj;
    logObj.login();
}