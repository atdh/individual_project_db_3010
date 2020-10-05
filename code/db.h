#ifndef DB_H
#define DB_H
#include <string>
#include "OurStore.h"

class Database {
    public:
        Database(std::string name, std::string path, OurStore* store);

        static Database CreateEmpty(std::string name);

        std::string GetDir();

        void SetKV(std::string key, std::string val);
        std::string GetKV(std::string key);
        void PrintStoreCnts();

    private:
        std::string name;
        std::string path;
        OurStore* store;
};

#endif  // DB_H