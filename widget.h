#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>      // Inclure la classe QWidget de Qt pour créer des interfaces graphiques
#include <QTableWidget> // Inclure pour utiliser QTableWidget, qui permet d'afficher des données sous forme de tableau

namespace Ui {
class Widget; // Déclaration anticipée de la classe Widget dans l'espace de noms Ui
}

class Widget : public QWidget // Déclaration de la classe Widget qui hérite de QWidget
{
    Q_OBJECT // Macro nécessaire pour utiliser les fonctionnalités de Qt, comme les signaux et les slots

public:
    explicit Widget(QWidget *parent = nullptr); // Constructeur de la classe Widget, avec un paramètre parent optionnel
    ~Widget(); // Destructeur de la classe Widget

private:
    Ui::Widget *ui; // Pointeur vers l'interface utilisateur générée par Qt Designer

    // Déclaration du QTableWidget pour afficher les résultats
    QTableWidget *tableWidget; // Pointeur vers un QTableWidget qui affichera les données sous forme de tableau

private slots:
    // Slot qui sera appelé lorsque l'utilisateur modifie une cellule dans le QTableWidget
    void updateNoteInDatabase(QTableWidgetItem* item); // Méthode pour mettre à jour une note dans la base de données

};

#endif // WIDGET_H
