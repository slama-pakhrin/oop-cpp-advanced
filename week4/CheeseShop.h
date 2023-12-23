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

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include "Cheese.h"

namespace sdds 
{
	class CheeseShop 
	{
	private:

		std::string shopName{};
		const sdds::Cheese** m_cheese{};
		size_t m_size;
		size_t m_capacity;
		void clear();

	public:

		CheeseShop(const std::string& name);
		CheeseShop& addCheese(const Cheese& cheese);
		~CheeseShop();
		CheeseShop(const CheeseShop& src);
		CheeseShop& operator=(const CheeseShop& src);
		CheeseShop(CheeseShop&& src) noexcept;
		CheeseShop& operator=(CheeseShop&& src) noexcept;
		friend std::ostream& operator<<(std::ostream& os, const CheeseShop& shop);
	};
}
	
#endif