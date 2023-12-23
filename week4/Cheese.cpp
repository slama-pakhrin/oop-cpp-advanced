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

#include "Cheese.h"
#include <iomanip>
#include <sstream>

namespace sdds {
	Cheese::Cheese():m_name{"NaC"}, m_weight(0), m_price(0.0), m_feature("") {}
   
	Cheese::Cheese(const std::string& str) 
    {
        std::string currentPosititon{}, pre{};
        int temp{};
        temp = str.find(',');
        currentPosititon = str.substr(0, temp);
        pre = str.substr(temp + 1);
        m_name = removeSpaces(currentPosititon);

        temp = pre.find(',');
        currentPosititon = pre.substr(0, temp);
        pre = pre.substr(temp + 1);
        m_weight = std::stoi(removeSpaces(currentPosititon));

        temp = pre.find(',');
        currentPosititon = pre.substr(0, temp);
        pre = pre.substr(temp + 1);
        m_price = std::stod(removeSpaces(currentPosititon));

        m_feature = removeSpaces(pre);
       
        size_t pos = m_feature.find(',');
        while (pos != std::string::npos) {
            m_feature.replace(pos, 1, " ");
            pos = m_feature.find(',', pos + 1);
        }
       
        m_feature = removeSpaces(m_feature);
    }

    Cheese Cheese::slice(size_t weight) {
        if (weight <= static_cast<size_t>(m_weight)) {
            Cheese slicedCheese = *this;
            slicedCheese.m_weight = static_cast<int>(weight);
            m_weight -= static_cast<int>(weight);
            return slicedCheese;
        }
        else {
           
            return Cheese();
        }
    }
    std::string Cheese::getName() const{
        return m_name;
    }
    int Cheese::getWeight() const {
        return m_weight;
    }
    double Cheese::getPrice() const {
        return m_price;
    }  
    std::string Cheese::getFeatures() const {
        return m_feature;
    }
    std::ostream& operator<<(std::ostream& os, const Cheese& cheese) {
        os << "|" << std::left << std::setw(21) << cheese.getName() << "|"
             << std::setw(5) << cheese.getWeight() << "|"
            << std::fixed << std::setprecision(2) << std::setw(5) << cheese.getPrice() << "|"
            << std::right << std::setw(33) << cheese.getFeatures() << " |\n";
        return os;
    }

    std::string Cheese::removeSpaces(const std::string& str) {
        std::istringstream iss(str);
        std::ostringstream oss;
        std::string word;
        while (iss >> word) {
            oss << word << " ";
        }
        std::string result = oss.str();
        result.pop_back();
        return result;
    }

}