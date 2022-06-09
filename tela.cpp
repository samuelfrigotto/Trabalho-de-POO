#include "tela.h"
#include "tabs.h"
#include "calculosvs.h"

#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
#include <QTabWidget>
#include <QFileInfo>
#include <QFileDevice>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>

//contrutor de telas.. no casso de nosso programa sao 4 telas
Tela::Tela(QString str, QWidget *parent) : QFrame{parent} {
    if(str == "Principal" and SIGNAL(trocaTela()) ){ //Tela Principal com 2 botoes para trocar de tela e 1 para fechcar o programa

        QPixmap pm("C:/Users/gaboh/Pictures/Images/menu.png"); // Imagem menu
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,600,  Qt::KeepAspectRatioByExpanding));
           lbl.show();

           inicio = new QPushButton("Inicio", this);
           inicio  -> setGeometry(425,85,200,50);
           inicio ->setStyleSheet("QPushButton {"
                                  "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                                   "}"
                                   "QPushButton:hover {"
                                             "background: rgb(255, 227, 135)"
                                         "};");
           connect(inicio, SIGNAL(clicked()), SIGNAL(trocaTela()));

           carregar = new QPushButton("Carregar", this);
           carregar  -> setGeometry(425,170,200,50);
           carregar -> setStyleSheet("QPushButton {"
                                     "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                                      "}"
                                      "QPushButton:hover {"
                                                "background: rgb(255, 227, 135)"
                                            "};");
           connect(carregar, SIGNAL(clicked()), SIGNAL(Carregar()));

           Sair = new QPushButton("Sair", this);
           Sair  -> setGeometry(425,250,200,50);

           Sair -> setStyleSheet("QPushButton {"
                                 "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                                  "}"
                                  "QPushButton:hover {"
                                            "background: rgb(255, 227, 135)"
                                        "};");
             connect(Sair,SIGNAL(clicked()), SIGNAL(fecharPrograma()));


  } else if(str == "Tela1" and SIGNAL(trocaTela()) ){ // Tela Grupos (Ronaldo) 2 botoes 1 para seguinte e outro para salvar

        QPixmap pm("C:/Users/gaboh/Pictures/Images/ronaldo (2).jpg"); // Imagem ronaldo
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,600,  Qt::KeepAspectRatioByExpanding));
           lbl.show();

        button = new QPushButton("Seguinte", this);
        button  -> setGeometry(600,0,100,50);
        button -> setStyleSheet("QPushButton {"
                              "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                               "}"
                               "QPushButton:hover {"
                                         "background: rgb(255, 227, 135)"
                                     "};");
        connect(button, SIGNAL(clicked()), SIGNAL( trocaTela() ));
        connect(button, SIGNAL(clicked()), SLOT(  armazenarResultados() ));

        //////////////////////////////especial////////////////////////////////////////////////
        buttonArchivar = button = new QPushButton("Salvar", this); // botao salvar
        buttonArchivar -> setGeometry(400,550,150,50);
        buttonArchivar -> setStyleSheet("QPushButton {"
                              "background:#99E8E3; color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                               "}"
                               "QPushButton:hover {"
                                         "background: #DCF1F0"
                                     "};");
        connect(buttonArchivar, SIGNAL(clicked()), SIGNAL( salvarTela() )); // conexao ou signal na classe tela mesmo



    } else if(str == "Tela2" and SIGNAL(trocaTela()) ){ // Janela final onde aparece o resultado final no Debug

        QPixmap pm("C:/Users/gaboh/Pictures/Images/Final.png"); // para ele funcionar a barra tem que ser-> /
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,600,  Qt::KeepAspectRatioByExpanding));
           lbl.show();

        back = new QPushButton("Sair", this);
        back  -> setGeometry(400,550,100,50);
        back -> setStyleSheet("QPushButton {"
                              "background:#99E8E3 ; color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                               "}"
                               "QPushButton:hover {"
                                         "background: #DCF1F0"
                                     "};");

        connect(back, SIGNAL(clicked()), SIGNAL( trocaTela()  )); // Sinal para fecahr o programa


    }else if(str == "Carregar" and SIGNAL(trocaTela()) ){ // Tela de Carregar
        QPixmap pm("C:/Users/gaboh/Pictures/Images/Carrega.png"); //Imagem carga
           lbl.setParent(this);
           lbl.setPixmap(pm.scaled(800,600,  Qt::KeepAspectRatioByExpanding));
           lbl.show();

        back = new QPushButton("Back", this);// volta para Principal
        back  -> setGeometry(30,30,200,50);
        back -> setStyleSheet("QPushButton {"
                              "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                               "}"
                               "QPushButton:hover {"
                                         "background: rgb(255, 227, 135)"
                                     "};");
        connect(back, SIGNAL(clicked()), SIGNAL( trocaTela()  ));

        arquivos = new QPushButton("Carregar ultimo txt", this);// volta carrega o ultimo txt
        arquivos  -> setGeometry(300,150,200,50);
        arquivos -> setStyleSheet("QPushButton {"
                              "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                               "}"
                               "QPushButton:hover {"
                                         "background: rgb(255, 227, 135)"
                                     "};");
        connect(arquivos, SIGNAL(clicked()), SLOT( armazenarResultados() )); // vai para o SLOT onde le um txt e calcula os resultados

        abrir = new QPushButton("Abrir", this);
        abrir  -> setGeometry(600,350,200,50);
        abrir -> setStyleSheet("QPushButton {"
                              "background: rgb(218, 176, 0); color: black; border-radius: 25px; font: 15px Arial, sans-serif"
                               "}"
                               "QPushButton:hover {"
                                         "background: rgb(255, 227, 135)"
                                     "};");
        connect(abrir, SIGNAL(clicked()), SIGNAL( trocaTelaFinal() )); //botao que emite um sinal para ir na tela final

    }
}




// Sobreescrita, Uso dos eventos de mouse do Qt.... Sempre que o Usurio clickar na tela a Janela de informacoes do programa aparece
void Tela::mousePressEvent( QMouseEvent *event) {

    int info = QMessageBox::information( this  ," ","<h1>Informacao</h1><tb></br>"
                                                           "<h3>Entra os reultados:</h3>"
                                                           "<ul><h4><li>Ganhar sao 3 pontos"
                                                           "<li>Empate 1 ponto"
                                                           "<li>Perder 0 ponto</br></br></ul>"
                                                           "<h4>Depois de entrar todos os resultados o "
                                                           "algorithmo vai calcular a probabilidade de cada time da "
                                                           "fase de grupos de ganhar a copa do mundo:</br></br>"
                                                           "Os resultados nao podem dar empate para todos os times e"
                                                           "nao pode mudar de tela antes de leer os resultados das SPINBOXES</h4>" );
}
