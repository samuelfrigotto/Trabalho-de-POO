#include "calculosvs.h"
#include <QDebug>
//using namespace std;

int Grupos::GT = 0;
int Grupos::xT = 0;


int Grupos::getGT(){
    return GT;
}

//comentarios das funcoes no arquivo .h
Grupos::Grupos(std::string nomeTime, int chaV, double rankF){
    rankFIFA[chaV] = rankF;
    group[chaV] = nomeTime;
    pontos[chaV] = 0;
    rankFIFA[chaV] = rankF;
}

int Grupos::getPontos(int x){
    return pontos[x];
}

void Grupos::Atribuir(std::string time, int chaV, double rankF){
    rankFIFA[chaV] = rankF;
    pontos[chaV] = 0;
    GP[chaV] = 0;
    GC[chaV] = 0;
    group[chaV] = time;
}


std::string Grupos::getTime(int x){
    return group[x];
}


void Grupos::Partida(int chave1, int chave2, int gols1, int gols2){

        GT += (gols1+gols2);

        if(gols1==gols2){ //se for empate
            pontos[chave1]++;
            pontos[chave2]++;

        }
        else if(gols1>gols2){
            pontos[chave1] += 3;//se chave1 ganhar
        }
        else pontos[chave2] += 3;//se chave2 ganhar

        GP[chave1] += gols1;
        GP[chave2] += gols2;
        GC[chave1] += gols2;
        GC[chave2] += gols1;
    }



int Grupos::getPrimeiro(){
    int aux;
    int aux2;
    for(int i = 0; i < 4; i++){//for pra pegar o melhor time por pontos
        for(int j = 0; j < 4; j++){

            if(pontos[j] > pontos[i]){
                aux = j;
            }
        }
    }


    for(int i = 0; i < 4; i++){//for pra pegar o segundo melhor time por pontos
        for(int j = 0; j < 4; j++){

            if(pontos[j] > pontos[i] && j!= aux){
                aux2 = j;
        }
        }
    }

    if(pontos[aux] == pontos[aux2]){//se eles empatarem em pontos compara qual eh o primeiro colocado
        if((GP[aux]-GC[aux]) < (GP[aux2]-GC[aux2])){ //SG AUX < SG AUX2
            return aux2;}
        else if((GP[aux]-GC[aux]) == (GP[aux2]-GC[aux2])) //SG AUX == SG AUX2
        {
            if((GP[aux]) < (GP[aux2])){ return aux2;} //GP AUX < GP AUX2
            else {return aux;}
        }
        else {return aux;}
    }

    return aux;


}

int Grupos::getSegundo(){//compara os 3 primeiros times para ver qual
    //eh o segundo colocado do grupo caso empatem em pontos

    int aux;
    int aux2;
    int aux3;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(pontos[j] > pontos[i]){
                aux = j;}

        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(pontos[j] > pontos[i] && j!= aux){
                aux2 = j;}

        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(pontos[j] > pontos[i] && j!= aux && j!=aux2){
                aux3 = j;}

        }
    }

    if(pontos[aux] == pontos[aux2]){
        if((GP[aux]-GC[aux]) < (GP[aux2]-GC[aux2])){
            return aux;}
        else if((GP[aux]-GC[aux]) == (GP[aux2]-GC[aux2]))
        {
            if((GP[aux]) < (GP[aux2])) {return aux;}
            else {return aux2;}
        }
        else{ return aux2;}
    }

    if(pontos[aux2] == pontos[aux3]){
        if((GP[aux2]-GC[aux2]) < (GP[aux3]-GC[aux3])){
            return aux3;}
        else if((GP[aux2]-GC[aux2]) == (GP[aux3]-GC[aux3]))
        {
            if((GP[aux2]) < (GP[aux3])) {return aux3;}
            else {return aux2;}
        }
        else {return aux2;}
    }

    return aux2;
}

int Grupos::getGP(int x){
    return GP[x];
}


int Grupos::getGC(int x){
    return GC[x];
}


double Grupos::getRank(int y){
    return rankFIFA[y];
}


double Grupos::getX(int y){//calculo utilizado para achar a probabilidade
    //de um time ser campeao com base nos seguintes atributos:

    int a = GP[y];
    int b = GC[y];
    int c = GT;
    double d = rankFIFA[y];
    int e = pontos[y];

    double x11 = (((double)a - (double)b)/(double)c)*((double)3/(double)10);//saldo de gols diidido pelo total de gols do grupo tem peso 3/10
       double x12 = (double)d*((double)4/(double)10); // o ranking da fifa que corresponde ao historico do passado do time tem peso 4/10
       double x13 = ((double)e/(double)9)*((double)3/(double)10);//os pontos feitos no grupo dividido por 9 para equalizar com as outras equacoes peso 3/10
       double x1 = x11 + x12 + x13;//somam-se as 3 partes da conta e temos x do time
       xT += x1;
    return x1;
}


















