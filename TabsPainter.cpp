//Parte estetica do Grupos
#include "tabs.h"
#include <QLabel>

// Uso do painter caso o Usuario nao consiga carrega as Imagens contendo a informacao do TabDialog
void GeneralTab::paintEvent(QPaintEvent *event){
   Q_UNUSED(event)
    QPainter painter(this); //pintor

               std::string Titulo = "Grupos ";
               QPen canetaazul(Qt::blue);
               QPen canetaBlack (Qt::black);
               QFont font("Verdana");
               font.setPixelSize(30);
               painter.setPen(canetaazul);
               painter.setFont(font);
               //                x   y  widht height
               painter.drawText( 300,50,200,50, Qt::AlignCenter,QString::fromStdString(Titulo));

               //qLabel para escribir
               std::string Equipo1 = "Time 1 ";
               painter.setPen(canetaBlack);
               painter.setFont(font);
               painter.drawText( 100,100,200,50, Qt::AlignCenter,QString::fromStdString(Equipo1));

               std::string Equipo2 = "Time 2 ";
               painter.setFont(font);
               painter.drawText( 500,100,200,50, Qt::AlignCenter,QString::fromStdString(Equipo2));
}
