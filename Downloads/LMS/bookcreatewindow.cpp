#include "bookcreatewindow.h"
#include "ui_bookcreatewindow.h"

BookCreateWindow::BookCreateWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookCreateWindow)
{
    ui->setupUi(this);
        this->setWindowTitle("Create Books Window");
}

BookCreateWindow::~BookCreateWindow()
{
    delete ui;
}
