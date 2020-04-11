#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileIconProvider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Might prevent freeze
    QFileIconProvider *fileIconProvider = new QFileIconProvider();
    fileIconProvider->setOptions(QFileIconProvider::DontUseCustomDirectoryIcons);

    // Column view part
    model = new QFileSystemModel(this);
    model->setRootPath(QDir::rootPath());
    model->setResolveSymlinks(true);
    model->setReadOnly(false);
    model->setFilter(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::AllDirs |
                     QDir::System);
    model->setIconProvider(fileIconProvider);

    QColumnView *columnView = ui->columnView;
//    columnView->setMinimumHeight(sizeCol);
    columnView->setModel(model);
    // tree->setRootIndex(model->index(QDir::currentPath()));
    columnView->setCurrentIndex(model->index(QDir::currentPath()));
    // columnView->setRootIndex());
//    QItemSelectionModel *itSel = columnView->selectionModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

