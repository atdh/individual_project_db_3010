#include "DB.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

Database::Database(std::string name, std::string path, OurStore* store) {
    this->name = name;
    this->path = path; 
    this->store = store;
}

Database Database::CreateEmpty(std::string name) {

    std::string basedir("./ourdb");
    if (!fs::exists(basedir)) {
        fs::create_directory(basedir);
    }

    std::string db_folder(basedir + "/" + name);
    if (!fs::exists(db_folder)) {
        fs::create_directory(db_folder);
    }

    OurStore* new_store = new OurStore();

    return Database(name, db_folder, new_store);
}

std::string Database::GetDir() {
    return this->path;
}

void Database::SetKV(std::string key, std::string val){
    this->store->SetKeyValue(key, val);
}

std::string Database::GetKV(std::string key) {
    return this->store->GetKeyValue(key);
}

void Database::PrintStoreCnts() {
    this->store->PrintContents();
}