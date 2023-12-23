#ifndef SDDS_RIDEREQUEST_H_
#define SDDS_RIDEREQUEST_H_
#include<iostream>

extern double g_taxrate, g_discount;

namespace sdds {
    class RideRequest{
        char cName[10];
		char desc[25];
		double price;
		bool discountP;
	public:
		RideRequest();
		std::istream& read(std::istream& istr = std::cin);
		void display() const;
	};
}

#endif