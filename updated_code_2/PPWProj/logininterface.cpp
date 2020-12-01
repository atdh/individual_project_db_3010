#include "logininterface.h"
#include <QDir>
#include <QtDebug>

LoginInterface::LoginInterface()
{

}
//FIrst we check to see if  the username exixts. If the username exists and the password matches, then we login accordingly.
//We make sure to keep track of whether the user is admin or not as well
LoginResp LoginInterface::Login(std::string user_attempt, std::string password_attempt) {
    LoginResp login_resp;
    password = password_attempt;
    //if it finds correct user name and password user logged in succesfully
    if (table.count(user_attempt) == 1)
    {
        if (table[user_attempt] == password_attempt) {
            login_resp.succ = true;

            //if its an admin then I will print options that the admin has
            if (admin_set.find(user_attempt) != admin_set.end())
            {
                std::cout << "\nHas admin access" << std::endl;
                login_resp.is_admin = true;
                this->user_is_admin = login_resp.is_admin;
            } else {
                login_resp.is_admin = false;
                this->user_is_admin = login_resp.is_admin;
            }

            return login_resp;
        } else {
            std::cout << "wrong password" << std::endl;
            login_resp.succ = false;
            login_resp.is_admin = false;
            this->user_is_admin = login_resp.is_admin;
            return login_resp;
        }
    }
    else
    {
        std::cout << "user doesn't exist" << std::endl;
        login_resp.succ = false;
        login_resp.is_admin = false;
        this->user_is_admin = login_resp.is_admin;
        return login_resp;
    }
}

// we need to use the QDir::currentPath() method in order to help us
// get the full path of where the data and storage files are
std::string GetFilePath(std::string file_name)
{
    std::string str_file_path = QDir::currentPath().toLocal8Bit().constData();
    str_file_path += "/" + file_name;
    qDebug() << QString::fromStdString(str_file_path);
    return str_file_path;
}

//We are reading the file line by line and adding the data from the file into the table hash map as well for O(1) seach time
void LoginInterface::ReadFile() {
    std::ifstream fileName;
    //reading do in
    fileName.open(GetFilePath("authentication.txt"), std::ios::in);
    std::string line = "";
    std::string username = "";
    std::string password = "";
    std::string admin_marker = "";
    //file pointer
    while (fileName >> username >> password >> admin_marker)
    {
//        std::cout << username << "," << password << "," << admin_marker << std::endl;
        table.insert(std::pair<std::string, std::string>(username, password));
        if (admin_marker == "a") {
            admin_set.insert(username);
        }
    }
    fileName.close();
}
//First we check to see if user exists in the table. If the user exists then we show error message
//and ask to come up with a difft username. If it's a unique user, we append to the end of the file
//andupdate our table map accordingly
LoginResp LoginInterface::WriteFile(std::string write_user, std::string write_password)
{
    std::fstream myfile;
    myfile.open(GetFilePath("authentication.txt"), std::fstream::app);

    LoginResp login_resp;

    bool unique_user = true;

    for (std::map<std::string, std::string>::iterator it = table.begin(); it != table.end(); it++)
    {
        if (it->first == write_user)
        {
            std::cout << "User exists. Come up with new name" << std::endl;
            unique_user = false;
            login_resp.succ = false;
            login_resp.is_admin = false;
            myfile.close();

            return login_resp;
        }
    }

    if (unique_user == true) {
        myfile << write_user << " " << write_password << " " << "$";
    }

    myfile.close();

    login_resp.succ = true;
    login_resp.is_admin = false;

    return login_resp;
}

//deleting users from file. We check if the username that the admin wants to delete exists first and then delete accordingly.
void LoginInterface::DeleteUserFromFile(std::string full_line) {
    std::string deleteline;
    std::string line;

    std::ifstream fin;
    fin.open(GetFilePath("authentication.txt"));
    std::ofstream temp;
    temp.open(GetFilePath("temp.txt"));

    while (getline(fin,line))
    {
        if (line.find(full_line) == std::string::npos) {
            temp << line << std::endl;
        }
    }

    temp.close();
    fin.close();
    remove("authentication.txt");
    rename("temp.txt","authentication.txt");
}
