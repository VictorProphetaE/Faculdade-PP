#include <iostream>
#include <cstdlib>
#include "Fila.h"

/**Função  principal*/
int main()
{
    int option=0;
    int x,tam;
    FILA fila;

    system("cls");
    cout<<"Entre com o tamanho da FIFO"<<endl;
    cin>>tam;
    system("cls");
    for(int i = 0;i<tam;i++)
    {
        x = rand() % 50;
        fila.Insere(x);
    }
    do{
        cout<<"************"<<endl;
        cout<<"Menu"<<endl;
        cout<<"1-Inserir"<<endl;
        cout<<"2-Imprimir"<<endl;
        cout<<"3-Excluir"<<endl;
        cout<<"4-Sair"<<endl;
        cin>>option;
        system("cls");
        switch(option)
        {
            case 1:
                x=tam+1;
                cout<<"Entre com um numero:"<<endl;
                cin>>x;
                fila.Insere(x);
                system("pause");
            break;
            case 2:
                fila.Imprime();
                system("pause");
            break;
            case 3:
                fila.Retira();
                fila.Imprime();
                system("pause");
            break;
            case 4:
            break;
            default:
                system("cls");
                cout<<"Opcao  invalida!"<<endl;
                system("pause");
            break;
            for(int i = 0;i<=tam;i++)
            {
                fila.Retira();
            }
        }
    }while(option  !=  4);

    return 0;

}
