#ifndef TABWIDGET_H
#define TABWIDGET_H
#include <QWidget>

#include <QDialog>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QString>



class QTabWidget;
class Pestana1;

class QString;
class QHBoxLayout;
class QDialog;

class QVBoxLayout;
class QPushButton;

class Pestana1 : public QWidget {
    QVBoxLayout *layout;

public:
    Pestana1(QWidget *parent = NULL);
};

class TabDialog : public QDialog {
    QString *labeTab1;
    QString *labeTab2;

    Pestana1 *primeira;
    QTabWidget *myTabWidget; //biblioteca widget

    QHBoxLayout *layout;
public:
    TabDialog(QWidget *parent = NULL);
};



#endif // TABWIDGET_H
