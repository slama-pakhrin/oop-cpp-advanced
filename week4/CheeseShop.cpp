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

#include "CheeseShop.h"

namespace sdds 
{
    CheeseShop::CheeseShop(const std::string& name) : shopName(name), m_cheese(nullptr), m_size(0), m_capacity(0) {}

    void CheeseShop::clear() {

        for (size_t i = 0; i < m_size; ++i) 
        {
            delete m_cheese[i];
        }
        delete[] m_cheese;
        m_cheese = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    CheeseShop::~CheeseShop() 
    {
        clear();
    }

    CheeseShop& CheeseShop::addCheese(const Cheese& cheese)
    {
        do {
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

            m_cheese[m_size] = new Cheese(cheese);
            ++m_size;

        } while (false);  

        return *this;
    }

    CheeseShop::CheeseShop(const CheeseShop& src){
        *this = src;
    }

    CheeseShop& CheeseShop::operator=(const CheeseShop& src) {
        if (this != &src) {
            if (m_cheese != nullptr) {
                clear();
            }

            shopName = src.shopName;
            m_cheese = new const Cheese * [src.m_capacity];

            for (size_t i = 0; i < src.m_size; ++i) {
                m_cheese[i] = new Cheese(*(src.m_cheese[i]));
            }

            m_size = src.m_size;
            m_capacity = src.m_capacity;
        }
        return *this; 
    }

    CheeseShop::CheeseShop(CheeseShop&& src) noexcept {
        *this = std::move(src);
    }

    CheeseShop& CheeseShop::operator=(CheeseShop&& src)noexcept {
        if (this != &src) {
            clear();

            shopName = std::move(src.shopName);
            m_cheese = src.m_cheese;
            m_size = src.m_size;
            m_capacity = src.m_capacity;

            src.m_cheese = nullptr;
            src.m_size = 0;
            src.m_capacity = 0;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const CheeseShop& shop) {
        os << "--------------------------" << std::endl;
        os << shop.shopName << std::endl;
        os << "--------------------------" << std::endl;
        if (shop.m_size == 0) {
            os << "This shop is out of cheese!" << std::endl;
        }
        else {
            for (size_t i = 0; i < shop.m_size; ++i) {
                os << *(shop.m_cheese[i]);
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}