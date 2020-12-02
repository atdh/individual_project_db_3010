#include <QtWidgets>
#include <QtTest/QtTest>
#include <loginwindow.h>
#include <dbwindow.h>
#include <logininterface.h>
#include <ui_loginwindow.h>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QtTest>

struct LoginResp;

//this allowed us to help change the window. It's a helper function.
void open_dbw(DBWindow* dbw_input) {
    dbw_input->show();
}

// this allows us to call the database window's fill user table
void fill_user_table(DBWindow* dbw_input) {
    dbw_input->FillUserTable();
}

// this allows us to call the database window's set_ui() method
// which will enable/disable certain ui components
// depending on whether the user is an admin
void set_up_ui_user(DBWindow* dbw_input) {
    dbw_input->set_ui();
}

// this allows us to the database window's AddMoreSignup() method
// which will add users to the user table when more than one person
// signs up
void add_new_user(DBWindow* dbw_input) {
    dbw_input->AddMoreSignup();
}

std::map<std::string, std::string> LoginInterface::table;
std::unordered_set<std::string> LoginInterface::admin_set;
bool LoginInterface::user_is_admin = false;
std::string LoginInterface::username = "";
std::string LoginInterface::password = "";

class TestLoginWindow: public QObject
{
    Q_OBJECT
public:
    TestLoginWindow() {
        dbw.set_partner(&lw);
        lw.set_partner(&dbw);
        lw.set_show_function(open_dbw);
        lw.set_fill_ut_function(fill_user_table);
        lw.set_set_ui_function(set_up_ui_user);
        lw.set_add_user_function(add_new_user);
    }
private:
    LoginWindow lw;
    DBWindow dbw;

private slots:
    void test_login_interface_login();
    void test_login_interface_login_data();
    void test_login_interface_writefile();
    void test_login_interface_writefile_data();

    void test_login();
    void test_login_data();
};

// this is the data function that provides the data
// to it test function "test_login_interface_login"
void TestLoginWindow::test_login_interface_login_data() {
    QTest::addColumn<QString>("test_username");
    QTest::addColumn<QString>("test_password");
    QTest::addColumn<LoginResp>("expected_lr");

    LoginResp expect_lr1;
    expect_lr1.succ = true;
    expect_lr1.is_admin = false;
    expect_lr1.adding_new_user = false;

    LoginResp expect_lr2;
    expect_lr2.succ = false;
    expect_lr2.is_admin = false;
    expect_lr2.body_info[0] = "User doesn't exist. Try again or";
    expect_lr2.body_info[1] = "sign up";
    expect_lr2.adding_new_user = false;

    LoginResp expect_lr3;
    expect_lr3.succ = true;
    expect_lr3.is_admin = true;
    expect_lr3.adding_new_user = false;

    LoginResp expect_lr4;
    expect_lr4.succ = false;
    expect_lr4.is_admin = false;
    expect_lr4.body_info[0] = "Incorrect password";
    expect_lr4.adding_new_user = false;

    QTest::newRow("valid non admin user") << "user1" << "pw1" << expect_lr1;
    QTest::newRow("invalid user")     << "i_user" << "i_pw" << expect_lr2;
    QTest::newRow("valid admin user") << "user2" << "pw2" << expect_lr3;
    QTest::newRow("wrong password") << "user1" << "i_pw1" << expect_lr4;
}

// this is the test function that tests the Login() method
// of the LoginInterface class
void TestLoginWindow::test_login_interface_login() {
    lw.li->table = {
      {"user1", "pw1"},
      {"user2", "pw2"},
      {"user3", "pw3"}
    };

    lw.li->admin_set = {"user2"};

    QFETCH(QString, test_username);
    QFETCH(QString, test_password);
    QFETCH(LoginResp, expected_lr);

    // we can compare two LoginResp to each other because the == operator was overloaded
    // in the struct LoginResp
    QCOMPARE(lw.li->Login(test_username.toLocal8Bit().constData(),
                          test_password.toLocal8Bit().constData()), expected_lr);
}

// this is the data function that provides the data
// to it test function "test_login_interface_writefile"
void TestLoginWindow::test_login_interface_writefile_data() {
    QTest::addColumn<QString>("test_username");
    QTest::addColumn<QString>("test_password");
    QTest::addColumn<LoginResp>("expected_lr");

    LoginResp expect_lr1;
    expect_lr1.succ = true;
    expect_lr1.is_admin = false;
    expect_lr1.body_info[0] = "";
    expect_lr1.body_info[1] = "";
    expect_lr1.adding_new_user = true;

    LoginResp expect_lr2;
    expect_lr2.succ = false;
    expect_lr2.is_admin = false;
    expect_lr2.body_info[0] = "User exists. Enter a new one or";
    expect_lr2.body_info[1] = "login";
    expect_lr2.adding_new_user = false;

    QTest::newRow("adding a unique user") << "user4" << "pw4" << expect_lr1;
    QTest::newRow("adding a nonunique user")     << "user1" << "pw1" << expect_lr2;
}

// this is the test function that tests the WriteFile() method
// of the LoginInterface class
void TestLoginWindow::test_login_interface_writefile() {
    lw.li->table = {
      {"user1", "pw1"},
      {"user2", "pw2"},
      {"user3", "pw3"}
    };

    QFETCH(QString, test_username);
    QFETCH(QString, test_password);
    QFETCH(LoginResp, expected_lr);

    QCOMPARE(lw.li->WriteFile(test_username.toLocal8Bit().constData(),
                          test_password.toLocal8Bit().constData()), expected_lr);
}

// this is the data function that provides data to its test function
// test_login
void TestLoginWindow::test_login_data() {
    QTest::addColumn<QTestEventList>("enter_user_event");
    QTest::addColumn<QTestEventList>("enter_password_event");
    QTest::addColumn<QTestEventList>("click_login");
    QTest::addColumn<bool>("DBWindow_visible");

    QTestEventList ue1;
    ue1.addKeyClicks("user1");
    QTestEventList pe1;
    pe1.addKeyClicks("pw1");
    QTestEventList cl1;
    cl1.addMouseClick(Qt::LeftButton);
    QTest::newRow("enter an existing user and password") << ue1 << pe1 << cl1 << true;

    QTestEventList ue2;
    ue2.addKeyClicks("i_user");
    QTestEventList pe2;
    pe2.addKeyClicks("i_pw");
    QTestEventList cl2;
    cl2.addMouseClick(Qt::LeftButton);
    QTest::newRow("enter an nonexisting user and password") << ue2 << pe2 << cl2 << false;

    QTestEventList ue3;
    ue3.addKeyClicks("user2");
    QTestEventList pe3;
    pe3.addKeyClicks("pw2");
    QTestEventList cl3;
    cl3.addMouseClick(Qt::LeftButton);
    QTest::newRow("enter an admin user and password") << ue3 << pe3 << cl3 << true;

    QTestEventList ue4;
    ue4.addKeyClicks("user1");
    QTestEventList pe4;
    pe4.addKeyClicks("i_pw1");
    QTestEventList cl4;
    cl4.addMouseClick(Qt::LeftButton);
    QTest::newRow("enter incorrect password") << ue4 << pe4 << cl4 << false;
}

// this test function tests multiple functionality of the process of logining
void TestLoginWindow::test_login() {
    lw.in_login_mode = true;

    lw.li->table = {
      {"user1", "pw1"},
      {"user2", "pw2"},
      {"user3", "pw3"}
    };

    lw.li->admin_set = {"user2"};

    QFETCH(QTestEventList, enter_user_event);
    QFETCH(QTestEventList, enter_password_event);
    QFETCH(QTestEventList, click_login);
    QFETCH(bool, DBWindow_visible);

    enter_user_event.simulate(lw.ui->lineEdit_username);
    enter_password_event.simulate(lw.ui->lineEdit_password);
    click_login.simulate(lw.ui->pushButton_login);

    QCOMPARE(lw.dbw_partner->isVisible(), DBWindow_visible);

    // need to make sure to reset some things for the next test case
    lw.dbw_partner->close();
    lw.ui->lineEdit_username->setText("");
    lw.ui->lineEdit_password->setText("");
}

QTEST_MAIN(TestLoginWindow)
#include "qt_tests.moc"
