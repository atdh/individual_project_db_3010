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

struct LoginResp {
    bool succ; // a boolean indicating whether the user logged in successfully
    bool is_admin; // assuming that the user successfully logged in, a boolean indicating whether user is an admi
};

class LoginInterface
{
public:
    LoginInterface();
    LoginResp Login(std::string user_attempt, std::string password_attempt);
    void ReadFile();
    void SignUp();
    void WriteFile(std::string write_user, std::string write_password);

private:
    std::string write_password;
    std::string write_user;
    std::map<std::string, std::string> table;
    std::unordered_set<std::string> admin_set;
};

#endif // USER_H
