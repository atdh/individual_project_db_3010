#include "logininterface.h"
#include <QDir>
#include <QtDebug>

LoginInterface::LoginInterface()
{

}

LoginResp LoginInterface::Login(std::string user_attempt, std::string password_attempt) {
    LoginResp login_resp;
    // user_attempt and password_attempt will come from the text fields of the ui
    ReadFile();
    //if it finds correct user name and password user logged in succesfully
//    if (table[user_attempt] == password_attempt)
//    {
//        login_resp.succ = true;

//        //if its an admin then I will print options that the admin has
//        if (admin_set.find(user_attempt) != admin_set.end())
//        {
//            std::cout << "\nHas admin access" << std::endl;
//            login_resp.is_admin = true;
//        } else {
//            login_resp.is_admin = false;
//        }

//        return login_resp;
//    }
//    else
//    {
//        std::cout << "lala";
//        login_resp.succ = false;
//        login_resp.is_admin = false;
//        return login_resp;
//    }
    login_resp.succ = true;
    login_resp.is_admin = true;
    return login_resp;
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
