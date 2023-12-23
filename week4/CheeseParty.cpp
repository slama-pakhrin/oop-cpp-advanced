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

#include "CheeseParty.h"

namespace sdds 
{
	CheeseParty::CheeseParty():m_cheese{nullptr},m_size{0},m_capacity{0}{}
    CheeseParty::~CheeseParty() {
       
        delete[] m_cheese;
        m_size = 0;
        m_capacity = 0;
    }
    CheeseParty::CheeseParty(const CheeseParty& src) {
        *this = src;
    }
    
    CheeseParty& CheeseParty::operator=(const CheeseParty& src) 
    {
        if (this != &src) {
            delete[] m_cheese;
            m_cheese = nullptr;
            m_cheese = new const Cheese * [src.m_capacity];

            size_t i = 0;
            do {
                m_cheese[i] = src.m_cheese[i];
                ++i;
            } while (i < src.m_size);

            m_size = src.m_size;
            m_capacity = src.m_capacity;
        }
        return *this;
    }

    CheeseParty::CheeseParty(CheeseParty&& src) noexcept // gurantee
    {
        *this = std::move(src);
    }

    CheeseParty& CheeseParty::operator=(CheeseParty&& src) noexcept //  contract to the code -> noexpect
    {
        if (this != &src) 
        {
           delete[] m_cheese;
            m_cheese = nullptr;
            m_size = 0;
            m_capacity = 0;     
            m_cheese = src.m_cheese;
            m_size = src.m_size;
            m_capacity = src.m_capacity;
            src.m_cheese = nullptr;
            src.m_size = 0;
            src.m_capacity = 0;
        }
        return *this;
    }

    CheeseParty& CheeseParty::addCheese(const Cheese& cheese)
    {
        for (size_t i = 0; i < m_size; ++i) {
            if (m_cheese[i] == &cheese) {
                return *this;
            }
        }
        if (m_size == m_capacity) {
            size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
            const Cheese** newArray = new const Cheese * [newCapacity];

            for (size_t i = 0; i < m_size; ++i) {
                newArray[i] = m_cheese[i];
            }

            delete[] m_cheese;
            m_cheese = newArray;
            m_capacity = newCapacity;
        }
        m_cheese[m_size] = &cheese;
        ++m_size;
        return *this;
    }
    CheeseParty& CheeseParty::removeCheese() {
    size_t index = 0;
    for (size_t i = 0; i < m_size; ++i) {
        if (m_cheese[i] != nullptr && m_cheese[i]->getWeight() == 0) {     
            index = i;
        }
    }
    const Cheese** newArray = new const Cheese * [m_size-1];
    for (size_t i = 0; i < index; ++i) {
        if (m_cheese[i] != nullptr) {
                newArray[i] = m_cheese[i];
                
        }
    }
        for (size_t i = index; i < m_size - 1; i++) {
            newArray[i] = m_cheese[i + 1];
        }
        delete[] m_cheese;
        m_cheese = newArray;
        newArray = nullptr;
        m_size--;
    
    return *this;
}

    std::ostream& operator<<(std::ostream& os, const CheeseParty& party) {
        os << "--------------------------" << std::endl;
        os << "Cheese Party" << std::endl;
        os << "--------------------------" << std::endl;
        if (party.m_size == 0) {
            os << "This party is just getting started!" << std::endl;
        }
        else {
            for (size_t i = 0; i < party.m_size; ++i) {
                os << *(party.m_cheese[i]);       
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}