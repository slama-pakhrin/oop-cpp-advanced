// Book.cpp

#include "Book.h"
#include <iomanip>

namespace sdds {

    Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
        : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

std::ostream& Book::print(std::ostream& os) const {
    os << "| " << std::setw(56) << std::left << m_title << "," << m_numChapters << "," << m_numPages << " | ("
       << std::fixed << std::setprecision(6) << static_cast<double>(m_numPages) / m_numChapters << ") |";
    return os;
}








    bool Book::isEmpty() const {
        return m_title.empty() || m_numChapters == 0 || m_numPages == 0;
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        return bk.print(os);
    }

} // namespace sdds
