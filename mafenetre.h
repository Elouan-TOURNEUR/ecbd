#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QTableWidget>
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QString>
typedef std::vector<std::string> CVString;
typedef std::vector <std::vector<std::string>> CMatString;


class MaFenetre : public QMainWindow
{
    Q_OBJECT // Macro OBLIGATOIRE
public slots :
    void setQuitter();
    void setCouleur();
public :
    MaFenetre(QWidget *parent = 0);
private :
    QLabel *m_lab, *m_tra, *m_test;
    QPushButton *m_bou;
    QComboBox *m_com;
    QString couleur ;
    QTableWidget *table;
    CVString m_vet;
    CMatString m_mat;


} ;
#endif // MAFENETRE_H
