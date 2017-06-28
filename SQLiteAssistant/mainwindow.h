#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QStringList>
#include <iostream>
#include <QFileDialog>
#include "tablecreation.h"
#include "edittable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getDbName();

private slots:
    void lookIntoDB();

    void on_button_table_clicked();

    void on_insertData_clicked();

    void on_chooseButton_clicked();

    void on_actionAbout_triggered();

    void on_button_dbCreation_clicked();

private:
    Ui::MainWindow *ui;
    QAction *lookDb;
    void createMenu();
    void createActions();
    QString database_name;
    QString db_path;
};

#endif // MAINWINDOW_H
