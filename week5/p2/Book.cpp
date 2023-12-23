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

#include "Book.h"

namespace sdds {
	const std::string& sdds::Book::author() const {
		return b_author;
	}
	const std::string& sdds::Book::title() const {
		return b_title;
	}
	const std::string& sdds::Book::country() const {
		return b_country;
	}
	const size_t& sdds::Book::year() const {
		return b_year;
	}
	double& sdds::Book::price() {
		return b_price;
	}
	const std::string& sdds::Book::description() const {
		return b_description;
	}
	sdds::Book::Book(const std::string& strBook) {
		string str = strBook; //temp book string
		string author, title, country, price, year, description; //temp variables to hold data

		//AUTHOR
		author = str.substr(0, str.find(',')); //constructs a string that starts from pos 0 to ',' and assigns the substring to the variable
		str.erase(0, str.find(',') + 1); //erase the part of the string from pos 0 to ','

		//TITLE
		title = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//COUNTRY
		country = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//PRICE
		price = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//YEAR
		year = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//DESCRIPTION
		description = str;

		//trim whitespace
		author.erase(0, author.find_first_not_of(' '));
		author.erase(author.find_last_not_of(' ') + 1);
		title.erase(0, title.find_first_not_of(' '));
		title.erase(title.find_last_not_of(' ') + 1);
		country.erase(0, country.find_first_not_of(' '));
		country.erase(country.find_last_not_of(' ') + 1);
		description.erase(0, description.find_first_not_of(' '));
		description.erase(description.find_last_not_of(' ') + 1);

		//store the tokens in the instance's attributes
		b_author = author;
		b_title = title;
		b_country = country;
		b_price = stod(price); //parses str and interprets it as an double
		b_year = stoi(year);  //parses str and interprets it as an int
		b_description = description;
	}
	std::ostream& operator<<(std::ostream& os, const Book& bck) {
		os << std::setw(20) << bck.author() << " | ";
		os << std::setw(22) << bck.title() << " | ";
		os << std::setw(5) << bck.country() << " | ";
		os << std::setw(4) << bck.year() << " | ";
		os << std::setw(6) << std::setprecision(2) << std::fixed << bck.b_price << " | ";
		os << bck.description() << std::endl;
		return os;
	}
}