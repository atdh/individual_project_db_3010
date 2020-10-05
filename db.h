#ifndef DB_H
#define DB_H
#include <string>

class Database {
    public:
        Database(std::string name, std::string path);

        static Database CreateEmpty(std::string name);

        std::string get_dir();

    protected:
        std::string name;
        std::string path;
};

#endif  // DB_H