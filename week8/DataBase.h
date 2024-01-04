/****************************************************
Workshop 8 

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Nov 15

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

#include "Profile.h"

namespace sdds
{
	template <typename T>
	class DataBase
	{
		std::vector<T> database;

	public:
		DataBase() {}
		DataBase(const char *fn)
		{
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
			while (file)
			{
				T e;
				try
				{
					if (e.load(file))
						database.push_back(T(e));
				}
				catch (...)
				{
					break;
				}
			}
		}
		size_t size() const { return database.size(); }
		const T &operator[](size_t i) const { return database[i]; }

		void operator+=(const T &item)
		{
			database.push_back(item);
		}

		void operator+=(std::unique_ptr<Profile> &&item)
		{
			database.push_back(std::move(*item));
		}

		void display(std::ostream &os) const
		{
			os << std::fixed << std::setprecision(2);
			for (auto &e : database)
				os << e;
		}
	};

	template <typename T>
	std::ostream &operator<<(std::ostream &os, const DataBase<T> &db)
	{
		db.display(os);
		return os;
	}
}
#endif