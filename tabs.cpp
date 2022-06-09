#include "tabs.h"

#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QDebug>
#include <QFile>
#include <QTextStream>

// Cria a Janela TabDialog e dentro dela uma General tab contendo todos os Grupos
TabDialog::TabDialog(const QString &str2, QWidget *parent) : QDialog(parent){
    QFileInfo fileInfo(str2);

    tabWidget = new QTabWidget(this);
    tabVector.resize(8);

// cria dentro do TabDialog as tabs e cria uma generaltab por cada grupo do A ate H
    QString letras[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    for (qsizetype i = 0; i < 8; i++) {
        tabVector[i] = new GeneralTab(letras[i], this);
        QString aux("GRUPO " + letras[i]);
        tabWidget->addTab(tabVector[i], aux);
    }

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
       connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
       connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    // coloca tudo dentro de um layout
       QVBoxLayout *mainLayout = new QVBoxLayout;
          mainLayout->addWidget(tabWidget);
          mainLayout->addWidget(buttonBox);
          setLayout(mainLayout);
          setWindowTitle(tr("Tab Dialog"));
}


// Cria a Tela General tab e cria Todos os Grupos do A ate H para prencher os SPINBOXES
GeneralTab::GeneralTab(QString grupo, QWidget *parent): QWidget(parent){
    // Criacao de VECTOR SPINBOXES
    // varivel grupo que foi passada desde o TabDialog para saber em cual grupo o usuario esta'
    spinBox.resize(12);
    if(grupo == 'A'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoA.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'B'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoB.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'C'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoC.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'D'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoD.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'E'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoE.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'F'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoF.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'G'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoG.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }else if(grupo == 'H'){
        QPixmap pm("C:/Users/gaboh/Pictures/Images/grupoH.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,550,  Qt::KeepAspectRatioByExpanding));
           lbl.show();
    }

    // criacao de 12 SPINBOXES e colocadas no meio da tela usando SetGeometry
    for(int i=0, j=180 ; i<12; i++){
        spinBox[i] = new QSpinBox(this);
        spinBox[i] -> setRange(-1, 9);
        spinBox[i] -> setSingleStep(1);
        spinBox[i] -> setValue(0);

        if(i%2 == 0){
            //                       x  y x  y
          spinBox[i] -> setGeometry(350,j,50,30);
        }else {
          spinBox[i] -> setGeometry(400,j,50,30);
           j+=50;
        }
    }
// tratamento de Erros
    // se o Usuario mudar o valor para algun numero negativo, lanca uma execao  no SLOT Execao
connect(spinBox[0], SIGNAL(valueChanged(int)),this, SLOT(Execao()));
connect(spinBox[1], SIGNAL(valueChanged(int)),this, SLOT(Execao1()));
connect(spinBox[2], SIGNAL(valueChanged(int)),this, SLOT(Execao2()));
connect(spinBox[3], SIGNAL(valueChanged(int)),this, SLOT(Execao3()));
connect(spinBox[4], SIGNAL(valueChanged(int)),this, SLOT(Execao4()));
connect(spinBox[5], SIGNAL(valueChanged(int)),this, SLOT(Execao5()));
connect(spinBox[6], SIGNAL(valueChanged(int)),this, SLOT(Execao6()));
connect(spinBox[7], SIGNAL(valueChanged(int)),this, SLOT(Execao7()));
connect(spinBox[8], SIGNAL(valueChanged(int)),this, SLOT(Execao8()));
connect(spinBox[9], SIGNAL(valueChanged(int)),this, SLOT(Execao9()));
connect(spinBox[10], SIGNAL(valueChanged(int)),this, SLOT(Execao10()));
connect(spinBox[11], SIGNAL(valueChanged(int)),this, SLOT(Execao11()));
// Os SLOTS execao foram criados no arquivo Execoes.cpp
}



//metodo chamado desde mainwindow.cpp onde ele armazena numa variavel os dados dos grupos
QString TabDialog::obterTodosOsDados() {
    QString dados;
    for (int i = 0; i < 8;i++) {
        dados += tabVector[i]->obterDados(); // chama o metodo para pegar os dados do grupo das SpinBoxes
    }
    return dados;
}

// Pega os dados das spin boxes que o Usuario entrou
QString GeneralTab::obterDados() {
    QString dados = "";
    for(size_t i = 0; i < spinBox.size(); i++){
        dados += QString::number(spinBox[i]->value()); // armazena o conteudo das Spinboxes na variavel dados
    }
    return dados;
}




