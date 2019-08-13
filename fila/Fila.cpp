//Renata Yoko Guima
//Fila.cpp

#include "Fila.h"

using namespace std;

FILA::FILA()
{
    cabeca = NULL;
}

int FILA::Insere(int numero)
{
    int retorno;
    NO *percorre, *no;

    no = new NO;

    if (no == NULL)
    {
         retorno = CHEIA;
    }
    else
    {
         no->Set(numero);
         if (cabeca == NULL)
         {
              no->SetProximo(cabeca);
              cabeca = no;
              retorno = OK;
         }
         else
         {
             for ( percorre = cabeca;((percorre->GetProximo()) != NULL);percorre = percorre->GetProximo());
                   percorre->SetProximo(no);
                   no->SetProximo(NULL);
                   retorno = OK;
         }
    }
    return(retorno);
}

int FILA::Retira()
{
    int retorno;
    NO *no;
    no = cabeca;

    if (no == NULL)
    {
         retorno = VAZIA;
    }
    else
    {
        if (no->GetProximo() == NULL)
           cabeca = NULL;
        else
           cabeca = no->GetProximo();
        delete no;
        retorno = OK;
    }
    return (retorno);
}


int FILA::Imprime()
{
    int retorno;
    NO *percorre, *no;
    if (cabeca == NULL)
    {
         retorno = VAZIA;
    }
    else
    {
         if (cabeca->GetProximo() == NULL)
         {
              cout << cabeca->Get() << endl;
         }
         else
         {
              cout << "IMPRIMINDO FILA" << endl;
              for ( percorre = cabeca;((percorre->GetProximo()) != NULL);percorre = percorre->GetProximo())
                   cout << percorre->Get() << endl;
              cout << percorre->Get() << endl;
         }
    retorno = OK;
    }
    return(retorno);
}



