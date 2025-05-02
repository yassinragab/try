#ifndef VIEWBOOKSWINDOW_H
#define VIEWBOOKSWINDOW_H

#include <QDialog>

namespace Ui {
class ViewBooksWindow;
}

class ViewBooksWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewBooksWindow(QWidget *parent = nullptr);
    ~ViewBooksWindow();

private:
    Ui::ViewBooksWindow *ui;
};

#endif // VIEWBOOKSWINDOW_H
