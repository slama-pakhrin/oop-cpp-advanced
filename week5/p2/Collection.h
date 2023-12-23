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

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
namespace sdds {
	typedef std::string string;
	template <class T>
	class Collection {
		string c_name{};
		T* c_objects{};
		size_t c_size{ 0 };
		void (*c_observer)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const string& name) : c_name(name) {}
		Collection(Collection&) = delete;
		Collection& operator=(Collection&) = delete;
		Collection(Collection&&) = delete;
		Collection& operator=(Collection&&) = delete;
		~Collection() {
			delete[] c_objects;
		}
		const string& name() const {
			return c_name;
		}
		size_t size() const {
			return c_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool same{ false };
			for (size_t i = 0; i < size(); i++) {
				if (c_objects[i].title() == item.title()) 
					same = true;
			}
			if (!same) {
				T* tempObj = new T[size() + 1]; //open space for a new item
				
				for (size_t i = 0; i < size(); i++)
					tempObj[i] = c_objects[i];
				tempObj[c_size++] = item;
				delete[] c_objects;
				c_objects = tempObj;
				//++c_size;
				if (c_observer != nullptr) c_observer(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= size()) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");
			}
			else {
				return c_objects[idx];
			}
		}
		T* operator[](const string& title) const {
			T* temp { nullptr };
			//int index{ -1 };
			for (size_t i = 0; i < size(); i++) {
				if (c_objects[i].title() == title) {
					//index = i;
					temp = &c_objects[i];
				}
			}
			/*if (index != -1) {
				return &c_objects[index];
			}
			else {
					return nullptr;
			}*/
			return temp;
		}
		friend std::ostream& operator<<(std::ostream& os, const Collection& col) {
			for (size_t i = 0; i < col.size(); i++) os << col[i];
			return os;
		}
	};
}
#endif