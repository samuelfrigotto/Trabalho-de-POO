#ifndef TELA_H
#define TELA_H

#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QTabWidget>
#include <QString>
#include <QPen>
#include <QPainter>


class Tela : public QFrame {
    Q_OBJECT
    QString dadosRonaldo;// armaznea os resultados da tela2

    std::vector<Tela*> tela; // vector de telas
    QPushButton *button, *test, *buttonArchivar;
    QPushButton *inicio, *Sair, *carregar; // main menu
    QPushButton *arquivos, *back, *abrir; //tela carregar arquivos

    // Painter Samuel
    QLabel lbl;
    //aux para ler arquivos
    QString salvos;
    QString Vencedor;

public:

     //--------------SAMUEL---------------------//
    int resultados[49][2]; // variavel para armazenar os resultados das spin boxes
    int primeiro[8]; //aux calculos
    int segundo[8];//aux calculos

    double x[16]; //aux calculos
    double xTOTAL = 0; //aux calculos
    double PORCENTAGEM[16]; ///variavel que tem os porcentagens de cada time
    //----------------------------------------//

    explicit Tela(QString str, QWidget *parent = nullptr);
    void mousePressEvent( QMouseEvent *event);

signals:
    void trocaTela();
    void trocaTelaFinal();
    void fecharPrograma();
    void Carregar();
    void salvarTela();

public slots:
    void armazenarResultados();
};
#endif // TELA_H


