#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

    template <typename T, unsigned C>
    class Collection {
        T m_items[C];
        unsigned m_size{ 0 };
        static T m_smallestItem;
        static T m_largestItem;

        void setSmallestItem(const T& item);
        void setLargestItem(const T& item);

    public:
        Collection();
        static T getSmallestItem();
        static T getLargestItem();
        unsigned size() const;
        unsigned capacity() const;
        bool operator+=(const T& item);
        void print(std::ostream& os) const;
    };

    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = T();

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = T();

    template <typename T, unsigned C>
    Collection<T, C>::Collection() : m_items{}, m_size(0) {}

    template <typename T, unsigned C>
    void Collection<T, C>::setSmallestItem(const T& item) {
        if (item < m_smallestItem) {
            m_smallestItem = item;
        }
    }

    template <typename T, unsigned C>
    void Collection<T, C>::setLargestItem(const T& item) {
        if (item > m_largestItem) {
            m_largestItem = item;
        }
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getSmallestItem() {
        return m_smallestItem;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getLargestItem() {
        return m_largestItem;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::size() const {
        return m_size;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::capacity() const {
        return C;
    }

    template <typename T, unsigned C>
    bool Collection<T, C>::operator+=(const T& item) {
        if (m_size < C) {
            m_items[m_size++] = item;
            setSmallestItem(item);
            setLargestItem(item);
            return true;
        }
        return false;
    }

    template <typename T, unsigned C>
    void Collection<T, C>::print(std::ostream& os) const {
        for (unsigned i = 0; i < m_size; ++i) {
            os << m_items[i];
            if (i < m_size - 1) {
                os << ", ";
            }
        }
    }

    template <typename T, unsigned C>
    std::ostream& operator<<(std::ostream& os, const Collection<T, C>& col) {
        col.print(os);
        return os;
    }

} // namespace sdds

#endif // SDDS_COLLECTION_H
