#include <iostream>
#include <QString>
#include "mydialog.h"
#include "getdialog.h"
#include "postdialog.h"

MyDialog::MyDialog(std::string input_key) {
    set_key(input_key);
    reset_key_value_vecs();
}

// this assumes that the key and value are set
void MyDialog::fill_key_value_vecs() {
    for (int i = 0; i < (int)key.size(); i++)
    {
        key_vec[i] = key[i];
    }
    for (int i = 0; i < (int)value.size(); i++)
    {
        value_vec[i] = value[i];
    }
}

std::vector<char> MyDialog::get_key_vec() {
    return key_vec;
}

std::vector<char> MyDialog::get_value_vec() {
    return value_vec;
}

// we reset the key and value vecs because it gives us a clean slate
// to work with in order to handle the next REST api request
void MyDialog::reset_key_value_vecs() {
    key_vec.clear();
    value_vec.clear();

    for (int i = 0; i < 32; i++) {
        key_vec.push_back('$');
        value_vec.push_back('$');
    }
}

void MyDialog::set_key(std::string input_key) {
    this->key = input_key;
}

std::string MyDialog::get_key() {
    return this->key;
}

void MyDialog::set_value(std::string input_value) {
    this->value = input_value;
}

std::string MyDialog::get_value() {
    return this->value;
}

std::string MyDialog::get_api_type() {
    return this->api_type;
}


