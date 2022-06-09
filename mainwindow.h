#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QPushButton>
#include <QLabel>

#include "tela.h"
#include "tabs.h"
//Class Main,  apartir de essa Janela se criam o resto de telas
// E' unico e' Singleton!
class MainWindow : public QMainWindow {
    Q_OBJECT
    static MainWindow* instancia;
    std::vector<TabDialog*> tabela; // vector de tabela cassso seja necessario quando se melhore o trabalho
    std::vector<Tela*> tela; // vector de telas
    QLabel lbl; // label para colocar imagens na tela
    MainWindow(QWidget *parent = nullptr);
public:
    MainWindow (const MainWindow &obj) = delete;
    MainWindow operator=(MainWindow &obj) = delete;// sobrecarga
    static MainWindow* getInstancia();

public slots:
    void salvarArquivo();
    void trocaParaTela1();
    void trocaParaTela2();
    void trocaParaTelaCarregar();
    void trocaParaTelaPrincipal();
    void FecharTudo();
};



#endif // MAINWINDOW_H
