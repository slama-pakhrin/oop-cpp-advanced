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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
const size_t MAX_WORDS = 6;
namespace sdds {
	typedef std::string string;
	class SpellChecker {
		string m_badWords[MAX_WORDS]; //an array with 6 misspelled words
		string m_goodWords[MAX_WORDS]; //an array with the correct spelling of those 6 words
		size_t count[MAX_WORDS]{}; //number of times each misspelled word has been replaced
	public:
		SpellChecker() : m_badWords{}, m_goodWords{} {};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif