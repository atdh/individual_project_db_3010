#include "dialogfactory.h"
#include "getdialog.h"
#include "postdialog.h"
#include "putdialog.h"
#include "deletedialog.h"

DialogFactory::DialogFactory()
{

}

// creates the corresponding REST api dialog based on what the input REST_TYPE
QDialog* DialogFactory::Create(REST_TYPE input_type) {
    if (input_type == REST_TYPE::GET) {
        return new GetDialog("GET");
    } else if (input_type == REST_TYPE::POST) {
        return new PostDialog("POST");
    } else if (input_type == REST_TYPE::PUT) {
        return new PutDialog("PUT");
    } else if (input_type == REST_TYPE::DELETE) {
        return new DeleteDialog("DELETE");
    }
}
