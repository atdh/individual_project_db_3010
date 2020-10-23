#ifndef OURSTORE_H
#define OURSTORE_H
#include <iostream>
#include <string>
#include <map>
#include "BTree.h"
#include <memory>

class OurStore
{
    public:
        OurStore();
        void SetKeyValue(std::string key, std::string value);
        std::string GetKeyValue(std::string key);
        void CreateFile();
        int get_total_entries();
        void incr_total_entries();
        unsigned long CreateHash(std::string s);

    private:
        std::unique_ptr<BTree> bt;
        int max_file_size;
        int total_entries;
};

#endif // OURSTORE_H
