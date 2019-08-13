/**
Descrição Pequeno sistema bancario

Nota: GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Paradigmas de Programação
Prof: Msc. Marcos Alves Mariano
Data de Criação: 27/04/2015
Data Modificação: 30/04/2015
*/

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <cstdlib>

using namespace std;

class conta
{
	int numerodaconta;
	int telefone;
	char nome[50],cpf[15], rg[15],endereco[20];
	int deposito;
	char tipo;
public:
	void criar_conta();
	void mostrar_conta() const;
	void dep(int);
	void saque(int);
	void report() const;
	int retnumerodaconta() const;
	int retdeposito() const;
	char rettipo() const;
};

void conta::criar_conta()
{
    numerodaconta++;
	cout<<"O seu numero da conta e:"<<endl<<numerodaconta<<endl;
	cout<<"Entre com o nome do cliente : "<<endl;
	cin.ignore();
	cin.getline(nome,50);
	cout<<"Entre com o cpf"<<endl;
	cin.ignore();
	cin.getline(cpf,15);
    cout<<"Entre com o rg"<<endl;
	cin.ignore();
	cin.getline(rg,15);
    cout<<"Entre com o endereco"<<endl;
	cin.ignore();
	cin.getline(endereco,20);
    cout<<"Entre com o telefone"<<endl;
	cin>>telefone;
	cout<<"Entre com o tipo da conta (C para corrente/P para poupanca): "<<endl;
	cin>>tipo;
	tipo=toupper(tipo);
	cout<<"Entre com a qntidade inicial de dinheiro(>=500 para poupanca e >=1000 corrente): "<<endl;
	cin>>deposito;
}

void conta::mostrar_conta() const
{
	cout<<"Numero da conta: "<<numerodaconta<<endl;
	cout<<"Nome : "<<nome<<endl;
    cout<<"CPF : "<<cpf<<endl;
	cout<<"RG : "<<rg<<endl;
    cout<<"Endereco : "<<endereco<<endl;
	cout<<"Telefone : "<<telefone<<endl;
	cout<<"Tipo da conta : "<<tipo<<endl;
	cout<<"Dinheiro na conta : "<<deposito<<endl;
}

void conta::dep(int x)
{
	deposito+=x;
}

void conta::saque(int x)
{
	deposito-=x;
}

void conta::report() const
{
	cout<<numerodaconta<<setw(10)<<" "<<nome<<setw(10)<<" "<<tipo<<setw(6)<<deposito<<endl;
}

int conta::retnumerodaconta() const
{
	return numerodaconta;
}

int conta::retdeposito() const
{
	return deposito;
}

char conta::rettipo() const
{
	return tipo;
}

void abrir_conta();
void mostrar_saldo(int);
void deletar_conta(int);
void mostrar_contas();
void deposito_e_saque(int, int);

int main()
{
	char opcao;
	int num;
	do
	{
    system("cls");
		cout<<"Menu principal"<<endl;
		cout<<"1-Nova conta"<<endl;
		cout<<"2-Deposito"<<endl;
		cout<<"3-Fazer saque"<<endl;
		cout<<"4-Mostrar Saldo"<<endl;
		cout<<"5-Mostrar todas as contas"<<endl;
		cout<<"6-Fechar uma conta"<<endl;
		cout<<"7-Sair"<<endl;
		cin>>opcao;
		system("cls");
		switch(opcao)
		{
		case '1':
			abrir_conta();
			break;
		case '2':
			cout<<"Entre com o numero da conta : "<<endl;
			cin>>num;
			deposito_e_saque(num, 1);
			break;
		case '3':
			cout<<"Entre com o numero da conta : "<<endl;
			cin>>num;
			deposito_e_saque(num, 2);
			break;
		case '4':
			cout<<"Entre com o numero da conta : "<<endl;
			cin>>num;
			mostrar_saldo(num);
			break;
		case '5':
			mostrar_contas();
			break;
		case '6':
			cout<<"Entre com o numero da conta : "<<endl;
			cin>>num;
			deletar_conta(num);
			break;
		 case '7':
			break;
		 default :cout<<"Selecione uma das opcoes de(1-7)"<<endl;
		}
		cin.ignore();
		cin.get();
	}while(opcao != '7');
	return 0;
}

void abrir_conta()
{
	conta ac;
	ofstream outFile;
	outFile.open("conta.dat",ios::binary|ios::app);
	ac.criar_conta();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(conta));
	outFile.close();
}

void mostrar_saldo(int n)
{
	conta ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("conta.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Falha ao abrir o arquivo!!"<<endl;
		return;
	}
	cout<<"\nDetalhes da conta\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(conta)))
	{
		if(ac.retnumerodaconta()==n)
		{
			ac.mostrar_conta();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"Numero da conta inexistente"<<endl;
}

void deletar_conta(int n)
{
	conta ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("conta.dat",ios::binary);
	if(!inFile)
	{
        cout<<"Falha ao abrir o arquivo!!"<<endl;
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(conta)))
	{
		if(ac.retnumerodaconta()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(conta));
		}
	}
	inFile.close();
	outFile.close();
	remove("conta.dat");
	rename("Temp.dat","conta.dat");
	cout<<"Conta deletada"<<endl;
}

void mostrar_contas()
{
	conta ac;
	ifstream inFile;
	inFile.open("conta.dat",ios::binary);
	if(!inFile)
	{
        cout<<"Falha ao abrir o arquivo!!"<<endl;
		return;
	}
	cout<<"Lista de contas"<<endl;
	cout<<"===================================================="<<endl;
	cout<<"No.      nome           tipo  Saldo\n"<<endl;
	cout<<"===================================================="<<endl;
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(conta)))
	{
		ac.report();
	}
	inFile.close();
}

void deposito_e_saque(int n, int option)
{
	int amt;
	bool found=false;
	conta ac;
	fstream File;
	File.open("conta.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
        cout<<"Falha ao abrir o arquivo!!"<<endl;
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(conta));
		if(ac.retnumerodaconta()==n)
		{
			ac.mostrar_conta();
			if(option==1)
			{
				cout<<endl<<"Entre com a qntidade a ser depositado"<<endl;
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<endl<<"Entre com a qntidade a se sacado"<<endl;
				cin>>amt;
				int bal=ac.retdeposito()-amt;
				if((bal<500 && ac.rettipo()=='S') || (bal<1000 && ac.rettipo()=='C'))
					cout<<"Dinheiro insuficiente"<<endl;
				else
					ac.saque(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(conta));
			cout<<"Conta atualizada"<<endl;
			found=true;
	       }
         }
	File.close();
	if(found==false)
        cout<<"Numero da conta inexistente"<<endl;
}
