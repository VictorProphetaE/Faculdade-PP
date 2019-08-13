
#if !defined INVOICE_H

#define INVOICE_H



#include "Customer.h"

#include "Car.h"

#include "RentDate.h"



class Invoice

{

public:

	Invoice();

	virtual ~Invoice();

	Customer CustomerRegistration();

	void	 CustomerInformation(const Customer& Pers);

	Car		 CarSelection();

	void	 CarSelected(const Car& Vehicle);

	double   CalculatePrice(const Car& Vehicle, double& Rate, int &Days);

	void	 setMileage(const long g);

	long	 getMileage() const;

	void	 setTankLevel(const char *v);

	char*	 getTankLevel() const;

	void     setCarCondition(const char *c);

	char*    getCarCondition() const;



	void ProcessOrder();

	void CarExamination();

	void ShowOrder();



private:

	long  Mileage;

	char *TankLevel;

	char *CarCondition;

};



#endif	// INVOICE_H
