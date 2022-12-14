#include "name.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlError>
#include<QDebug>
//int j=0,k=0;
//int n=0,m=0;

name::name(QObject *parent) : QObject(parent)
{

}
name::name(const QString &path)
{
 db=QSqlDatabase::addDatabase("QSQLITE");
 db.setDatabaseName(path);
 if(!db.open())
 {
     qDebug()<<"error"<<"\n";
 }
 else
 {
     qDebug()<<"ok"<<"\n";
 }
}
name::~name()
{
    if(db.isOpen())
    {
        db.close();
    }
}
bool name::isOpen() const
{
    return db.isOpen();
}
bool name::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE delta(name TEXT, Emp_id TEXT, Contact TEXT, dob TEXT,Skills TEXT,Desigination TEXT,Address TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'delta': one might already exist.";
        success = false;
    }

    return success;
}

bool name::addPerson(const QString&name,const QString& Emp_id,const QString& Contact,const QString& dob,
                     const QString& Skills,const QString& Desigination,const QString& Address )
{
    bool success = false;

    removePerson(Emp_id);
    if (!name.isEmpty()||!Emp_id.isEmpty()||!Contact.isEmpty()|| !dob.isEmpty() || !Skills.isEmpty()|| !Desigination.isEmpty() || !Address.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO delta (Emp_id,name,Contact,dob,Skills,Desigination,Address) VALUES (:Emp_id,:name,:Contact,:dob,:Skills,:Desigination,:Address) ");
        queryAdd.bindValue(":Emp_id", Emp_id);
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":Contact", Contact);
        queryAdd.bindValue(":dob", dob);
        queryAdd.bindValue(":Skills", Skills);
        queryAdd.bindValue(":Desigination", Desigination);
        queryAdd.bindValue(":Address", Address);

        if(queryAdd.exec())
        {
//            if(n==1 || m==1)
//            {
            success = true;
            }
//      }
        else
        {
            qDebug() << "add persons failed: " << queryAdd.lastError();
//            qDebug()<<"Already Added Person Detailes in list";
//            m=1,n=1;
//            check(m,n);
            return 0;
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }
//     check(m,n);
    return success;
}

//int name::check(int j,int k)
//{
//    if(j==1 || k==1)
//    {

//        ++j;
//        ++k;
//         qDebug()<<" Added Name and contact";
//    }
//    else
//    {
//        qDebug()<<"Already Add";
//       //  j=0,k=0;
//        return 0;
//    }
//    return 0;
//}

//int name::pop()
//{
//   return j;
//   return k;
//}


bool name::removePerson(const QString &Emp_id)
{
    bool success = false;


    if (personExists(Emp_id))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM delta WHERE Emp_id = (:Emp_id)");
        queryDelete.bindValue(":Emp_id", Emp_id);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}
bool name::personExists(const QString& Emp_id) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Emp_id FROM delta WHERE Emp_id = (:Emp_id) ");
    checkQuery.bindValue(":Emp_id", Emp_id);

    if (checkQuery.exec())

    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool name::allpersonsexist(const QString &name, const QString &Emp_id, const QString &Contact, const QString &dob,
                          const QString &Skills, const QString &Desigination, const QString &Address) const
{

    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM delta WHERE name = (:name) AND Emp_id = (:Emp_id) AND Contact = (:Contact) AND dob = (:dob) AND Skills = (:Skills) AND Desigination = (:Desigination) AND Address = (:Address)");
    checkQuery.bindValue(":Emp_id", Emp_id);
    checkQuery.bindValue(":name", name);
    checkQuery.bindValue(":Contact", Contact);
    checkQuery.bindValue(":dob", dob);
    checkQuery.bindValue(":Skills", Skills);
    checkQuery.bindValue(":Desigination", Desigination);
    checkQuery.bindValue(":Address", Address);

    if (checkQuery.exec())

    {
        if (checkQuery.next())
        {
            exists = true;
          // return 1;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
        //return 0;
    }
 qDebug()<<exists;
   return exists;
}
bool name::removeAllPersons()
{
   bool success = false;


   QSqlQuery removeQuery;

   removeQuery.prepare("DELETE FROM delta");
    if (removeQuery.exec())
    {
        if (removeQuery.next())
        {
            success = true;
        }
    }

    else
    {
        qDebug() << "Remove all persons failed: " << removeQuery.lastError();
    }

    return success;
}

QVector<QString> name::printAllPersons()
{
    QVector<QString>vec;
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM delta");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        vec.push_back(name);

        qDebug() << "===" << name;
    }
    return vec;
}
