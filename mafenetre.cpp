#include "mafenetre.h"
#include "charger_csv.h"
MaFenetre::MaFenetre(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("CLASSIFICATION DES PATIENTS - PREDICTION");

    setFixedSize(1400,800);

    m_bou = new QPushButton("Quitter", this);
    m_bou->setGeometry(1000,700,80,40);

    m_pred = new QPushButton("Prédire", this);
    m_pred->setGeometry(200, 300, 80, 40);

    m_nom = new QLineEdit(this);
    m_nom->setGeometry(600, 50, 150, 30);

    m_prenom = new QLineEdit(this);
    m_prenom->setGeometry(600, 100, 150, 30);

    m_labnom = new QLabel("Nom : ", this);
    m_labnom->setGeometry(500, 50, 150, 30);

    m_labprenom = new QLabel("Prénom : ", this);
    m_labprenom->setGeometry(500, 100, 150, 30);

    m_lab = new QLabel("Valeur des attributs :", this);
    m_lab->setGeometry(20, 180, 150, 30);

    m_lab1 = new QLabel("Fièvre", this);
    m_lab1->setGeometry(230, 150, 100, 30);

    m_lab2 = new QLabel("Douleur", this);
    m_lab2->setGeometry(350, 150, 100, 30);

    m_lab3 = new QLabel("Toux", this);
    m_lab3->setGeometry(470, 150, 100, 30);

    boxFievre = new QComboBox(this);
    boxFievre->setGeometry(230,180,100,30);

    boxDouleur = new QComboBox(this);
    boxDouleur->setGeometry(350,180,100,30);

    boxToux = new QComboBox(this);
    boxToux->setGeometry(470,180,100,30);

    m_tra = new QLabel(this);
    m_tra->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_tra->move(320, 300);

    connect(m_bou, SIGNAL(clicked()), this, SLOT(setQuitter()));
    connect(m_pred, SIGNAL(clicked()), this, SLOT(setPredire()));

    read_csv (m_mat, m_vet, "data.csv");

    std::set<std::string> valeursDouleur; // comboBox de douleur
    std::set<std::string> valeursFievre; // comboBox de fièvre
    std::set<std::string> valeursToux; // comboBox de toux

    for (unsigned i = 1 ; i < m_mat.size() ; i = i + 1){
        {
            valeursDouleur.insert(m_mat[i][1]) ;
        }
    }
    for (unsigned i = 1 ; i < m_mat.size() ; i = i + 1){
        {
            valeursFievre.insert(m_mat[i][0]) ;
        }
    }
    for (unsigned i = 1 ; i < m_mat.size() ; i = i + 1){
        {
            valeursToux.insert(m_mat[i][2]) ;
        }
    }
    for (unsigned i = 1 ; i < m_mat.size() ; i = i + 1){
        {
            m_valeursMaladies.insert(m_mat[i][3]) ;
        }
    }

    boxDouleur->addItem("NULL");
    for (const std::string& valeur : valeursDouleur)
        boxDouleur->addItem(valeur.c_str());

    boxFievre->addItem("NULL");
    for (const std::string& valeur : valeursFievre)
        boxFievre->addItem(valeur.c_str());

    boxToux->addItem("NULL");
    for (const std::string& valeur : valeursToux)
        boxToux->addItem(valeur.c_str());


    table = new QTableWidget(this) ;
    table->setGeometry(300,380,550,350) ;
    table->setRowCount(m_mat.size()+5) ;
    table->setColumnCount(m_vet.size()+1);

    //    unsigned compteur = 0 ;
    //    for(unsigned j = 1 ; j < m_vet.size()+1 ; j = j + 1){
    //        QString test = QString::fromUtf8(m_vet[compteur].c_str()) ;
    //        QTableWidgetItem *item = new QTableWidgetItem(test) ;
    //        table->setItem(0,j,item) ;
    //        compteur++ ;
    //    }

    //    unsigned compteur2 = 0 ;
    //    for (unsigned i = 1 ; i < m_mat.size()+1 ; i = i + 1)
    //    {
    //        string name = "Patient ";
    //        name += to_string(i) ;
    //        QTableWidgetItem *patient = new QTableWidgetItem(name.c_str()) ;
    //        table->setItem(i,0,patient);
    //        unsigned compteur3 = 0 ;
    //        for(unsigned j = 1 ; j < m_vet.size()+1 ; j = j + 1){
    //            QString test = QString::fromUtf8(m_mat[compteur2][compteur3].c_str()) ;
    //            QTableWidgetItem *item = new QTableWidgetItem(test) ;
    //            table->setItem(i,j,item) ;
    //            compteur3++;
    //        }
    //        compteur2++;
    //    }


    unsigned compteur2 = 0 ;
    for (unsigned i = 1 ; i < m_mat.size()+1 ; i = i + 1)
    {
        string name = "Patient ";
        name += to_string(i) ;
        QTableWidgetItem *patient = new QTableWidgetItem(name.c_str()) ;
        table->setItem(i,0,patient);
        unsigned compteur3 = 0 ;
        unsigned compteur = 0 ;

        for(unsigned j = 1 ; j < m_vet.size()+1 ; j = j + 1)
        {
            QString test2 = QString::fromUtf8(m_vet[compteur].c_str()) ;
            QTableWidgetItem *item2 = new QTableWidgetItem(test2) ;
            table->setItem(0,j,item2) ;
            compteur++ ;
            QString test = QString::fromUtf8(m_mat[compteur2][compteur3].c_str()) ;
            QTableWidgetItem *item = new QTableWidgetItem(test) ;
            table->setItem(i,j,item) ;
            compteur3++;
        }
        compteur2++;
    }

    for (unsigned i=0; i < m_mat.size(); ++i)
        m_freqMaladie[m_mat[i][3]] += 1;


    for (const std::string& maladie : m_valeursMaladies)
        m_freqMaladie[maladie] /= m_mat.size();

    //    for (int i=0; i < m_vet.size(); ++i)
    //        table->setHorizontalHeaderItem(i, new QTableWidgetItem(m_vet[i].c_str()));

}
void MaFenetre::setQuitter()
{
    exit(0);
}
int compteur = 10 ;
void MaFenetre::setPredire()
{
    string maladieResult;
    double score = 0;

    for(const string& maladie : m_valeursMaladies)
    {
        double conf1=0.0, conf2=0.0, conf3=0.0;

        for(int i=0; i < m_mat.size(); ++i)
        {
            if(m_mat[i][3] == maladie)
            {
                if(m_mat[i][0]==boxFievre->currentText().toStdString())
                    conf1 += 1.0;

                if(m_mat[i][1]==boxDouleur->currentText().toStdString())
                    conf2 += 1.0;

                if(m_mat[i][2]==boxToux->currentText().toStdString())
                    conf3 += 1.0;
            }
        }

        double freq = m_freqMaladie[maladie] * m_mat.size();

        if (boxFievre->currentText().toStdString() == "NULL")
            conf1 = 1;
        else
            conf1 /= freq;

        if (boxDouleur->currentText().toStdString() == "NULL")
            conf2 = 1;
        else
            conf2 /= freq;

        if (boxToux->currentText().toStdString() == "NULL")
            conf3 = 1;
        else
            conf3 /= freq;

        if (boxFievre->currentText().toStdString() == "NULL" && boxDouleur->currentText().toStdString() == "NULL" && boxToux->currentText().toStdString() == "NULL")
        {
            maladieResult = "Impossible de trouver la maladie";
            break;
        }

        if(m_freqMaladie[maladie] * conf1 * conf2 * conf3 > score)
        {
            maladieResult = maladie;
            score = m_freqMaladie[maladie] * conf1 * conf2 * conf3;
        }
        if (score == 0.0)
        {
            maladieResult = "Pas assez de données" ;
        }
    }

    m_tra->setText(maladieResult.c_str());
    m_tra->adjustSize();
    m_tra->setVisible(true);



    QTableWidgetItem *prenom = new QTableWidgetItem(m_prenom->text()) ;
    table->setItem(compteur,0,prenom) ;
    QTableWidgetItem *fievre = new QTableWidgetItem(boxFievre->currentText()) ;
    table->setItem(compteur,1,fievre) ;
    QTableWidgetItem *douleur = new QTableWidgetItem(boxDouleur->currentText()) ;
    table->setItem(compteur,2,douleur) ;
    QTableWidgetItem *toux = new QTableWidgetItem(boxToux->currentText()) ;
    table->setItem(compteur,3,toux) ;
    QTableWidgetItem *maladie = new QTableWidgetItem(maladieResult.c_str()) ;
    table->setItem(compteur,4,maladie) ;



    compteur ++ ;
}
