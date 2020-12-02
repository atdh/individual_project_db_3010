#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <array>

struct LoginResp {
    bool succ; // a boolean indicating whether the user logged in successfully
    bool is_admin; // assuming that the user successfully logged in, a boolean indicating whether user is an admin
    std::array<std::string, 2> body_info;
    std::string new_user;
    std::string new_password;
};

class LoginInterface
{
public:
    static bool user_is_admin;
    static std::string username;
    static std::string password;
    LoginInterface();
    LoginResp Login(std::string user_attempt, std::string password_attempt);
    static void ReadFile();
    void SignUp();
    LoginResp WriteFile(std::string write_user, std::string write_password);
    static void DeleteUserFromFile(std::string user_name);
    static std::map<std::string, std::string> table;
    static std::unordered_set<std::string> admin_set;
};

#endif // USER_H
