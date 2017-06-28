#include "edittable.h"
#include "ui_edittable.h"

EditTable::EditTable(QWidget *parent, QString dbName) :
    QDialog(parent),
    ui(new Ui::EditTable)
{
    ui->setupUi(this);
    m_dbPath = dbName;

    formL = new QFormLayout;
    acceptButton = new QDialogButtonBox(QDialogButtonBox::Ok);
    mainLayout = new QVBoxLayout;
    selectT = new QComboBox;
    createMenu();

    formLayout = new QFormLayout();
    formLayout->addRow(tr("&Choose Table:"), selectT);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(acceptButton);
    setLayout(mainLayout);

    connect(acceptButton, SIGNAL(accepted()), this, SLOT(close()));
    QObject::connect(selectT, SIGNAL(activated(QString)),
                     this, SLOT(displayInput(QString)));
}


EditTable::~EditTable()
{
    delete ui;
}

void EditTable::createMenu()
{
    _mydb = QSqlDatabase::addDatabase("QSQLITE","myDb3");
    _mydb.setDatabaseName(m_dbPath);
    _mydb.open();

    QString all = "select * from sqlite_master";
    QSqlQuery query(all, _mydb);
    //query.exec();

    QStringList _list;
    while (query.next())
    {
           if (query.value(0).toString() == "table")
           {
                _list.append(query.value(1).toString());
           }
    }
    _mydb.close();
    selectT->addItem(" ");
    for(int i=0; i< _list.size(); i++)
    {
        selectT->addItem(_list[i]);
    }
}


void EditTable::displayInput(QString tbName)
{
    _tbName = tbName;
    //_colNames.clear();

    while (QLayoutItem *item = formL->takeAt(0)) {
            delete item->widget();
            delete item;
    }

    //delete _lineEditList.at(i);

    _mydb.open();

    QString all = "pragma table_info(" + _tbName + ")";
    QSqlQuery query(all, _mydb);
    //query.exec();

    QList<QLabel*> _labelsList;
    std::vector<QLineEdit*> _lineEditList;
    std::vector<QString> _colNames;
    while (query.next())
    {
        QString colName = query.value(1).toString();
        QString varType = query.value(2).toString();
        QLabel *tmp = new QLabel(colName + " (" + varType + ")");
        QLineEdit *tmpEdit = new QLineEdit;
        _colNames.push_back(colName);
        QString *varTmp = new QString(varType);
        _varTypeList.push_back(varTmp);
        _lineEditList.push_back(tmpEdit);
        _labelsList.append(tmp);
    }

    if(_labelsList.size()>0)
    {
        for(int i = 0; i < _labelsList.size(); i++)
        {
         formL->addRow(_labelsList.at(i), _lineEditList.at(i));
        }
    }
    _mydb.close();
    mainLayout->removeWidget(acceptButton);
    mainLayout->removeItem(formL);
    mainLayout->addLayout(formL);
    mainLayout->addWidget(acceptButton);
    _copyEdits = _lineEditList;
}

void EditTable::close()
{
    int size_edits = _copyEdits.size();
    int i = 0;
    QString values;

    while(size_edits > i)
    {
        values = values + "'" + _copyEdits.at(i)->text() + "'";
        if(size_edits <= (i+1))     // there is no 'next'
        {   
            values = values + ")";
        } else {        // there is a 'next'
            if(_copyEdits.at(i+1)->text().isEmpty())     // empty 'next'
            {
                values = values + ")";
            }
            else {
            values = values + ", ";
            }
        }
        i++;
    }
    QString all = "insert into " + _tbName + " values " + "(" + values;
    //qDebug() << all;
    _mydb.open();
    QSqlQuery query(all, _mydb);
    _mydb.close();
    accept();
}
