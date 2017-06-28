#include "tablecreation.h"
#include "ui_tablecreation.h"
#include <QGridLayout>
#include <QWidget>
#include <QMenuBar>
#include <QMessageBox>
#include <QSignalMapper>

tableCreation::tableCreation(QWidget *parent, QString dbName) :
    QDialog(parent),
    ui(new Ui::tableCreation)
{
    ui->setupUi(this);
    m_dbPath = dbName;
    createMenu();
    indexCol1 = 0;
    indexCol2 = 0;
    indexCol3 = 0;
    indexCol4 = 0;
    indexCol5 = 0;
    indexCol6 = 0;
    indexCol7 = 0;
    indexCol8 = 0;
}

tableCreation::~tableCreation()
{
    delete ui;
}

void tableCreation::createMenu()
{
    ui->variableType1->addItem("INT");
    ui->variableType1->addItem("TEXT");
    ui->variableType1->addItem("BLOB");
    ui->variableType1->addItem("REAL");
    ui->variableType1->addItem("NUMERIC");

    ui->variableType2->addItem("INT");
    ui->variableType2->addItem("TEXT");
    ui->variableType2->addItem("BLOB");
    ui->variableType2->addItem("REAL");
    ui->variableType2->addItem("NUMERIC");

    ui->variableType3->addItem("INT");
    ui->variableType3->addItem("TEXT");
    ui->variableType3->addItem("BLOB");
    ui->variableType3->addItem("REAL");
    ui->variableType3->addItem("NUMERIC");

    ui->variableType4->addItem("INT");
    ui->variableType4->addItem("TEXT");
    ui->variableType4->addItem("BLOB");
    ui->variableType4->addItem("REAL");
    ui->variableType4->addItem("NUMERIC");

    ui->variableType5->addItem("INT");
    ui->variableType5->addItem("TEXT");
    ui->variableType5->addItem("BLOB");
    ui->variableType5->addItem("REAL");
    ui->variableType5->addItem("NUMERIC");

    ui->variableType6->addItem("INT");
    ui->variableType6->addItem("TEXT");
    ui->variableType6->addItem("BLOB");
    ui->variableType6->addItem("REAL");
    ui->variableType6->addItem("NUMERIC");

    ui->variableType7->addItem("INT");
    ui->variableType7->addItem("TEXT");
    ui->variableType7->addItem("BLOB");
    ui->variableType7->addItem("REAL");
    ui->variableType7->addItem("NUMERIC");

    ui->variableType8->addItem("INT");
    ui->variableType8->addItem("TEXT");
    ui->variableType8->addItem("BLOB");
    ui->variableType8->addItem("REAL");
    ui->variableType8->addItem("NUMERIC");

    //QMenu *trialMenu = new QMenu(this);
    //trialMenu->addAction(trialAction);
    //ui->variableType1->setMenu(trialMenu);

}

void tableCreation::on_acceptButton_clicked()
{
   QString tableName = ui->inputTbName->text();
   QString _colNames[8];
   _colNames[0] = ui->inputCol1->text();
   _colNames[1] = ui->inputCol2->text();
   _colNames[2] = ui->inputCol3->text();
   _colNames[3] = ui->inputCol4->text();
   _colNames[4] = ui->inputCol5->text();
   _colNames[5] = ui->inputCol6->text();
   _colNames[6] = ui->inputCol7->text();
   _colNames[7] = ui->inputCol8->text();
   QString _dataTypes[8];
   _dataTypes[0] = decideType(indexCol1);
   _dataTypes[1] = decideType(indexCol2);
   _dataTypes[2] = decideType(indexCol3);
   _dataTypes[3] = decideType(indexCol4);
   _dataTypes[4] = decideType(indexCol5);
   _dataTypes[5] = decideType(indexCol6);
   _dataTypes[6] = decideType(indexCol7);
   _dataTypes[7] = decideType(indexCol8);

   int num_cols = 0;
   for(int i = 0; i < 8; i++)
   {
        if(_colNames[i].size() > 0)
        {
            num_cols++;
        }
   }
   QString primaryKey[8] = {};
   for (int i=0; i < 7 ; i++)
   {
       switch(i){
       case 0:
           if(ui->priKey_1->isChecked()){
               primaryKey[i] = "PRIMARY KEY";
           }
           break;
        case 1:
           if(ui->priKey_2->isChecked()){
               primaryKey[i] = "PRIMARY KEY";
           }
           break;
        case 2:
           if(ui->priKey_3->isChecked()){
               primaryKey[i] = "PRIMARY KEY";
           }
           break;
       case 3:
          if(ui->priKey_4->isChecked()){
              primaryKey[i] = "PRIMARY KEY";
          }
          break;
       case 4:
          if(ui->priKey_5->isChecked()){
              primaryKey[i] = "PRIMARY KEY";
          }
          break;
       case 5:
          if(ui->priKey_6->isChecked()){
              primaryKey[i] = "PRIMARY KEY";
          }
          break;
       case 6:
          if(ui->priKey_7->isChecked()){
              primaryKey[i] = "PRIMARY KEY";
          }
          break;
       case 7:
          if(ui->priKey_8->isChecked()){
              primaryKey[i] = "PRIMARY KEY";
          }
          break;
       }
   }
   QSqlDatabase _mydb = QSqlDatabase::addDatabase("QSQLITE","myDb2");
   _mydb.setDatabaseName(m_dbPath);
   _mydb.open();

   //QSqlQuery query;
   QString prep;
   for(int i = 0; i < num_cols; i++)
   {
        prep = prep + _colNames[i] + " " + _dataTypes[i];
        if(primaryKey[i].size() > 0)
        {
            prep = prep + " " + primaryKey[i];
        }
        if (num_cols - i <= 1)
        {
            prep = prep + ")";
        } else
        {
            prep = prep + ",";
        }
   }
   QString all = "CREATE TABLE " + tableName + " (" + prep;
   QSqlQuery query(all, _mydb);
   query.exec();
   _mydb.close();
   //QSqlDatabase::removeDatabase("qt_sql_default_connection");
   this->close();
}

QString tableCreation::decideType(int index)
{
    switch (index) {
    case 0:
        return "INT";
        break;
    case 1:
        return "TEXT";
        break;
    case 2:
        return "BLOB";
        break;
    case 3:
        return "REAL";
        break;
    case 4:
        return "NUMERIC";
        break;
    default:
        return " ";
        break;
    }
}

void tableCreation::on_variableType5_activated(int index)
{
    indexCol5 = index;
}

void tableCreation::on_variableType1_activated(int index)
{
    indexCol1 = index;
}

void tableCreation::on_variableType2_activated(int index)
{
    indexCol2 = index;
}

void tableCreation::on_variableType3_activated(int index)
{
    indexCol3 = index;
}

void tableCreation::on_variableType4_activated(int index)
{
    indexCol4 = index;
}

void tableCreation::on_variableType6_activated(int index)
{
    indexCol6 = index;
}

void tableCreation::on_variableType7_activated(int index)
{
    indexCol7 = index;
}

void tableCreation::on_variableType8_activated(int index)
{
    indexCol8 = index;
}
