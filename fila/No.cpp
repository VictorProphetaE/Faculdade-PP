//Renata Yoko Guima
//No.cpp

#include "No.h"

NO::NO()
{
}

int NO::Get()
{ 
    return(numero);
}

void NO::Set(int num)
{
    numero = num;
}

void NO::SetProximo(NO *prox)
{
    proximo = prox;
}

NO * NO::GetProximo()
{
     return(proximo);
}

NO::~NO()
{
    proximo = NULL;
}
