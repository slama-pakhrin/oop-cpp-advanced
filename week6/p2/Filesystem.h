/****************************************************
Workshop 6

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Oct 28

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/
#ifndef sdds_Filesystem_h
#define sdds_Filesystem_h
#include <iostream>
#include "Directory.h"
#include "Resource.h"
#include "File.h"


namespace sdds{
class Filesystem{
    Directory* m_root{};
    Directory* m_current{};
public:
    Filesystem(const std::string& fileName, const std::string& path={});
    Filesystem(const Filesystem& other)=delete;
    Filesystem& operator=(const Filesystem& other)=delete;
    Filesystem(Filesystem&& other);
    Filesystem& operator=(Filesystem&& other);
    Filesystem& operator+=(Resource*);
    Directory* change_directory(const std::string& name={});
    Directory* get_current_directory() const;
    ~Filesystem();
};



}




#endif
