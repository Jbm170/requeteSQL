#include "widget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>

// Fonction principale de l'application
int main(int argc, char *argv[])
{
    // Initialiser l'application Qt
    QApplication a(argc, argv);

    // Créer une instance du widget principal
    Widget w;

    // Configurer la connexion à la base de données MySQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("jeu");
    db.setUserName("etudiant");
    db.setPassword("Passciel2");

    // Tenter de se connecter à la base de données
    if(db.open())
    {
        qDebug() << "Vous êtes maintenant connecté à " << db.hostName() ;

        // Créer une requête SQL pour sélectionner toutes les lignes de la table 'jeu'
        QSqlQuery query;
        query.exec("SELECT * FROM `jeu`");

        // Parcourir les résultats de la requête
        while (query.next()) {
            QString id = query.value(0).toString();
            QString Nom = query.value(1).toString();
            QString club = query.value(2).toString();
            QString note = query.value(3).toString();
            qDebug() << Nom << club << note;
        }
        qDebug() << "Requête ok ! :)" ;

        // Fermer la connexion à la base de données
        db.close();
    }
    else
    {
        qDebug() << "La connexion a échouée, désolé" << db.lastError().text();
    }

    // Afficher le widget principal
    w.show();

    // Exécuter la boucle d'événements de l'application Qt
    return a.exec();
}
