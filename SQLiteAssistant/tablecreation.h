#ifndef TABLECREATION_H
#define TABLECREATION_H

#include <QDialog>
#include <QMenuBar>
#include <QMenu>
#include <QtSql>
#include "mainwindow.h"

namespace Ui {
class tableCreation;
}

class tableCreation : public QDialog
{
    Q_OBJECT

public:
    explicit tableCreation(QWidget *parent = 0, QString dbName = " ");
    ~tableCreation();

private slots:

    void on_acceptButton_clicked();

    void on_variableType5_activated(int index);

    void on_variableType1_activated(int index);

    void on_variableType2_activated(int index);

    void on_variableType3_activated(int index);

    void on_variableType4_activated(int index);

    void on_variableType6_activated(int index);

    void on_variableType7_activated(int index);

    void on_variableType8_activated(int index);

private:
    Ui::tableCreation *ui;
    void createMenu();
    int indexCol1;
    int indexCol2;
    int indexCol3;
    int indexCol4;
    int indexCol5;
    int indexCol6;
    int indexCol7;
    int indexCol8;
    QString m_dbName;
    QString m_dbPath;
    QString decideType(int index);
};

#endif // TABLECREATION_H
