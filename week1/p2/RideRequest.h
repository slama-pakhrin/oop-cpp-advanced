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


#ifndef SDDS_RIDEREQUEST_H__
#define SDDS_RIDEREQUEST_H__
#include <iostream>
#include <cstring>

extern double g_taxrate;
extern double g_discount;

namespace sdds
{
	class RideRequest
	{
		char cName[10];
		std::string desc;
		double price;		
		bool disPrice;
	public:
		RideRequest();
		std::istream& read(std::istream& istr);
		void display();
	};
}
#endif 