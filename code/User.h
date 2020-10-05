/*
class User
methods:
SetUsername(std::string name)
Description: sets the user’s username
GetUsername()
Description: gets the user’s username
MakeApiRequest(std::string api_call)
Description: make an api call, which will in turn call the corresponding Microsoft cpp REST SDK method

*/
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <map>

class User
{
public:
    User(std::string name);
    void SetUserName(std::string name, int id);
    std::string GetUserName();
    void MakeApiRequest(std::string api_call);

private:
    std::string name;
    int id;
};

#endif
