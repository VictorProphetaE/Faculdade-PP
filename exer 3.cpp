/**
Descrição: Pequeno serviços de correio expresso

Nota: GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Paradigmas de Programação
Prof: Msc. Marcos Alves Mariano
Data de Criação: 24/04/2015
Data Modificação: 30/04/2015
*/

#include <iostream>
#include <string>

using namespace std;

class Package
{
private:
	string nome, cidade, estado, remetente, destinatario;
    int CEP;
    string endereco;
    float peso;
    double cost;

public:
    void setnome(string nome);
    void setcidade(string cidade);
    void setestado(string estado);
    void setCEP(int CEP);
    void setendereco(string endereco);
    void setremetente(string remetente);
    void setdestinatario(string destinatario);
    string getnome()
	{
		return nome;
	}
    string getcidade()
	{
		return cidade;
	}
    string getestado()
	{
		return estado;
	}
	int getCEP()
	{
		return CEP;
	}
	string getendereco()
	{
		return endereco;
	}

	string getremetente()
	{
		return remetente;
	}
	string getdestinatario()
	{
		return destinatario;
	}

double calculateCost(float peso,double custototal)
{
	double z;
    z = peso * custototal;

    cout<< "Custo base = " <<z << endl<<endl;
    return z;
}
};

void Package::setnome(string n)
{
	nome = n;
}

void Package::setcidade(string c)
{
	cidade = c;
}
void Package::setestado(string s)
{
	estado = s;
}
void Package::setCEP (int zp)
{
	CEP = zp;
}
void Package::setendereco(string adr)
{
	endereco = adr;
}
void Package::setremetente(string sen)
{
	remetente = sen;
}
void Package::setdestinatario(string rec)
{
	destinatario = rec;
}

class TwoPackage: public Package
{
public:
	double custodetransporte(float peso, double custototal, double taxafixa)

	{
		double z;

		z= calculateCost(peso,custototal) + taxafixa;
		cout<< "O custo  do dois Pacote e = " <<z << endl;
		return z;
	}
private:
	double taxafixa;
};

class OvernightPackage: public Package
{
public:
	double calcCostOvernight(float peso,double custototal,double custoadicional )
	{
		double z;
		z = calculateCost(peso, custototal)+(custoadicional * peso);

		cout<< "O custo da entrega noturna e = " <<z << endl;
		return z;
	}
private:
	double overnightCost;
};

int main()
{
	int i;
	string nomecliente,enderecocliente,cidade,estado,remetenteendereco,destinatarioendereco;
    float pesodopacote;
    string cidadedocliente;
    double custototal;
    double taxafixa;
    double custoadicional;
    string estadodocliente;
    int CEPdocliente;

	Package base;
    TwoPackage twoday;
    OvernightPackage overnight;

    cout<<"Entre com o nome do cliente "<<endl;
    cin>>nomecliente;
    cout<<endl;
    base.setnome(nomecliente);

    cout<<"Entre com o endereco do cliente"<<endl;
    cin>>enderecocliente;
    cout<<endl;
    base.setendereco(enderecocliente);

    cout<<"Entre com a cidade do cliente"<<endl;
    cin>>cidadedocliente;
    cout<<endl;
    base.setcidade(cidadedocliente);

    cout<<"Entre com o estado do cliente"<<endl;
    cin>>estadodocliente;
    cout<<endl;
    base.setestado(estadodocliente);

    cout<<"Entre com o CEP do cliente"<<endl;
    cin>>CEPdocliente;
    cout<<endl;
    base.setCEP(CEPdocliente);

    cout<<"Entre com o peso"<<endl;
    cin>>pesodopacote;
    cout<<endl;
    cout<<"Entre com o custo"<<endl;
    cin>>custototal;
    cout<<endl;

    cout<<"Entre com a escolha do menu abaixo:"<<endl;
    cout<<"   1- Calcular a base de custo  "<<endl;
    cout<<"   2- Calcular o custo de dois dias "<<endl;
    cout<<"   3- Calcular o custo de entrega noturna"<<endl;
    cin>>i;
    cout<<endl;

	switch (i)
	{
	case 1 :
		base.calculateCost(pesodopacote,custototal);
		break;

	case 2 :
		cout<<"Entre com o plano de custo"<<endl;
        cin>>taxafixa;
		twoday.custodetransporte(pesodopacote,custototal,taxafixa);
        break;

	case 3 :
		cout<<"Entre com o custo adicional"<<endl;
        cin>>custoadicional;
        overnight.calcCostOvernight(pesodopacote,custototal,custoadicional);
        break;

	default:
		cout<<"Escolha invalida "<<endl;
	}

	cout<<"Entre com o endereco do remetente "<<endl;
    cin>>remetenteendereco;
    cout<<endl;
    base.setremetente( remetenteendereco);

    cout<<"Entre com o endereco do destinatario"<<endl;
    cin>>destinatarioendereco;
    cout<<endl;
    base.setdestinatario(destinatarioendereco);

    cout<<"endereco a partir:"<< remetenteendereco<<endl;
    cout<<"Para:"<<destinatarioendereco<<endl;

	//system ("pause");
	return 0;
}
