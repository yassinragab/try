#include "generatereportswindow.h"
#include "ui_generatereportswindow.h"

GenerateReportsWindow::GenerateReportsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GenerateReportsWindow)
{
    ui->setupUi(this);
        this->setWindowTitle("Reports Window");
}

GenerateReportsWindow::~GenerateReportsWindow()
{
    delete ui;
}
