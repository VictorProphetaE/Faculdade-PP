//Renata Yoko Guima
//no.h

#include <iostream>

#ifndef NO_H
#define NO_H

class NO{
    int numero;
    NO * proximo;
 public:
    NO();
    int Get();
    void Set(int num);
    void SetProximo(NO *prox);
    NO * GetProximo();
    ~NO();
};

#endif
