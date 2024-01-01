/****************************************************
Workshop 7

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Nov 10

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <list>

#include "CovidCollection.h"

using namespace std;

namespace sdds {

	CovidCollection::CovidCollection(char* fileName)
	{
		if (fileName != nullptr) {

			ifstream f(fileName);

			if (!f) {
				throw std::invalid_argument("Invalid filename");
			}

			string line;
			while (getline(f, line)) {
				if (line.size() >= 75) {
					Covid data;
					data.m_status = "General";
					data.m_country = line.substr(0, 25);
					eraseSpaces(data.m_country);
					data.m_city = line.substr(25, 25);
					eraseSpaces(data.m_city);
					data.m_variant = line.substr(50, 20);
					eraseSpaces(data.m_variant);
					data.m_year = stoi(line.substr(70, 20));
					data.m_numCases = stoul(line.substr(80, 5));
					data.m_numDeaths = stoul(line.substr(85, 5));

					collection.push_back(data);
				}
			}
		}

	}

	void CovidCollection::display(std::ostream& out, const std::string& country) const
	{
		unsigned int deaths = 0;
		unsigned int cases = 0;
		unsigned int globalDeaths = 0;
		unsigned int globalCases = 0;
		double percentageDeaths = 0.0;
		double percentageCases = 0.0;

		if (country != "ALL")
		{
			out << "Displaying information of country = " << country << endl;
		}

		for_each(collection.begin(), collection.end(), [&out, country, &deaths, &cases, &globalDeaths, &globalCases](const Covid& data)
			{
				globalDeaths += data.m_numDeaths;
				globalCases += data.m_numCases;
				if (country != "ALL")
				{
					if (data.m_country == country)
					{
						out << data << endl;
						deaths += data.m_numDeaths;
						cases += data.m_numCases;
					}
				}
				else
				{
					out << data << endl;
				}
			});

		if (country == "ALL") {
			out << '|';
			out.setf(ios::right);
			out << setw(80) << "Total cases around the world: " << globalCases << " |" << endl;
			out.unsetf(ios::right);
			out << '|';
			out.setf(ios::right);
			out << setw(80) << "Total deaths around the world: " << globalDeaths << " |" << endl;
			out.unsetf(ios::right);
		}
		else {
			percentageCases = (double)cases / globalCases * 100;
			percentageDeaths = (double)deaths / globalDeaths * 100;
			out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
			out << '|';
			out.setf(ios::right);
			out << setw(79 - country.length()) << "Total cases in " << country << ": " << cases << " |" << endl;
			out.unsetf(ios::right);
			out << '|';
			out.setf(ios::right);
			out << setw(79 - country.length()) << "Total deaths in " << country << ": " << deaths << " |" << endl;
			out.unsetf(ios::right);
			out << '|';

			out.setf(ios::right);
			out << setw(26 - to_string((int)percentageDeaths).length() - to_string((int)percentageCases).length()) << fixed << setprecision(6) << country << " has " << percentageCases << "% of global cases and " << percentageDeaths << "% of global deaths |" << endl;
			out.unsetf(ios::right);
		}
	}

	void CovidCollection::sort(const std::string& field)
	{
		std::sort(collection.begin(), collection.end(), [field](const Covid& a, const Covid& b) {
			if (field == "year")
			{
				if (a.m_year == b.m_year)
					return a.m_numDeaths < b.m_numDeaths;
				return a.m_year < b.m_year;
			}
			else if (field == "country")
			{
				if (a.m_country == b.m_country)
					return a.m_numDeaths < b.m_numDeaths;
				else
					return a.m_country < b.m_country;
			}
			else if (field == "variant")
			{
				if (a.m_variant == b.m_variant)
					return a.m_numDeaths < b.m_numDeaths;
				else
					return a.m_variant < b.m_variant;
			}
			else
			{
				return a.m_numDeaths < b.m_numDeaths;
			}
			});
	}

	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const
	{
		return std::any_of(collection.begin(), collection.end(), [=](const Covid& data) {
			return(data.m_country == country && data.m_variant == variant && data.m_numDeaths > deaths);
			});
	}

	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const
	{
		list<Covid> covidList;
		std::copy_if(collection.begin(), collection.end(), back_inserter(covidList), [=](const Covid& data) {
			return data.m_numDeaths >= deaths;
			});

		return covidList;
	}


	void CovidCollection::updateStatus()
	{
		std::transform(collection.begin(), collection.end(), collection.begin(), [](Covid& c) {
			if (c.m_numDeaths > 300) {
				c.m_status = "EPIDEMIC";
			}
			else if (c.m_numDeaths < 50) {
				c.m_status = "EARLY";
			}
			else
			{
				c.m_status = "MILD";
			}
			return c;
			});
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		out.setf(ios::left);
		out << "| " << left << setw(21) << theCovid.m_country << " | ";
		out << setw(15) << theCovid.m_city << " | ";
		out << setw(20) << theCovid.m_variant << " | ";
		out.unsetf(ios::left);
		out.setf(ios::right);
		if (theCovid.m_year > 0)
			out << setw(6) << theCovid.m_year << " | ";
		else
			out << setw(6) << " " << " | ";
		out << setw(4) << theCovid.m_numCases << " | ";
		out << setw(3) << theCovid.m_numDeaths << " | | ";
		out << setw(8) << theCovid.m_status << " |";
		out.unsetf(ios::right);

		return out;
	}

	void eraseSpaces(string& str)
	{
		while (!str.empty() && isspace(str.back()))
			str.pop_back();
	}




}