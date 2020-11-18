#include "dialogfactory.h"
#include "getdialog.h"
#include "postdialog.h"

DialogFactory::DialogFactory()
{

}

QDialog* DialogFactory::Create(REST_TYPE input_type) {
    if (input_type == REST_TYPE::GET) {
        return new GetDialog("GET");
    } else if (input_type == REST_TYPE::POST) {
        return new PostDialog("POST");
    }
}
