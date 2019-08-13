
#if !defined CUSTOMER_H

#define CUSTOMER_H



class Customer

{

private:

    char* FirstName;

    char* LastName;

    char* Address;

    char* City;

    char* State;

    long  ZIPCode;



public:

    void  setFirstName(const char *FN);

    char* getFirstName() const { return FirstName; }

    void  setLastName(const char *LN);

    char* getLastName() const { return LastName; }

    char* FullName() const;

    void  setAddress(const char *Adr);

    char* getAddress() const { return Address; }

    void  setCity(const char *CT);

    char* getCity() const { return City; }

    void  setState(const char *St);

    char* getState() const { return State; }

    void  setZIPCode(const long ZIP);

    long  getZIPCode() const { return ZIPCode; }

    Customer();

    Customer(char *FName, char *LName, char *Adr,

             char *Ct, char *St, long  ZIP);

    Customer(const Customer &Pers);

    Customer(char * FName, char * LName);

    ~Customer();

};



#endif	// CUSTOMER_H
