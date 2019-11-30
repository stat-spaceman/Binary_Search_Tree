

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer(void);
	// Customer(string LastNameValue,char FirstInitialValue,int balanceValue);
	Customer(string,char,int);
	~Customer(void){};

	string GetLastName() const;
	char GetFirstInitial() const;
	int Getbalance()  const;

	void SetLastName(const string setLastName);
	void SetFirstInitial(const char setFirstInitial);
	void Setbalance(const int setbalance);

	bool operator==(const Customer& Customer2) const;
	bool operator!=(const Customer& Customer2) const;
	bool operator>=(const Customer& Customer2) const;
	bool operator>(const Customer& Customer2) const;
	bool operator<=(const Customer& Customer2) const;
	bool operator<(const Customer& Customer2) const;


private:
	string LastName;
	char FirstInitial;
	int balance;

	friend ostream& operator<<(ostream & os,  Customer & c);

};

#endif /* CUSTOMER_H_ */
