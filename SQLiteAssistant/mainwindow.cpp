#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lookIntoDB()
{
    QMessageBox msgBox;
    msgBox.setText("Everything working");
    msgBox.exec();

}

void MainWindow::on_button_table_clicked()
{
    tableCreation _tableCreation(0, db_path);
    _tableCreation.setModal(true);
    _tableCreation.exec();
}

QString MainWindow::getDbName()
{
    return database_name;
}


void MainWindow::on_insertData_clicked()
{
    EditTable _editTable(0, db_path);
    _editTable.setModal(true);
    _editTable.exec();
}

void MainWindow::on_chooseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Open File"),
                                                      QDir::homePath(),
                                                      ("db (*.sqlite)"));
    QString path = QDir::toNativeSeparators(fileName);
    //qDebug() << path.indexOf("sqlite");
    int index = path.indexOf("sqlite");
    QString dbTmp;
    for(int i=index -2 ; i > 0; i--)
    {
        if(path[i] == '\\')
        {
            break;
        } else {
        dbTmp.insert(0, path[i]);
        }
    }
    //qDebug() << dbTmp;
    database_name = dbTmp;
    db_path = path;
    QSqlDatabase _mydb = QSqlDatabase::addDatabase("QSQLITE","myDb");
    //_mydb = QSqlDatabase::addDatabase("QSQLITE");

    _mydb.setDatabaseName(path);
    if(!_mydb.open())
    {
        ui->label->setText("Could not connect to database");
    } else
    {
        ui->label->setText("Database selected: " + database_name);
    }
    _mydb.close();
    //QSqlDatabase::removeDatabase("qt_sql_default_connection");
    //QSqlDatabase::removeDatabase("myDb");

}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("About");
    msgBox.setText("SQLite Assistant.\nv.0.1.0\nCreated by Adrian Anton.\nadrisoenn@gmail.com");
    msgBox.exec();
}


void MainWindow::on_button_dbCreation_clicked()
{
    QFileDialog *dialog = new QFileDialog;
    //dialog->setFileMode(QFileDialog::AnyFile);
    QString strFile = dialog->getSaveFileName(NULL, "Create New SQLite db","","");
    dialog->setLabelText(QFileDialog::Accept, "Create db");
    dialog->setLabelText(QFileDialog::Reject, "Cancel");
    QString file_name = strFile + ".sqlite";
    QFile file(file_name);
    file.open(QIODevice::WriteOnly);
    file.close();
}
