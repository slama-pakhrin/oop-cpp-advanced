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

#include "Movie.h"
namespace sdds {
	Movie::Movie(const std::string& strMovie) {
		string str = strMovie;
		string title, year, description;

		//TITLE
		title = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//YEAR
		year = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//DESCRIPTION
		description = str;

		//trim whitespace
		title.erase(0, title.find_first_not_of(' '));
		title.erase(title.find_last_not_of(' ') + 1);
		year.erase(0, year.find_first_not_of(' '));
		year.erase(year.find_last_not_of(' ') + 1);
		description.erase(0, description.find_first_not_of(' '));
		description.erase(description.find_last_not_of(' ') + 1);

		//store the tokens in the instance's attributes
		m_title = title;
		m_description = description;
		m_year = stoi(year);
	}
	const std::string& Movie::title() const {
		return m_title;
	}
	const std::string& Movie::description() const {
		return m_description;
	}
	const size_t Movie::year() const {
		return m_year;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& mov) {
		os << std::setw(40) << mov.title() << " | ";
		os << std::setw(4) << mov.year() << " | ";
		os << mov.description() << std::endl;
		return os;
	}
}