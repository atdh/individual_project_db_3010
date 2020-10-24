/*
class Superuser (derived from the Base class, User)
methods:
RemoveUser(std::string name)
Description: removes a User
DeleteDB()
Description: deletes the database
*/
#ifndef SUPERUSER_H
#define SUPERUSER_H
#include <iostream>
#include <string>
#include <map>

class SuperUser : public User
{
public:
    SuperUser(std::string name);
    User(GetUserName()) {} //test
    void RemoveUser(std::string name, int id);
    void DeleteDB(std::string name);

private:
    std::string name;
    int id;
};

#endif
