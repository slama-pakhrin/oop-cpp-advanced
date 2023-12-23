
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds
{
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);

		
		operator bool()const;

	
		bool operator<(const Book& ro)const;
		bool operator>(const Book& ro)const;
		~Book() = default;
	

		std::ostream& print(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}


#endif // !SDDS_BOOK_H