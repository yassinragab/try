#ifndef BORROWRETURNWINDOW_H
#define BORROWRETURNWINDOW_H

#include <QDialog>

namespace Ui {
class BorrowReturnWindow;
}

class BorrowReturnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowReturnWindow(QWidget *parent = nullptr);
    ~BorrowReturnWindow();

private:
    Ui::BorrowReturnWindow *ui;
};

#endif // BORROWRETURNWINDOW_H
