#ifndef DIALOGFACTORY_H
#define DIALOGFACTORY_H
#include <QDialog>

enum REST_TYPE {
    GET, POST, PUT, DELETE
};

// I'm using the factory design pattern in order to hide
// how we create each individual REST api dialog
class DialogFactory
{
public:
    DialogFactory();

    // this is the method that takes in the REST type and returns the corresponding dialog object
    static QDialog* Create(REST_TYPE input_type);
};

#endif // DIALOGFACTORY_H
