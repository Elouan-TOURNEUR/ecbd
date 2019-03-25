#include "mafenetre.h"
#include "charger_csv.h"
MaFenetre::MaFenetre(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(800,600);

    m_bou = new QPushButton("Quitter", this);
    m_bou->setGeometry(600,400,80,40);

    m_lab = new QLabel("Couleur", this);
    m_lab->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_lab->move(320, 125);


    m_com = new QComboBox(this);
    m_com->setGeometry(300,150,100,30);
    m_com->addItem("Rouge");
    m_com->addItem("Vert");
    m_com->addItem("Bleu");
    m_com->addItem("Jaune");
    m_com->addItem("Orange");
    m_com->addItem("Violet");

    m_tra = new QLabel(this);
    m_tra->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_tra->move(320, 300);

    read_csv (m_mat, m_vet, "data.csv");

    table = new QTableWidget(this) ;
    table->setGeometry(100,100,400,400) ;
    table->setRowCount(m_mat.size()+1) ;
    table->setColumnCount(m_vet.size()+1);

    for (unsigned i = 0 ; i < m_vet.size() ; i++)
    {
        for(unsigned j = 0 ; j < m_mat.size() ; j++){
            QString test = QString::fromUtf8(m_vet[i].c_str()) ;
            QTableWidgetItem *item = new QTableWidgetItem(test) ;
            table->setItem(i,j, item) ;
        }

    }


    connect(m_bou, SIGNAL(clicked()), this, SLOT(setQuitter()));
    connect(m_com, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(setCouleur()));

}

void MaFenetre::setQuitter()
{
    exit(0);
}
void MaFenetre::setCouleur()
{
    couleur = m_com->currentText();

    m_tra->setText(">> " + couleur + " <<");
}
