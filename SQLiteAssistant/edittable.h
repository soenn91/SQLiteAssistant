#ifndef EDITTABLE_H
#define EDITTABLE_H

#include <QDialog>
#include <QStringList>
#include <QtSql>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QObject>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QList>

namespace Ui {
class EditTable;
}

class EditTable : public QDialog
{
    Q_OBJECT
    QWidget *centralWidget;

public:
    explicit EditTable(QWidget *parent = 0, QString dbName = " ");
    ~EditTable();

private slots:
    //void on_selectT_activated(QString tbName);
    void displayInput(QString tbName);
    void close();

private:
    Ui::EditTable *ui;
    void createMenu();
    //insertData(QString tbName, std::vector<QLabel*> labels, std::vector<QLineEdit*> edits);
    QString m_dbName;
    QString m_dbPath;
    QComboBox *selectT;
    QFormLayout *formLayout;    //table selection
    QFormLayout *formL;     //input data cols
    QVBoxLayout *mainLayout;
    QString _tbName;
    QDialogButtonBox *acceptButton;
    QSqlDatabase _mydb;
    std::vector<QLineEdit*> _copyEdits;
    std::vector<QString*> _varTypeList;
    //QList<>

};

#endif // EDITTABLE_H
