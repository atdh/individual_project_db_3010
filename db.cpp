#include "db.h"
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

Database::Database(std::string name, std::string path) {
    this->name = name;
    this->path = path; 
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

    return Database(name, db_folder);
}

std::string Database::get_dir() {
    return "some directory";
}