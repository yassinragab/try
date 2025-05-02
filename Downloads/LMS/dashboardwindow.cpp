#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

#include "BookCreateWindow.h"  // Include BookCreateWindow
#include "ViewBooksWindow.h"   // Include ViewBooksWindow
#include "BorrowReturnWindow.h"  // Include BorrowReturnWindow
#include "GenerateReportsWindow.h"  // Include GenerateReportsWindow

DashboardWindow::DashboardWindow(const QString &usernameInput, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    setWindowTitle("Dashboard Window");

    ui->welcomeLabel->setText("Welcome, " + usernameInput);

    updateStatistics(150, 40, 8);

    connect(ui->createBookButton, &QPushButton::clicked, this, &DashboardWindow::onCreateBookClicked);
    connect(ui->viewBooksButton, &QPushButton::clicked, this, &DashboardWindow::onViewBooksClicked);
    connect(ui->borrowReturnButton, &QPushButton::clicked, this, &DashboardWindow::onBorrowReturnClicked);
    connect(ui->generateReportsButton, &QPushButton::clicked, this, &DashboardWindow::onGenerateReportsClicked);
}

void DashboardWindow::updateStatistics(int totalBooks, int borrowedBooks, int overdueBooks)
{
    ui->totalBooksLabel->setText("Total Books: " + QString::number(totalBooks));
    ui->borrowedBooksLabel->setText("Borrowed Books: " + QString::number(borrowedBooks));
    ui->overdueBooksLabel->setText("Overdue Books: " + QString::number(overdueBooks));
}


DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::onViewBooksClicked()
{
    // Hide the dashboard window
    this->hide();

    // Create and show the ViewBooksWindow
    ViewBooksWindow *viewBooksWindow = new ViewBooksWindow();
    viewBooksWindow->show();
}

void DashboardWindow::onBorrowReturnClicked()
{
    // Hide the dashboard window
    this->hide();

    // Create and show the BorrowReturnWindow
    BorrowReturnWindow *borrowReturnWindow = new BorrowReturnWindow();
    borrowReturnWindow->show();
}

void DashboardWindow::onGenerateReportsClicked()
{
    // Hide the dashboard window
    this->hide();

    // Create and show the GenerateReportsWindow
    GenerateReportsWindow *generateReportsWindow = new GenerateReportsWindow();
    generateReportsWindow->show();
}
void DashboardWindow::onCreateBookClicked()
{
    // Hide the dashboard window
    this->hide();

    // Create and show the BookCreateWindow
    BookCreateWindow *createBookWindow = new BookCreateWindow();
    createBookWindow->show();
}
