/****************************************************
Workshop 5 part 2

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Oct 12

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
#include <iomanip>
namespace sdds {
	typedef std::string string;
	class Movie {
		string m_title{}; //title
		size_t m_year{ 0 }; //the year of release
		string m_description{}; //the description
	public:
		Movie() {};
		Movie(const std::string& strMovie);
		const std::string& title() const;
		const std::string& description() const;
		const size_t year() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& mov);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}
#endif