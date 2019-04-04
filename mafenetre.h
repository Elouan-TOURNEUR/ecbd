#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>

#include <map>
#include <vector>
#include <set>

typedef std::vector<std::string> CVString;
typedef std::vector <std::vector<std::string>> CMatString;


class MaFenetre : public QMainWindow
{
    Q_OBJECT // Macro OBLIGATOIRE
public slots :
    void setQuitter();
    void setPredire();

public :
    MaFenetre(QWidget *parent = 0);
private :
    QLabel *m_lab, *m_tra, *m_test;

    QPushButton *m_bou;
    QPushButton* m_pred;

    QLineEdit* m_nom;
    QLineEdit* m_prenom;
    QLabel* m_labnom;
    QLabel* m_labprenom;

    QLabel* m_result;
    QLabel* m_lab1;
    QLabel* m_lab2;
    QLabel* m_lab3;
    QLabel* m_maladie;

    QComboBox* boxFievre;
    QComboBox* boxDouleur;
    QComboBox* boxToux;

    QTableWidget *table;
    CVString m_vet;
    CMatString m_mat;

    std::map<std::string, double> m_freqMaladie;
    std::set<std::string> m_valeursMaladies; // noms possibles de maladies

} ;
#endif // MAFENETRE_H
