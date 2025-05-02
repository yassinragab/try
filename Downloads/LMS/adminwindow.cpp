#include "adminwindow.h"
#include "ui_adminwindow.h"

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QMessageBox>
#include <QListWidgetItem>

AdminWindow::AdminWindow(QWidget *parent, QWidget *loginWindow) :
    QDialog(parent),
    ui(new Ui::AdminWindow),
    previousWindow(loginWindow)  // <<< save the previous window
{
    ui->setupUi(this);
    setWindowTitle("Admin Window");

    updateUserList();  // load users when opening
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_addUserButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString role = ui->roleComboBox->currentText();

    QRegularExpression re("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8}$");
    if (!re.match(password).hasMatch()) {
        QMessageBox::warning(this, "Invalid Password", "Password must be exactly 8 characters and include both letters and numbers.");
        return;
    }

    QFile file("users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open users file.");
        return;
    }

    QTextStream out(&file);
    out << username << "," << password << "," << role << "\n";
    file.close();

    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
    updateUserList();
}

void AdminWindow::updateUserList()
{
    ui->userListWidget->clear();
    QFile file("users.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            ui->userListWidget->addItem(line);
        }
        file.close();
    }
}

void AdminWindow::on_deleteUserButton_clicked()
{
    QListWidgetItem *selected = ui->userListWidget->currentItem();
    if (!selected) {
        QMessageBox::warning(this, "No Selection", "Please select a user to delete.");
        return;
    }

    QString toDelete = selected->text();
    QFile file("users.txt");
    QFile tempFile("temp.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text) &&
        tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {

        QTextStream in(&file);
        QTextStream out(&tempFile);

        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line != toDelete)
                out << line << "\n";
        }

        file.close();
        tempFile.close();

        file.remove();
        tempFile.rename("users.txt");
        updateUserList();
    }
}

void AdminWindow::on_backButton_clicked()
{
    if (previousWindow) {
        previousWindow->show();   // <<< show login window again
    }
    this->close();  // <<< close admin window
}
