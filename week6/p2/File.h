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

#ifndef SDDS_File_h
#define SDDS_File_h

#include <iostream>
#include "Resource.h"
#include "Flags.h"
namespace sdds{
    class File:public Resource{
        std::string m_contents{};
    public:
        File(const std::string& name, const std::string& content);
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
    };
}


#endif 
