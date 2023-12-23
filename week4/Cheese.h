/****************************************************
Workshop 4 part 2

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Oct 6

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
#include <string>

namespace sdds 
{
	class Cheese 
	{
	private:

		std::string m_name{};
		int m_weight{};
		double m_price{};
		std::string m_feature{};
		std::string removeSpaces(const std::string& str);

	public:

		Cheese();
		Cheese(const std::string& str);
		Cheese slice(size_t weight);
		std::string getName() const;
		int getWeight() const;
		double getPrice() const;
		std::string getFeatures() const;
		
	};
	std::ostream& operator<<(std::ostream& os, const Cheese& cheese);

}

#endif 
