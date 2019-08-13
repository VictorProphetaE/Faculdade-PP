
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;



#include "Car.h"



//--------------------------------------------------------------------

Car::Car()

{

	setMakeModel("No Car Selected");

	setCarYear(2000);

	setCategory(1);

}

//--------------------------------------------------------------------

Car::Car(char *MM, int Y, int Cat)

{

	setMakeModel(MM);

	setCarYear(Y);

	setCategory(Cat);

}

//--------------------------------------------------------------------

Car::~Car()

{

//	delete [] MakeModel;

}

//--------------------------------------------------------------------

void Car::setMakeModel(const char *m)

{

	MakeModel = new char[strlen(m) + 1];

	strcpy(MakeModel, m);

}

//--------------------------------------------------------------------

char* Car::getMakeModel() const

{

	return MakeModel;

}

//--------------------------------------------------------------------

void Car::setCarYear(const int y)

{

	CarYear = y;

}

//--------------------------------------------------------------------

int Car::getCarYear() const

{

	return CarYear;

}

//--------------------------------------------------------------------

void Car::setCategory(const int c)

{

	Category = c;

}

//--------------------------------------------------------------------

int Car::getCategory() const

{

	return Category;

}

