#include "deletedialog.h"
#include "ui_deletedialog.h"

//delete button on database ui
DeleteDialog::DeleteDialog(std::string input_type, QWidget *parent) :
    QDialog(parent),
    MyDialog(input_type),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    ui->pushButton->setText("Submit");
    ui->textEdit->setPlaceholderText("Insert a key");
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_pushButton_clicked()
{
    //this is so the placholder for the button can be read without errors. We are getting th etexts in the textedit
    //ui componenet and converting it to a string
    std::string key_str = ui->textEdit->toPlainText().toLocal8Bit().constData();
    set_key(key_str);

    Response r = DoRequest();
    //sends the signal to delete
    emit SendDelRes(r);
}
//this gets called so that it actually does the delete operation
Response DeleteDialog::DoRequest()
{
    Node* temp_root = db->get_root();
    unsigned long hash = db->CreateHash(get_key());
    Node* temp_node = db->SearchNode(temp_root, hash);

    if (temp_node != NULL)
    {
        std::string value = db->ConvertToStr(temp_node->value);
        db->set_root(db->Delete(temp_root, hash));

        Response r(true, "Found key in database. Deleting it");
        r.delete_key = QString::fromStdString(get_key());

        return r;
    } else {
        return Response(false, "Error. Key doesn't exist");
    }
}

