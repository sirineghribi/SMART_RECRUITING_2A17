#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("test");
db.setUserName("zeinebbm");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
 return  test;
}
void Connexion::CloseConnexion()
{
    db.close();
}

