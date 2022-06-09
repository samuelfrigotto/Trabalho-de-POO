#ifndef CALCULOSVS_H
#define CALCULOSVS_H

#include <bits/stdc++.h>
#include <QString>

class Grupos{

int pontos[4]; // vetor que guarda os pontos do grupo
int GP[4]; // vetor que guarda os gols pro do grupo
int GC[4]; // vetor que guarda os gols sofridos do grupo
double rankFIFA[4]; // vetor que guarda o ranking fifa dos times do grupo
std::string group[4]; // vetor que guarda o nome dos times do grupo
static int GT; // variavel que guarda os gols totais do grupo
static int xT;

public:

    Grupos(std::string nomeTime, int chaV, double rankF); //construtor do grupo com o cabeca de chave
    void Atribuir(std::string time, int chaV, double rankF);// funcao que atribui os outros times do grupo
    void Partida(int chave1, int chave2, int gols1, int gols2);// funcao que simula a partida e atribui os gols e pontos para cada time

    int getPontos(int x);//getter dos pontos
    std::string getTime(int x); //getter do nome do time
    int getPrimeiro(); // getter do primeiro colocado do grupo
    int getSegundo(); //getter do segundo colocado do grupo
    int getGP(int x); //getter de gols pro
    int getGC(int x);//getter de gols contra
    static int getGT(); //variavel que guarda o total de gols do grupo
    double getRank(int y); //getter do rank fifa de cada time
    double getX(int y); //getter do calculo da oribabilidade de cada time
};


#endif // CALCULOSVS_H
