#include <iostream>

#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

#include "Invoice.h"

Invoice::Invoice()
{

	setTankLevel("Empty");

	setCarCondition("Good");

}

Invoice::~Invoice()

{

}

Customer Invoice::CustomerRegistration()

{

    char FName[20], LName[20], Addr[40], CT[32], St[30];

    long ZC = 0;


    cout << "Enter Customer Information\n";
    cout << "First Name: "; cin >> FName;
    cout << "Last Name:  "; cin >> LName;
    cout << "Address:    "; cin >> ws;
    cin.getline(Addr, 40);
    cout << "City:       ";
    cin.getline(CT, 32);
    cout << "State:      ";
    cin.getline(St, 30);
    cout << "Zip Code:   "; cin >> ZC;

	Customer Cust(FName, LName, Addr, CT, St, ZC);

	return Cust;
}

Car Invoice::CarSelection()
{
	int CarType, ModelChosen;
	char strCarSelected[20];
	int CarSelectedYear = 2000;

	cout << "What type of car would you like to rent?";
	do {
		cout << "\n1 - Economy   | 2 - Compact  | 3 - Standard"
			 << "\n4 - Full Size | 5 - Mini Van | 6 - Sports Utility";
		cout << "\nYour Choice: ";
		cin >> CarType;
		if( CarType < 1 || CarType > 6 )
			cout << "\nPlease type a number between 1 and 6";
	} while(CarType < 1 || CarType > 6);

	switch(CarType)
	{
	case ctEconomy:
		cout << "\nFor the Economy type, we have:"
			 << "\n1 - Daewoo Lanos | 2 - Cheverolet Metro";
		cout << "\nWhich one would you prefer? ";
		cin >> ModelChosen;
		if(ModelChosen == 1)
		{
			strcpy(strCarSelected, "Daewoo Lanos");
			CarSelectedYear = 1999;
		}
		else
		{
			strcpy(strCarSelected, "Chevrolet Metro");
			CarSelectedYear = 1998;
		}
		break;
	case ctCompact:
		cout << "\nFor the Compact type, we have:"
			 << "\n1 - Chevrolet Cavalier | 2 - Dogde Neon"
			 << "\n3 - Nissan Sentra      | 4 - Toyota Corolla";
		cout << "\nWhich one would you prefer? ";
		cin >> ModelChosen;
		if(ModelChosen == 1)
		{
			strcpy(strCarSelected, "Chevrolet Cavalier");
			CarSelectedYear = 1999;
		}
		else if(ModelChosen == 2)
		{
			strcpy(strCarSelected, "Dodge Neon");
			CarSelectedYear = 2001;
		}

		else if(ModelChosen == 3)

		{

			strcpy(strCarSelected, "Nissan Sentra");

			CarSelectedYear = 1998;

		}

		else

		{

			strcpy(strCarSelected, "Toyota Corrolla");

			CarSelectedYear = 2002;

		}

		break;



	case ctStandard:

		cout << "\nFor the Standard type, we have:"

			 << "\n1 - Chevrolet Monte Carlo | 2 - Toyota Camri";

		cout << "\nWhich one would you prefer? ";

		cin >> ModelChosen;



		if(ModelChosen == 1)

		{

			strcpy(strCarSelected, "Chevrolet Monte Carlo");

			CarSelectedYear = 2000;

		}

		else

		{

			strcpy(strCarSelected, "Toyota Camri");

			CarSelectedYear = 1998;

		}

		break;



	case ctFullSize:

		cout << "\nFor the Full Size type, we have:"

			 << "\n1 - Chrysler 300M | 2 - Buick Century | 3 - Infinity I30";

		cout << "\nWhich one would you prefer? ";

		cin >> ModelChosen;



		if(ModelChosen == 1)

		{

			strcpy(strCarSelected, "Chrysler 300M");

			CarSelectedYear = 2000;

		}

		else if(ModelChosen == 2)

		{

			strcpy(strCarSelected, "Buick Century");

			CarSelectedYear = 1999;

		}

		else

		{

			strcpy(strCarSelected, "Infinity I30");

			CarSelectedYear = 2003;

		}

		break;



	case ctMiniVan:

		cout << "\nFor the Mini-Van type, we have:"

			 << "\n1 - Dodge Caravan   | 2 - Dodge Caravan"

			 << "\n3 - Pontiac Montana | 4 - Pontiac Montana | 5 - Chevrolet Astro Van";

		cout << "\nWhich one would you prefer? ";

		cin >> ModelChosen;



		if(ModelChosen == 1)

		{

			strcpy(strCarSelected, "Dodge Caravan");

			CarSelectedYear = 2001;

		}

		else if(ModelChosen == 2)

		{

			strcpy(strCarSelected, "Dodge Caravan");

			CarSelectedYear = 2003;

		}

		else if(ModelChosen == 3)

		{

			strcpy(strCarSelected, "Pontiac Montana");

			CarSelectedYear = 2003;

		}

		else

		{

			strcpy(strCarSelected, "Chevrolet Astro Van");

			CarSelectedYear = 2000;

		}

		break;



	case ctSUV:

		cout << "\nFor the Sport Utility type, we have:"

			 << "\n1 - GMC Jimmy        | 2 - Jeep Cherokee"

			 << "\n3 - Chevrolet Blazer | 4 - Toyota Pathfinder";

		cout << "\nWhich one would you prefer? ";

		cin >> ModelChosen;



		if(ModelChosen == 1)

		{

			strcpy(strCarSelected, "GMC Jimmy");

			CarSelectedYear = 1998;

		}

		else if(ModelChosen == 2)

		{

			strcpy(strCarSelected, "Jeep Cherokee");

			CarSelectedYear = 2003;

		}

		else if(ModelChosen == 3)

		{

			strcpy(strCarSelected, "Chevrolet Blazer");

			CarSelectedYear = 2001;

		}

		else

		{

			strcpy(strCarSelected, "Toyota Pathfinder");

			CarSelectedYear = 2000;

		}

		break;

	}



	Car Selected(strCarSelected, CarSelectedYear, CarType);

	return Selected;

}

//--------------------------------------------------------------------

void Invoice::setMileage(const long g)

{

	Mileage = g;

}

//--------------------------------------------------------------------

long Invoice::getMileage() const

{

	return Mileage;

}

//--------------------------------------------------------------------

void Invoice::setTankLevel(const char *v)

{

	TankLevel = new char[strlen(v) + 1];

	strcpy(TankLevel, v);

}

//--------------------------------------------------------------------

char* Invoice::getTankLevel() const

{

	return TankLevel;

}

//--------------------------------------------------------------------

void Invoice::setCarCondition(const char *c)

{

	CarCondition = new char[strlen(c) + 1];

	strcpy(CarCondition, c);

}

//--------------------------------------------------------------------

char* Invoice::getCarCondition() const

{

	return CarCondition;

}

//--------------------------------------------------------------------

void Invoice::ProcessOrder()

{

	int NbrOfDays;;

	double Rate, TotalPrice;

	// Enter Customer Information

	Customer Person = CustomerRegistration();

	cout << "\nProcess Car Information\n";

	Car	Driving = CarSelection();



	TotalPrice = CalculatePrice(Driving, Rate, NbrOfDays);

	CarExamination();



	// This function works for both Borland C++ Builder and MSVC

	system("cls");



	cout << " - Bethesda Car Rental -";

	cout << "\n=============================";

	CustomerInformation(Person);

	cout << "\n------------------------------";

	CarSelected(Driving);

	cout << setiosflags(ios::fixed) << setprecision(2);

	cout << "\n------------------------------";

	cout << "\nCar Mileage: " << getMileage();

	cout << "\nCondition:   " << getCarCondition();

	cout << "\nTank Level:  " << getTankLevel();

	cout << "\n# of Days:   " << NbrOfDays;

	cout << "\n------------------------------";

	cout << "\nRate:        $" << Rate;

	cout << "\nTotal Price: $" << TotalPrice;

	cout << "\n==============================\n";

}

//--------------------------------------------------------------------

void Invoice::CustomerInformation(const Customer& Pers)

{

    cout << "\nEmployee Identification";

    cout << "\nFull Name:    " << Pers.FullName();

    cout << "\nAddress:      " << Pers.getAddress();

    cout << "\nCity:         " << Pers.getCity() << ", "

         << Pers.getState() << " " << Pers.getZIPCode();

}

//--------------------------------------------------------------------

void Invoice::CarSelected(const Car& Vehicle)

{

	cout << "\nModel:       " << Vehicle.getMakeModel();

	cout << "\nYear:        " << Vehicle.getCarYear();

}



//--------------------------------------------------------------------

double Invoice::CalculatePrice(const Car& Vehicle, double& DayRate,

							   int &NumberOfDays)

{

//	char	WeekEndResponse;// Does the customer rent the car for the week-end?

	double	OneDayRate, // If renting for less than 5 days including week-end

			WeekDay,	// If renting for at least 5 days, regardless of the days

			WeekEnd = 0;// If renting for more than two days from Friday to monday

	//double	DayRate;	// Rate applied based on the number of days

	double	TotalRate;



	switch(Vehicle.getCategory())

	{

	case ctEconomy:

		DayRate		= 24.95;

		OneDayRate	= 29.95;

		WeekDay		= 24.95;

		WeekEnd		= 19.95;

		break;



	case ctCompact:

		DayRate		= 34.95;

		OneDayRate	= 39.95;

		WeekDay		= 34.95;

		WeekEnd		= 25.95;

		break;



	case ctStandard:

		DayRate		= 38.95;

		OneDayRate	= 49.95;

		WeekDay		= 38.95;

		WeekEnd		= 32.95;

		break;



	case ctFullSize:

		DayRate		= 44.95;

		OneDayRate	= 69.95;

		WeekDay		= 44.95;

		WeekEnd		= 35.95;

		break;



	case ctMiniVan:

		DayRate		= 54.95;

		OneDayRate	= 89.95;

		WeekDay		= 54.95;

		WeekEnd		= 42.95;

		break;



	case ctSUV:

		DayRate		= 64.95;

		OneDayRate	= 89.95;

		WeekDay		= 64.95;

		WeekEnd		= 50.95;

		break;

	}



	cout << "\nHow many days? "; cin >>	NumberOfDays;

	TotalRate = DayRate * NumberOfDays;

	return TotalRate;

}

//--------------------------------------------------------------------

void Invoice::CarExamination()

{

	char Cond;

	int GasLevel;



	cout << "Rate the car's condition (e=Excellent/g=Good/d=Driveable): ";

	cin >> Cond;

	if( Cond == 'e' || Cond == 'E' )

		strcpy(CarCondition, "Excellent");

	else if( Cond == 'g' || Cond == 'G' )

		strcpy(CarCondition, "Good");

	else if( Cond == 'd' || Cond == 'D' )

		strcpy(CarCondition, "Driveable");

	else

		strcpy(CarCondition, "Can't Decide");



	cout << "Enter the car mileage: ";

	cin >> Mileage;



	do {

		cout << "Gas level in the tank"

			 << "\n1 - Considered Empty"

			 << "\n2 - 1/4 Full"

			 << "\n3 - Half Full"

			 << "\n4 - 3/4 Full"

			 << "\n5 - Full Tank";

		cout << "\nEnter the gas level: ";

		cin >> GasLevel;

	}while(GasLevel < 1 || GasLevel > 5);



	switch(GasLevel)

	{

	case 1:

		setTankLevel("Empty");

		break;

	case 2:

		setTankLevel("1/4 Full");

		break;

	case 3:

		setTankLevel("Half Full");

		break;

	case 4:

		setTankLevel("3/4 Full");

		break;

	case 5:

		setTankLevel("Full Tank");

		break;

	}

}
