/**
Descrição Jogo da Velha

Nota: GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Paradigmas de Programação
Prof: Msc. Marcos Alves Mariano
Data de Criação: 11/04/2015
Data Modificação: 15/04/2015
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

class jogodavelha
{
    private:
        int array[3][3];
        int marcacao;
    public:
        void grade(void);
        int Marcacao(int x) {marcacao=x;};
        jogodavelha();
        void jogadas();
        bool campo_cheio();
        bool campo_vazio(int y, int x);
        bool procuraremarcar(int x,int y);
        bool linha();
        bool coluna();
        bool diagonal();
        bool ganhador();
        void limpar();
};

jogodavelha::jogodavelha()
{
    int i,j;
        for (i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                array[i][j]=0;
}

bool jogodavelha::campo_vazio(int y, int x)
{
        if(array[y][x]==0)
            return true;
        return false;
}

bool jogodavelha::campo_cheio()
{
    int i,j;
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(campo_vazio(i,j))
                return false;
    return true;
}

bool jogodavelha::procuraremarcar(int x,int y)
{
        if(campo_vazio(y,x))
        {
            array[y][x]=marcacao;
            return true;
        }
        return false;
}

void jogodavelha::grade()
{
    int i,j;
    cout << " ";
    for (i = 0; i < 3; i++)
        cout<<" "<<i;
    cout << "\n  - - -\n";
    for (i = 0; i < 3; i++)
    {
        cout << i;
        for(j = 0; j < 3; j++)
        {
            cout<<"|"<<array[i][j];
        }
        cout << "|\n  - - -\n";
    }
}

bool jogodavelha::linha()
{
    int i;
    for (i = 0; i < 3; i++)
        if(!campo_vazio(i,0)&&!campo_vazio(i,1)&&!campo_vazio(i,2))
        if(array[i][0]==array[i][1]&&array[i][0]==array[i][2])
            return true;
    return false;
}

bool jogodavelha::coluna()
{
    int i;
    for (i = 0; i < 3; i++)
        if(!campo_vazio(0,i)&&!campo_vazio(1,i)&&!campo_vazio(2,i))
        if(array[0][i]==array[1][i]&&array[0][i]==array[2][i])
            return true;
    return false;
}

bool jogodavelha::diagonal()
{

    if(!campo_vazio(1,1))
    {
        if(array[2][0]==array[1][1]&&array[1][1]==array[0][2])
            return true;
            if(array[0][0]==array[1][1]&&array[0][0]==array[2][2])
            return true;
    }
    return false;
}

bool jogodavelha::ganhador()
{
    return linha()||coluna()||diagonal();
}

void jogodavelha::limpar()
{
    int i,j;
        for (i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                array[i][j]=0;
}

int main()
{
    int marcacao,i=0;
    int x,y;
    int opcao;
    jogodavelha w;
    while(opcao!=2)
    {
        i=0;
        w.grade();
        while(!w.campo_cheio())
        {
            i++;
            marcacao=i%2==0?2:1;
            cout<<"Turno "<<marcacao<<" Coordenadas x:"<<endl;
            cin>>x;
            cout<<"Coordenada y:"<<endl;
            cin>>y;
            if(x>2||y>2)
            {
                cout<<"Coordenada inexistente"<<endl;
                i--;
                continue;
            }
            w.Marcacao(marcacao);
            if(w.procuraremarcar(x,y))
                w.grade();
            else
            {
                cout<<"Esta cheio"<<endl;
                i--;
            }
            if(w.ganhador())
            {
                cout<<"Ganhador "<<marcacao<<endl;
                system("pause");
                break;
            }
        }
        system("cls");
        cout<<"Deseja outra partida"<<endl;
        cout<<"1-sim"<<endl;
        cout<<"2-nao"<<endl;
        cin>>opcao;
        w.limpar();
    }
    return 0;
}
