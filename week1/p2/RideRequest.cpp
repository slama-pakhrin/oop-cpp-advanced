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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "RideRequest.h"

double g_taxrate;
double g_discount;

using namespace std;

namespace sdds
{
	RideRequest::RideRequest() {

		}

	istream& RideRequest::read(istream& istr) {
		char Special = ' ';
		if (!istr.fail()) {
			istr.get(cName, 10, ',');
			istr.ignore();
			getline(istr, desc, ',');
			istr >> price;
			istr.ignore();
			istr >> Special;
			if (Special == 'Y') {
				disPrice = true;
			}
			else {
				disPrice = false;
			}
		}
		return istr;
	}

	void RideRequest::display() {
		static int counter = 1;
		double Foodprice = price * g_taxrate + price;
		if (cName[0] != '\0') {
			cout.width(2);
			cout.setf(ios::left);
			cout << counter;
			cout << ". ";
			cout.width(10);
			cout << cName;
			cout << "|";
			cout.width(25);
			cout << desc;
			cout << "|";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << Foodprice;
			cout.unsetf(ios::fixed);
			cout << "|";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.width(13);
			if (disPrice) {
				cout.precision(2);
				cout.setf(ios::fixed);
				cout << Foodprice - g_discount << endl;
				cout.unsetf(ios::fixed);
			}
			else {
				cout.fill(' ');
				cout << endl;
			}
			cout.unsetf(ios::right);
		}
		else {
			cout.width(2);
			cout.setf(ios::left);
			cout << counter << ". No Ride Request" << endl;
		}
		counter++;
	}
}