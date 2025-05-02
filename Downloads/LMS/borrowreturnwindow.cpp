#include "borrowreturnwindow.h"
#include "ui_borrowreturnwindow.h"

BorrowReturnWindow::BorrowReturnWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BorrowReturnWindow)
{
    ui->setupUi(this);
        this->setWindowTitle("Borrow/Return Books Window");
}

BorrowReturnWindow::~BorrowReturnWindow()
{
    delete ui;
}
