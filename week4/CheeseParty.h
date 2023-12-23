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

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include"Cheese.h"

namespace sdds 
{
	class CheeseParty 
	{
	private:

		const sdds::Cheese** m_cheese{};
		size_t m_size{};
		size_t m_capacity{};

	public:

		CheeseParty();
		~CheeseParty();
		CheeseParty(const CheeseParty& src);
		CheeseParty& operator=(const CheeseParty& src);
		CheeseParty(CheeseParty&& src) noexcept;
		CheeseParty& operator=(CheeseParty&& src) noexcept;
		CheeseParty& addCheese(const Cheese& cheese);
		CheeseParty& removeCheese();
		friend std::ostream& operator<<(std::ostream& os, const CheeseParty& party);
	};
}
#endif 