
#if !defined CAR_H

#define CAR_H



enum TCarType { ctEconomy = 1, ctCompact, ctStandard, ctFullSize, ctMiniVan, ctSUV };



class Car

{

public:

			 Car();

			 Car(char *MM, int Y, int Cat);

	virtual ~Car();

	void     setMakeModel(const char *mm);

	char*    getMakeModel() const;

	void     setCarYear(const int y);

	int      getCarYear() const;

	void     setCategory(const int c);

	int      getCategory() const;



private:

	char*	 MakeModel;

	int		 CarYear;

	int		 Category;

};



#endif // CAR_H
