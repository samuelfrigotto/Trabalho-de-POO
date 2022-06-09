#include "mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

// transicoes entre telas,  Sinais e os eventos que acontecem
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    tela.resize(5); // tamanho 6 porque sao 5 telas
    tabela.resize(1);
    setGeometry(400,60,800,600); //os outros dois sao o tamanho.. cumprimento 800  e altura 600
    setWindowTitle("Main Menu");


    tela[0] = new Tela("Principal", this); // tela copa do mundo MAINMENU
    tela[0]->setGeometry(0,0,800,600);
    connect(tela[0], &Tela::trocaTela , this, &MainWindow:: trocaParaTela1);
    connect(tela[0], &Tela::fecharPrograma, this, &MainWindow:: FecharTudo);
    connect(tela[0], &Tela::Carregar, this, &MainWindow:: trocaParaTelaCarregar);

    tela[1] = new Tela("Tela1", this);//Tela Roaldo para armazenar dados SPINBOXES
    tela[1]->setGeometry(0,0,800,600);
    connect(tela[1], &Tela::trocaTela, this, &MainWindow:: trocaParaTela2);
    connect(tela[1], &Tela::salvarTela, this, &MainWindow:: salvarArquivo); // slot salvararquivo

    //tabela ou TabDialog, criado como vector de tabelas
    tabela[0] = new TabDialog("Grupos", this);//tela prencher informacao grupos
    tabela[0]->hide();

    tela[2] = new Tela("Tela2", this);//Tela Final
    tela[2]-> setGeometry(0,0,800,600);
    connect(tela[2], &Tela::trocaTela, this, &MainWindow:: FecharTudo );


    tela[3] = new Tela("Carregar", this);// Tela para abrir o txt salvo
    tela[3]-> setGeometry(0,0,800,600);
    connect(tela[3], &Tela::fecharPrograma, this, &MainWindow:: FecharTudo);
    connect(tela[3], &Tela::trocaTela, this, &MainWindow:: trocaParaTelaPrincipal );
    connect(tela[3], &Tela::trocaTelaFinal, this, &MainWindow:: trocaParaTela2 );

    for(int i=1; i < 4;i++) tela[i]->hide(); //oculta as telas pelo numero de telas
}


void MainWindow::trocaParaTela1() {
   //hide
    tela[0]->hide();
    tela[2]->hide();
    tela[3]->hide();

    //show
    tela[1]->show();
    tabela[0]-> setGeometry(1200,100,800,550);
    tabela[0]->show();
    setWindowTitle("Grupos");
  }

void MainWindow::trocaParaTela2() {

    //hide
    tabela[0]->hide();
    tela[1]->hide();
    tela[2]->hide();
    tela[3]->hide();
    //show
    tela[2]->show();
    setWindowTitle("Final");

}

void MainWindow::trocaParaTelaPrincipal() {
    //close
    tela[1]->close();
    tela[2]->close();
    tela[3]->close();
    //show
    tela[0]->show();
    setWindowTitle("Main Menu");
}


void MainWindow::FecharTudo() {
    //exit todo o progrma
    tela[0]->close();
    tela[1]->close();
    tela[2]->close();
    this->close();

}

void MainWindow::trocaParaTelaCarregar() {
    //
    tela[0]->close();
    tela[1]->close();
    tela[2]->close();
    tela[3]->show();
    setWindowTitle("Carregar");


}

// Depois de clickar no Botao da tela do Ronaldo vem nesse SLOT para salvar em um TXT os resultados
 void MainWindow::salvarArquivo() {
     QString dadosTotais = tabela[0]->obterTodosOsDados(); // funcao QString em tabs.cpp escrita na classe TabDialog

     QString filename= "test.txt";

     qDebug() << "OK";

     QFile file(filename);
     if(!file.exists()){
         qDebug() << "NO existe el archivo "<<filename;
     }else{
         qDebug() << filename<< " encontrado...";
     }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
         QTextStream out(&file);
          out << dadosTotais;
          file.flush();
          file.close();
    }
 }


 //SINGLETON DA JANELA PRINCIPAL
 MainWindow* MainWindow::getInstancia(){

    if(instancia == nullptr){
         instancia = new MainWindow;
    }
    return instancia;

 }
MainWindow* MainWindow::instancia = nullptr;
