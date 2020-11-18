#ifndef DIALOGFACTORY_H
#define DIALOGFACTORY_H
#include <QDialog>

enum REST_TYPE {
    GET, POST, PUT, DELETE
};


class DialogFactory
{
public:
    DialogFactory();

    static QDialog* Create(REST_TYPE input_type);
};

#endif // DIALOGFACTORY_H
