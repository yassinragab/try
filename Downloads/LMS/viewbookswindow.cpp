#include "viewbookswindow.h"
#include "ui_viewbookswindow.h"

ViewBooksWindow::ViewBooksWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewBooksWindow)
{
    ui->setupUi(this);
        this->setWindowTitle("View Books Window");
}

ViewBooksWindow::~ViewBooksWindow()
{
    delete ui;
}
