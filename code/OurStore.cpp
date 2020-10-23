#include "OurStore.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <filesystem>
#include "BTree.h"

OurStore::OurStore() {
    this->max_file_size = 1000;
    this->total_entries = 0;
    bt = std::make_unique<BTree>(BTree(8));
}

unsigned long OurStore::CreateHash(std::string s) {
    unsigned long hash = 5381;

    for (int i = 0; i < (int)s.length(); i++) {
        hash = ((hash << 5) + hash) + (unsigned long)s[i]; 
    }

    return hash;
}

int OurStore::get_total_entries() {
    return this->total_entries;
}

void OurStore::incr_total_entries() {
    this->total_entries += 1;
}

void OurStore::CreateFile() {
    if (this->get_total_entries() % 14 == 0) {
        std::string filename= "file" + std::to_string(this->get_total_entries()) + ".txt";
        std::ofstream fout(filename);
        fout.fill (' ');
        fout.width (this->max_file_size);
        fout << " ";
    }

    return;
}

void checkFileSize() {
    std::cout << "foo" << std::endl;
    long size;
    FILE *f;
 
    f = fopen("testFile.txt", "rb");
    if (f == NULL) 
        return;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fclose(f);
 
    std::cout << "The size of the file is " << std::to_string(size) << std::endl;
}

void OurStore::SetKeyValue(std::string key, std::string value) {

    this->CreateFile();

    std::ofstream outfile;
    outfile.open("testFile.txt", std::ios::app);
    std::array<char, 32> key_arr = {0};
    std::array<char, 32> value_arr = {0};
    for (int i = 0; i < (int)key.size(); i++) {
        key_arr[i] = key[i];
    }
    for (int i = 0; i < (int)value.size(); i++) {
        value_arr[i] = value[i];
    }

    for (int i = 0; i < 32; i++) {
        outfile << key_arr[i];
    }

    for (int i = 0; i < 32; i++) {
        outfile << value_arr[i];
    }

    unsigned long hash = this->CreateHash(key);

    outfile << hash;

    outfile.close();
    checkFileSize();
    bt->insert(hash);

    this->incr_total_entries();
}

std::string OurStore::GetKeyValue(std::string key) {
    


}

