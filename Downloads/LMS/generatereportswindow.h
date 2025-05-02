#ifndef GENERATEREPORTSWINDOW_H
#define GENERATEREPORTSWINDOW_H

#include <QDialog>

namespace Ui {
class GenerateReportsWindow;
}

class GenerateReportsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GenerateReportsWindow(QWidget *parent = nullptr);
    ~GenerateReportsWindow();

private:
    Ui::GenerateReportsWindow *ui;
};

#endif // GENERATEREPORTSWINDOW_H
