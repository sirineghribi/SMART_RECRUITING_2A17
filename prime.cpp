#include "prime.h"

prime::prime()
{
primes=0;
nbh_supp=0;

}
prime::prime(int nbh_supp,int primes)
{
this->primes=primes;
    this->nbh_supp=nbh_supp;

}

int prime::getprimes(){return primes;}
void prime:: setprimes(int primes) {this->primes=primes;}
int prime ::getnbh_supp(){return nbh_supp;}
void prime:: setnbh_supp(int nbh_supp) {this->nbh_supp=nbh_supp;}



 bool prime:: ajouter_nbh_supp()
 {

      QSqlQuery query;
      QString res=QString::number(nbh_supp);
      QString res1=QString::number(primes);

      query.prepare("INSERT INTO prime ( nbh_supp,primes) "
                              "VALUES ( :nbh_supp,:primes)");
                query.bindValue(":nbh_supp", res);
                query.bindValue(":primes", res1);


      return query.exec();

 }
 QSqlQueryModel * prime:: afficher_nbh()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from prime");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("nbh_supp"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("primes"));


 return model;
 }

