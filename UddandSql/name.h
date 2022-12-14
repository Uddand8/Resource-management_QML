#ifndef NAME_H
#define NAME_H

#include<QSqlDatabase>
#include<QSettings>
#include<QObject>

class name :public QObject
{
    Q_OBJECT
public:
    explicit name(QObject *parent = nullptr);
    name(const QString &path);
    ~name();

signals:
private :
  QSqlDatabase db;
public slots:
    bool createTable();
    bool isOpen() const;
    bool addPerson(const QString&name,const QString& Emp_id,const QString& Contact,const QString& dob,
                   const QString& Skills,const QString& Desigination,const QString& Address );
    bool removePerson(const QString&Emp_id);


    bool removeAllPersons();
    bool personExists(const QString& Emp_id) const;
    bool allpersonsexist(const QString&name,const QString& Emp_id,const QString& Contact,const QString& dob,
                        const QString& Skills,const QString& Desigination,const QString& Address) const;
   QVector<QString> printAllPersons() ;
//    int check(int,int);
//    int pop();
//    int pop1();
};
#endif // NAME_H
