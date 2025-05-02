#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QDialog>

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DashboardWindow(const QString &usernameInput, QWidget *parent = nullptr);
    ~DashboardWindow();

    void updateStatistics(int totalBooks, int borrowedBooks, int overdueBooks);

private slots:
    void onCreateBookClicked();       // For Create New Book button
    void onViewBooksClicked();        // For View Books button
    void onBorrowReturnClicked();     // For Borrow/Return Books button
    void onGenerateReportsClicked();  // For Generate Reports button


private:
    Ui::DashboardWindow *ui;
};

#endif // DASHBOARDWINDOW_H
