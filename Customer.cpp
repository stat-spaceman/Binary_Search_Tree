/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

Customer::Customer(void){
	LastName;
	FirstInitial;
	balance=0;
}

Customer::Customer(string LastNameValue,char FirstInitialValue,int balanceValue) {
	LastName = LastNameValue;
	FirstInitial = FirstInitialValue;
	balance = balanceValue;
}

string Customer::GetLastName() const{
	return LastName;
}
char Customer::GetFirstInitial() const{
	return FirstInitial;
}

int Customer::Getbalance()  const{
	return balance;
}

void Customer::SetLastName(const string setLastName){
	LastName=setLastName;
}
void Customer::SetFirstInitial(const char setFirstInitial){
	FirstInitial=setFirstInitial;
}
void Customer::Setbalance(const int setbalance){
	balance=setbalance;
}
bool Customer::operator==(const Customer& Customer2) const{
	//if two customer have same LastName and First Initial return true
	if(this->LastName.compare(Customer2.LastName)==0 && this->FirstInitial==Customer2.FirstInitial){	
		return true;
	}
	else{
		return false;
	}
}

bool Customer::operator!=(const Customer& Customer2) const{
	//if the last name are different or first initial are different
	if(this->LastName.compare(Customer2.LastName)!=0 || this->FirstInitial!=Customer2.FirstInitial){	
		return true;
	}
	else{
		return false;
	}
}

bool Customer::operator>=(const Customer& Customer2) const{
	if(this->LastName.compare(Customer2.LastName)>0 ){	
		return true;
	}
	//if last name are same then compare first initial
	else if (this->LastName.compare(Customer2.LastName)==0){
		if(this->FirstInitial>=Customer2.FirstInitial){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool Customer::operator<=(const Customer& Customer2) const{
	if(this->LastName.compare(Customer2.LastName)<0 ){	
		return true;
	}
	//if last name are same then compare first initial
	else if (this -> LastName.compare(Customer2.LastName)==0){
		if(this->FirstInitial<=Customer2.FirstInitial){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}

}

bool Customer::operator<(const Customer& Customer2) const{
	if(this -> LastName.compare(Customer2.LastName)<0 ){
		return true;
	}
	//if last name are same then compare first initial
	else if (this -> LastName.compare(Customer2.LastName)==0){
		if(this -> FirstInitial<Customer2.FirstInitial){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool Customer::operator>(const Customer& Customer2) const{
	if(this->LastName.compare(Customer2.LastName)>0 ){
		return true;
	}
	//if last name are same then compare first initial
	else if (this->LastName.compare(Customer2.LastName)==0){
		if(this->FirstInitial>Customer2.FirstInitial){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

ostream& operator<<(ostream & os,  Customer & c) {
	os<<c.LastName<<", "<<c.FirstInitial<<". ("<<c.balance<<")";
	return os;
}
