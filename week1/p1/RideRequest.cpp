/****************************************************
Workshop 1

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Sept 16

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/

#include <iostream>
#include "RideRequest.h"
using namespace std;
double  g_taxrate=0.0, g_discount=0.0;
namespace sdds {
	RideRequest::RideRequest() {
		this->cName[0] = '\0';
		this->desc[0] = '\0';
		this->price = 0.0;
		this->discountP = true;
	}
	istream& RideRequest::read(istream& istr) {

		char _discountP = '\0';

		if (istr) {
			istr.getline(this->cName, 10, ',');
			istr.getline(this->desc, 25, ',');
			istr >> this->price;
			istr.ignore();
			istr >> _discountP;
			if (_discountP == 'Y') {
				this->discountP = true;
			}
			else if (_discountP == 'N') {
				this->discountP = false;
			}
		}
		return istr;
	}
	void RideRequest::display() const {
		static unsigned int COUNTER = 0;
		double priceWithTax = this->price * (1 + g_taxrate);
		double discPrice = priceWithTax - g_discount;

		cout.width(2);
		cout.setf(ios::left);
		cout << ++COUNTER << ". ";
		cout.unsetf(ios::left);

		if (this->cName[0] != '\0') {
	
			cout.width(10);
			cout.setf(ios::left);
			cout << this->cName;
			cout.unsetf(ios::left);

			cout << "|";
			cout.width(25);
			cout.setf(ios::left);
			cout << this->desc;
			cout.unsetf(ios::left);

			cout << "|";
			cout.width(12);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::left);
			cout << priceWithTax;
			cout.unsetf(ios::left);

			cout << "|";
			if (this->discountP == true) {
				cout.width(13);
				cout.setf(ios::right);
				cout << discPrice;
				cout.unsetf(ios::right);
			}
			cout << endl;
		}
		else {
			cout << "No Ride Request" << endl;
		}
	}
}