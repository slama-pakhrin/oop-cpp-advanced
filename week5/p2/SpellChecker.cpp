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

#include "SpellChecker.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			/* Optimized Version: when the only separator for the words 
			   in the lines is the whitespace, we can read from the file
			   through >> operator and it will automatically remove the
			   whitespaces and push the words to the array.
			   Reference: http://www.cplusplus.com/forum/beginner/78150/ */
			for (size_t i = 0; i < MAX_WORDS; ++i)
			{
				file >> m_badWords[i];
				file >> m_goodWords[i];
			}
			file.close();


			/* Old version just for reference:*/
			//size_t i{ 0 };
			//string line, badWord;
			//do {
			//	
			//	std::getline(file, line);

			//	//BAD WORD
			//	badWord = line.substr(0, line.find(' '));
			//	badWord.erase(0, badWord.find_first_not_of(' '));
			//	badWord.erase(badWord.find_last_not_of(' ') + 1);

			//	m_badWords[i] = badWord;
			//	line.erase(0, line.find(' ') + 1);

			//	//GOOD WORD
			//	line.erase(0, line.find_first_not_of(' '));
			//	line.erase(line.find_last_not_of(' ') + 1);
			//	m_goodWords[i] = line;
			//} while (file && i++ < MAX_WORDS);
		}
	}
	void SpellChecker::operator()(std::string& text) {
    for (size_t i = 0; i < MAX_WORDS; i++) {
        size_t pos = 0;
        while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
            text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
            count[i]++;
            // Move past the current position to continue searching
            pos += m_goodWords[i].size();
        }
    }
}




	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < MAX_WORDS; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << count[i] << " replacements" << std::endl;
		}
	}
}