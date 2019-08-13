

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#pragma hdrstop



#include "Customer.h"



//---------------------------------------------------------------------------

char *Customer::FullName() const

{

    char *FName = new char[40];

    strcpy(FName, FirstName);

    strcat(FName, " ");

    strcat(FName, LastName);



    return FName;

}

//---------------------------------------------------------------------------

Customer::Customer()

    : ZIPCode(0)

{

    FirstName = new char[20];

    strcpy(FirstName, "John");

    LastName  = new char[20];

    strcpy(LastName, "Doe");

    Address   = new char[40];

    strcpy(Address, "123 Main Street Apt A");

    City      = new char[32];

    strcpy(City, "Great City");

    State     = new char[30];

    strcpy(State, "Our State");

}

//---------------------------------------------------------------------------

Customer::Customer(char * FName, char * LName)

    : ZIPCode(0)

{

    FirstName = new char[strlen(FName) + 1];

    strcpy(FirstName, FName);

    LastName  = new char[strlen(LName) + 1];

    strcpy(LastName, LName);

    Address   = new char[40];

    strcpy(Address, "123 Main Street Apt A");

    City      = new char[32];

    strcpy(City, "Great City");

    State     = new char[30];

    strcpy(State, "Our State");

}

//---------------------------------------------------------------------------

Customer::Customer(char *FName, char *LName, char *Adr,

                       char *Ct, char *St, long  ZIP)

    : ZIPCode(ZIP)

{

    FirstName = new char[strlen(FName) + 1];

    strcpy(FirstName, FName);

    LastName  = new char[strlen(LName) + 1];

    strcpy(LastName, LName);

    Address   = new char[40];

    strcpy(Address, Adr);

    City      = new char[32];

    strcpy(City, Ct);

    State     = new char[30];

    strcpy(State, St);

}

//---------------------------------------------------------------------------

Customer::Customer(const Customer &Pers)

    : ZIPCode(Pers.ZIPCode)

{

    FirstName = new char[strlen(Pers.FirstName) + 1];

    strcpy(FirstName, Pers.FirstName);

    LastName  = new char[strlen(Pers.LastName) + 1];

    strcpy(LastName, Pers.LastName);

    Address   = new char[strlen(Pers.Address) + 1];

    strcpy(Address, Pers.Address);

    City      = new char[strlen(Pers.City) + 1];

    strcpy(City, Pers.City);

    State     = new char[strlen(Pers.State) + 1];

    strcpy(State, Pers.State);

}

//---------------------------------------------------------------------------

void Customer::setFirstName(const char *FN)

{

    strcpy(FirstName, FN);

}

//---------------------------------------------------------------------------

void Customer::setLastName(const char *LN)

{

    strcpy(LastName, LN);

}

//---------------------------------------------------------------------------

void Customer::setAddress(const char *Adr)

{

    strcpy(Address, Adr);

}

//---------------------------------------------------------------------------

void Customer::setCity(const char *CT)

{

    strcpy(City, CT);

}

//---------------------------------------------------------------------------

void Customer::setState(const char *St)

{

    strcpy(State, St);

}

//---------------------------------------------------------------------------

void Customer::setZIPCode(const long ZIP)

{

    ZIPCode = ZIP;

}

//---------------------------------------------------------------------------

Customer::~Customer()

{

    delete [] FirstName;

    delete [] LastName;

    delete [] Address;

    delete [] City;

    delete [] State;

}
