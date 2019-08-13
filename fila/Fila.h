//Renata Yoko Guima
//Fila.h

#ifndef FILA_H
#define FILA_H

#include <iostream>
using namespace std;

#include "No.h"

//Estados
#define OK 0
#define VAZIA 1
#define CHEIA 2

class FILA{
    NO *cabeca;
 public:
    FILA();
    int Insere(int numero);
    int Retira();
    int Imprime();
};  

#endif
