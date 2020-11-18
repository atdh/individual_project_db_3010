#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QString>
#include <QtDebug>
#include <QDialog>
#include "databasebst.h"

// this class is the base class of the get, post, put, and delete dialog classes
// I decided to use inheritance since it saved on having to repeatedly create the
// members, such as key and value, and the methods, such as set_key() and set_value()
// for every single dialog class
class MyDialog {
private:
    std::string api_type;
    std::string key;
    std::string value;

    std::vector<char> key_vec;
    std::vector<char> value_vec;
public:
    static DatabaseBST* db;
    MyDialog(std::string input_type);
    void set_key(std::string input_key);
    std::string get_key();
    void set_value(std::string input_value);
    std::string get_value();
    std::string get_api_type();

    std::vector<char> get_key_vec();
    std::vector<char> get_value_vec();
    void fill_key_value_vecs();
    void reset_key_value_vecs();
    virtual Response DoRequest() { return Response(); };
};


#endif // MYDIALOG_H
