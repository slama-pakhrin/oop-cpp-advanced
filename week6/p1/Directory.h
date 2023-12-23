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

#ifndef SDDS_Directory_h
#define SDDS_Directory_h
#include <iostream>
#include <vector>
#include "Resource.h"
namespace sdds
{
    class Directory : public Resource
    {
        std::vector<Resource *> m_contents{};

    public:
        Directory() = default;
        Directory(const std::string &name);
        void update_parent_path(const std::string &);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory &operator+=(Resource *);
        Resource *find(const std::string &, const std::vector<OpFlags> &flagg = {});
        ~Directory();
        Directory(const Directory &) = delete;
        Directory &operator=(const Directory &) = delete;
        Directory(Directory &&) = delete;
        Directory &operator=(Directory &&) = delete;
    };

}

#endif
