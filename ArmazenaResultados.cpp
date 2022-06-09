#include "tela.h"
#include "tabs.h"
#include "calculosvs.h"

#include <QDebug>

// Depois de clickar no seguiente, o metodo armazenarResultados vai calcular os resultados dos grupos
// Dando como saida os dois melhores grupos de cada time e o calculo da formula para saber
// a probabilidade de cada time ganhar
void Tela::armazenarResultados(){

    // Ler o arquivo criado e armazenar na variavel resultados[48][2]
               QString filename="test.txt";
               QFile file(filename);
               if(!file.exists()){
                   qDebug() << "NO existe el archivo "<< filename;
               }else{
                   qDebug() << filename<<" encontrado...";
               }

               if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                  salvos  = file.readAll(); // variavel salvos que tem os resultados qu eo usuario entrou no SpinBox-> coloca essses resultados dentro do txt
                }
                int k = 0;
                int t = 0;
                int j= 0;
                try{// try cathc por acaso de erro
               for( k=0;k<48;k++, j+=2 ){
                           QString aux = salvos[j];
                           resultados[k][0] = aux.toInt();
                           QString aux2 = salvos[j+1];
                           resultados[k][1] = aux2.toInt();
                }
                }catch(...){
                 qDebug() << k << t ;
               }


////////////////////////////////////////////////////////////////////////////////////
/// USO DA CLASE CALCULOSCVS.H
////////////////////////////////////////////////////////////////////////
///             //A
                std::string nome0 = "Qatar";
                double rank0 = 0.4414;
                std::string nome1 = "Holanda";
                double rank1 = 0.6587;
                std::string nome2 = "Senegal";
                double rank2 = 0.5842;
                std::string nome3 = "Equador";
                double rank3 = 0.4526;


                //*B

                std::string nome4 = "Inglaterra";
                double rank4 = 0.7617;
                std::string nome5 = "Iran";
                double rank5 = 0.5645;
                std::string nome6 = "USA";
                double rank6 = 0.6337;
                std::string nome7 = "Russia";
                double rank7 = 0.4000;

                //C
                std::string nome8 = "Argentina";
                double rank8 = 0.7651;
                std::string nome9 = "Arabia Saudita";
                double rank9 = 0.4447;
                std::string nome10 = "Mexico";
                double rank10 = 0.6588;
                std::string nome11 = "Polonia";
                double rank11 = 0.5442;

                //D
                std::string nome12 = "Franca";
                double rank12 = 0.7899;
                std::string nome13 = "Ucrania";
                double rank13 = 0.6587;
                std::string nome14 = "Dinamarca";
                double rank14 = 0.6536;
                std::string nome15 = "Tunisia";
                double rank15 = 0.4998;

                //E
                std::string nome16 = "Espanha";
                double rank16 = 0.7092;
                std::string nome17 = "Vasco";
                double rank17 = 0.6666;
                std::string nome18 = "Alemanha";
                double rank18 = 0.6505;
                std::string nome19 = "Japao";
                double rank19 = 0.5534;

                //*F
                std::string nome20 = "Belgica";
                double rank20 = 0.8270;
                std::string nome21 = "Canada";
                double rank21 = 0.4790;
                std::string nome22 = "Marrocos";
                double rank22 = 0.5519;
                std::string nome23 = "Croacia";
                double rank23 = 0.6211;


                //G
                std::string nome24 = "Brasil";
                double rank24 = 0.8327;
                std::string nome25 = "Servia";
                double rank25 = 0.5475;
                std::string nome26 = "Suica";
                double rank26 = 0.6353;
                std::string nome27 = "Camaroes";
                double rank27 = 0.4805;

                //*H

                std::string nome28 = "Portugal";
                double rank28 = 0.6748;
                std::string nome29 = "Gana";
                double rank29 = 0.3874;
                std::string nome30 = "Uruguai";
                double rank30 = 0.6357;
                std::string nome31 = "Coreia do Sul";
                double rank31 = 0.5195;

                //Criacao dos grupos
                Grupos A(nome0, 0, rank0);
                A.Atribuir(nome1, 1, rank1);
                A.Atribuir(nome2, 2, rank2);
                A.Atribuir(nome3, 3, rank3);

                Grupos B(nome4, 0, rank4);
                B.Atribuir(nome5,1, rank5);
                B.Atribuir(nome6,2, rank6);
                B.Atribuir(nome7,3, rank7);

                Grupos C(nome8, 0, rank8);
                C.Atribuir(nome9, 1, rank9);
                C.Atribuir(nome10, 2, rank10);
                C.Atribuir(nome11, 3, rank11);

                Grupos D(nome12,  0, rank12);
                D.Atribuir(nome13, 1, rank13);
                D.Atribuir(nome14, 2, rank14);
                D.Atribuir(nome15, 3, rank15);

                Grupos E(nome16,  0, rank16);
                E.Atribuir(nome17, 1, rank17);
                E.Atribuir(nome18, 2, rank18);
                E.Atribuir(nome19, 3, rank19);

                Grupos F(nome20,  0, rank20);
                F.Atribuir(nome21, 1, rank21);
                F.Atribuir(nome22, 2, rank22);
                F.Atribuir(nome23, 3, rank23);

                Grupos G(nome24,  0, rank24);
                G.Atribuir(nome25, 1, rank25);
                G.Atribuir(nome26, 2, rank26);
                G.Atribuir(nome27, 3, rank27);

                Grupos H(nome28,  0, rank28);
                H.Atribuir(nome29, 1, rank29);
                H.Atribuir(nome30, 2, rank30);
                H.Atribuir(nome31, 3, rank31);

                /*for( k=0;k<48;k++ ){
                        qDebug() << resultados[k][0] << resultados[k][1] ;

                 }*/


                //criacao dos confrontos
                A.Partida(1, 2, resultados[0][0], resultados[0][1]);
                A.Partida(0, 3, resultados[1][0], resultados[1][1]);
                A.Partida(0, 2, resultados[2][0], resultados[2][1]);
                A.Partida(1, 3, resultados[3][0], resultados[3][1]);
                A.Partida(0, 1, resultados[4][0], resultados[4][1]);
                A.Partida(2, 3, resultados[5][0], resultados[5][1]);


                B.Partida(1, 2, resultados[6][0], resultados[6][1]);
                B.Partida(0, 3, resultados[7][0], resultados[7][1]);
                B.Partida(0, 2, resultados[8][0], resultados[8][1]);
                B.Partida(1, 3, resultados[9][0], resultados[9][1]);
                B.Partida(0, 1, resultados[10][0], resultados[10][1]);
                B.Partida(2, 3, resultados[11][0], resultados[11][1]);

                C.Partida(1, 2, resultados[12][0], resultados[12][1]);
                C.Partida(0, 3, resultados[13][0], resultados[13][1]);
                C.Partida(0, 2, resultados[14][0], resultados[14][1]);
                C.Partida(1, 3, resultados[15][0], resultados[15][1]);
                C.Partida(0, 1, resultados[16][0], resultados[16][1]);
                C.Partida(2, 3, resultados[17][0], resultados[17][1]);

                D.Partida(1, 2, resultados[18][0], resultados[18][1]);
                D.Partida(0, 3, resultados[19][0], resultados[19][1]);
                D.Partida(0, 2, resultados[20][0], resultados[20][1]);
                D.Partida(1, 3, resultados[21][0], resultados[21][1]);
                D.Partida(0, 1, resultados[22][0], resultados[22][1]);
                D.Partida(2, 3, resultados[23][0], resultados[23][1]);

                E.Partida(1, 2, resultados[24][0], resultados[24][1]);
                E.Partida(0, 3, resultados[25][0], resultados[25][1]);
                E.Partida(0, 2, resultados[26][0], resultados[26][1]);
                E.Partida(1, 3, resultados[27][0], resultados[27][1]);
                E.Partida(0, 1, resultados[28][0], resultados[28][1]);
                E.Partida(2, 3, resultados[29][0], resultados[29][1]);

                F.Partida(1, 3, resultados[30][0], resultados[30][1]);
                F.Partida(0, 2, resultados[31][0], resultados[31][1]);
                F.Partida(0, 3, resultados[32][0], resultados[32][1]);
                F.Partida(1, 2, resultados[33][0], resultados[33][1]);
                F.Partida(0, 1, resultados[34][0], resultados[34][1]);
                F.Partida(3, 2, resultados[35][0], resultados[35][1]);

                G.Partida(1, 2, resultados[36][0], resultados[36][1]);
                G.Partida(0, 3, resultados[37][0], resultados[37][1]);
                G.Partida(0, 2, resultados[38][0], resultados[38][1]);
                G.Partida(1, 3, resultados[39][0], resultados[39][1]);
                G.Partida(0, 1, resultados[40][0], resultados[40][1]);
                G.Partida(2, 3, resultados[41][0], resultados[41][1]);

                H.Partida(1, 2, resultados[42][0], resultados[42][1]);
                H.Partida(0, 3, resultados[43][0], resultados[43][1]);
                H.Partida(0, 2, resultados[44][0], resultados[44][1]);
                H.Partida(1, 3, resultados[45][0], resultados[45][1]);
                H.Partida(0, 1, resultados[46][0], resultados[46][1]);
                H.Partida(2, 3, resultados[47][0], resultados[47][1]);
                //////////////////////////////////////////
                ///
                ///   //calculos em porcentagem
                ///
                /// //////////////////////////////////////

                primeiro[0] = A.getPrimeiro();
                primeiro[1] = B.getPrimeiro();
                primeiro[2] = C.getPrimeiro();
                primeiro[3] = D.getPrimeiro();
                primeiro[4] = E.getPrimeiro();
                primeiro[5] = F.getPrimeiro();
                primeiro[6] = G.getPrimeiro();
                primeiro[7] = H.getPrimeiro();

                segundo[0] = A.getSegundo();
                segundo[1] = B.getSegundo();
                segundo[2] = C.getSegundo();
                segundo[3] = D.getSegundo();
                segundo[4] = E.getSegundo();
                segundo[5] = F.getSegundo();
                segundo[6] = G.getSegundo();
                segundo[7] = H.getSegundo();


                x[0] = A.getX(primeiro[0]);
                x[1] = B.getX(primeiro[1]);
                x[2] = C.getX(primeiro[2]);
                x[3] = D.getX(primeiro[3]);
                x[4] = E.getX(primeiro[4]);
                x[5] = F.getX(primeiro[5]);
                x[6] = G.getX(primeiro[6]);
                x[7] = H.getX(primeiro[7]);
                x[8] = A.getX(segundo[0]);
                x[9] = B.getX(segundo[1]);
                x[10] = C.getX(segundo[2]);
                x[11] = D.getX(segundo[3]);
                x[12] = E.getX(segundo[4]);
                x[13] = F.getX(segundo[5]);
                x[14] = G.getX(segundo[6]);
                x[15] = H.getX(segundo[7]);

                for(int w = 0; w<16; w++){
                xTOTAL += x[w];
                // qDebug()<<"X:"<<x[w];
                }
                for (int p = 0; p < 16; p++){
                   // calculo da porcentagem
                    PORCENTAGEM[p] = (x[p]*(double)100)/xTOTAL;
                }

                // Debug dos primeros de cada grupo e o porcentagem de cada um deles de ganahr de 100
                    QString aux = QString::fromStdString( A.getTime(primeiro[0]));
                    qDebug() << aux << " "  << PORCENTAGEM[0] ;
                    aux = QString::fromStdString( B.getTime(primeiro[1]));
                    qDebug() << aux << " "  << PORCENTAGEM[1] ;
                     aux = QString::fromStdString( C.getTime(primeiro[2]));
                    qDebug() << aux << " "  << PORCENTAGEM[2] ;
                     aux = QString::fromStdString( D.getTime(primeiro[3]));
                    qDebug() << aux << " "  << PORCENTAGEM[3] ;
                     aux = QString::fromStdString( E.getTime(primeiro[4]));
                    qDebug() << aux << " "  << PORCENTAGEM[4] ;
                     aux = QString::fromStdString( F.getTime(primeiro[5]));
                    qDebug() << aux << " "  << PORCENTAGEM[5] ;
                     aux = QString::fromStdString( G.getTime(primeiro[6]));
                    qDebug() << aux << " "  << PORCENTAGEM[6] ;
                     aux = QString::fromStdString( H.getTime(primeiro[7]));
                    qDebug() << aux << " "  << PORCENTAGEM[7] ;
                     aux = QString::fromStdString( A.getTime( segundo[0]));
                    qDebug() << aux << " "  << PORCENTAGEM[8] ;
                     aux = QString::fromStdString( B.getTime( segundo[1]));
                    qDebug() << aux << " "  << PORCENTAGEM[9] ;
                     aux = QString::fromStdString( C.getTime(segundo[2]));
                    qDebug() << aux << " "  << PORCENTAGEM[10];
                     aux = QString::fromStdString( D.getTime(segundo[3]));
                    qDebug() << aux << " "  << PORCENTAGEM[11] ;
                     aux = QString::fromStdString( E.getTime(segundo[4]));
                    qDebug() << aux << " "  << PORCENTAGEM[12] ;
                     aux = QString::fromStdString( F.getTime(segundo[5]));
                    qDebug() << aux << " "  << PORCENTAGEM[13] ;
                     aux = QString::fromStdString( G.getTime(segundo[5]));
                    qDebug() << aux << " "  << PORCENTAGEM[14] ;
                     aux = QString::fromStdString( H.getTime(segundo[7]));
                    qDebug() << aux << " "  << PORCENTAGEM[15] ;


                    /////////////////////////////////////////
                    /// pegar o time com maior porcentagem
                    int vencedor;

                    for(int i = 0; i<15; i++){
                        if(PORCENTAGEM[i] > PORCENTAGEM[vencedor]){
                            vencedor = i;
                            //qDebug()<<PORCENTAGEM[vencedor];
                        }
                    }
                    if(PORCENTAGEM[15] > PORCENTAGEM[vencedor]){
                        vencedor = 15;
                    }

                    std::string SELECOES[16];
                    SELECOES[0] = A.getTime(primeiro[0]);
                    SELECOES[1] = B.getTime(primeiro[1]);
                    SELECOES[2] = C.getTime(primeiro[2]);
                    SELECOES[3] = D.getTime(primeiro[3]);
                    SELECOES[4] = E.getTime(primeiro[4]);
                    SELECOES[5] = F.getTime(primeiro[5]);
                    SELECOES[6] = G.getTime(primeiro[6]);
                    SELECOES[7] = H.getTime(primeiro[7]);
                    SELECOES[8] = A.getTime(segundo[0]);
                    SELECOES[9] = B.getTime(segundo[1]);
                    SELECOES[10] = C.getTime(segundo[2]);
                    SELECOES[11] = D.getTime(segundo[3]);
                    SELECOES[12] = E.getTime(segundo[4]);
                    SELECOES[13] = F.getTime(segundo[5]);
                    SELECOES[14] = G.getTime(segundo[6]);
                    SELECOES[15] = H.getTime(segundo[7]);

                    Vencedor = QString::fromStdString( SELECOES[vencedor]);
                    qDebug() << "VENCEDOR: " << Vencedor << " " << PORCENTAGEM[vencedor] ;

}
