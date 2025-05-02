#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include "AdminWindow.h"
#include "DashboardWindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
    this->setWindowTitle("Login Window");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::handleLogin()
{
    QString enteredUsername = ui->usernameInput->text();
    QString enteredPassword = ui->passwordInput->text();

    // Hardcoded admin check
    if (enteredUsername == "a" && enteredPassword == "123") {

        AdminWindow *admin = new AdminWindow(nullptr, this);  // <<< FIXED: pass this
        admin->show();
        this->hide();
        return;
    }

    // Check users.txt for regular users
    bool found = false;
    QFile file("users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            QStringList parts = line.split(",");
            if (parts.size() >= 2) {
                QString username = parts[0];
                QString password = parts[1];

                if (enteredUsername == username && enteredPassword == password) {
                    found = true;
                    break;
                }
            }
        }
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Unable to open users file.");
        return;
    }

    if (found) {
        DashboardWindow *dashboard = new DashboardWindow(enteredUsername);
        dashboard->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
