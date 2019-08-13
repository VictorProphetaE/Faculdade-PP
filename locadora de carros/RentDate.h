#if !defined RentDate_h

#define RentDate_h

class CRentDate

{

public:

	CRentDate();

	CRentDate(int m, int d, int y);

	CRentDate(const CRentDate& d);

	void setDate(int m, int d, int y);

	int getMonth();

	int getDay();

	int getYear();

	virtual ~CRentDate();

private:

	int Month;

	int Day;

	int Year;

};


#endif	// CUSTOMER_H
