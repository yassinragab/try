#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr, QWidget *loginWindow = nullptr);
    ~AdminWindow();

private slots:
    void on_addUserButton_clicked();
    void on_deleteUserButton_clicked();
    void on_backButton_clicked();  // <<< Added back button slot

private:
    Ui::AdminWindow *ui;
    void updateUserList();
    QWidget *previousWindow;  // <<< Store the previous window
};

#endif // ADMINWINDOW_H
