// Book.h

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {

    class Book {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};

    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);

        std::ostream& print(std::ostream& os) const;
        bool isEmpty() const; // Add this member function
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);

} // namespace sdds

#endif // SDDS_BOOK_H
