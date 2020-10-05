#ifndef OURDB_H
#define OURDB_H
#include <string>
#include "db.h"

class OurDB {
    public:
        OurDB ();
        static Database CreateDB(std::string name);
};

#endif  // OURDB_H