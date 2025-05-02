#ifndef BOOKCREATEWINDOW_H
#define BOOKCREATEWINDOW_H

#include <QDialog>

namespace Ui {
class BookCreateWindow;
}

class BookCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BookCreateWindow(QWidget *parent = nullptr);
    ~BookCreateWindow();

private:
    Ui::BookCreateWindow *ui;
};

#endif // BOOKCREATEWINDOW_H
