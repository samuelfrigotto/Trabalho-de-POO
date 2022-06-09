#ifndef TABS_H
#define TABS_H

#include <QWidget>
#include <vector>
#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QFileInfo>
#include <QPainter>
#include <QGroupBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

class GeneralTab : public QWidget{
    Q_OBJECT
    QPushButton *archivar;
    QLabel lbl;

public:
    //variaveis usadas para armazenar os resultados dos calculos de cada time
       char grp;
       int i = 0, j=12;
       QString obterDados();
    QGroupBox *spinBoxesGroup;
    std::vector<QSpinBox*> spinBox;

    explicit GeneralTab(QString grupo, QWidget *parent = nullptr);
     void paintEvent(QPaintEvent *event); //Paint Event hides Overloaded virtual funtion

public slots:
    // Os SLOTS execao foram feitos no arquivo Execoes.cpp
    void Execao();
    void Execao1();
    void Execao2();
    void Execao3();
    void Execao4();
    void Execao5();
    void Execao6();
    void Execao7();
    void Execao8();
    void Execao9();
    void Execao10();
    void Execao11();

signals:
    void guardar();

};


class TabDialog : public QDialog{
    Q_OBJECT
    std::vector<GeneralTab*> tabVector;
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;

public:
    explicit TabDialog(const QString &str2, QWidget *parent = nullptr);
    QString obterTodosOsDados(); // string aux

};

#endif // TABS_H
