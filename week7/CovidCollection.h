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

#pragma once
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <vector>
#include <list>
namespace sdds
{

	struct Covid
	{
		std::string m_status = "";
		std::string m_country = "";
		std::string m_city = "";
		std::string m_variant = "";
		int m_year{};
		unsigned int m_numCases{};
		unsigned int m_numDeaths{};
	};

	class CovidCollection
	{
		std::vector<Covid> collection;
	public:
		CovidCollection(char* fileName);
		void display(std::ostream& out, const std::string& country = "ALL") const;
		void sort(const std::string& field = "country");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		void updateStatus();
	};

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

	void eraseSpaces(std::string& str);
}

#endif 