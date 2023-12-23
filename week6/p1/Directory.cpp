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

#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include "Directory.h"
#include "Flags.h"

using namespace std;
namespace sdds
{
    Directory::Directory(const std::string &name)
    {
        m_name = name;
    }
    void Directory::update_parent_path(const std::string &crpath)
    {
        m_parent_path = crpath;
        for (size_t i = 0; i < m_contents.size(); i++)
        {
            m_contents[i]->update_parent_path(path());
        }
    }
    NodeType Directory::type() const
    {
        return sdds::NodeType::DIR;
    }
    std::string Directory::path() const
    {
        return m_parent_path + m_name;
    }
    std::string Directory::name() const
    {
        return m_name;
    }
    int Directory::count() const
    {
        return int(m_contents.size());
    }
    size_t Directory::size() const
    {
        size_t total = 0u;
        for (size_t i = 0; i < m_contents.size(); i++)
        {
            total += m_contents[i]->size();
        }
        return total;
    }
    Directory &Directory::operator+=(Resource *other)
    {
        for (size_t i = 0; i < m_contents.size(); i++)
        {
            if (m_contents[i]->name() == other->name())
            {
                throw exception();
            }
        }
        m_contents.push_back(other);

        //        m_contents[m_contents.size()-1]->update_parent_path( m_contents[m_contents.size()-1]->path());
        other->update_parent_path(path());

        return *this;
    }
    Resource *Directory::find(const std::string &name, const std::vector<OpFlags> &flagg)
    {
        for (size_t i = 0; i < m_contents.size(); i++)
        {
            // Check if the RECURSIVE flag is set in the flagg vector
            bool isRecursive = false;
            for (OpFlags flags : flagg)
            {
                if (flags == sdds::OpFlags::RECURSIVE)
                {
                    isRecursive = true;
                }
            }
            if (m_contents[i]->name() == name)
            {
                return m_contents[i];
            }
            if (isRecursive && m_contents[i]->type() == sdds::NodeType::DIR)
            {
                Resource *find = dynamic_cast<Directory *>(m_contents[i])->find(name, flagg);
                if (find)
                {
                    return find;
                }
            }
        }
        return nullptr;
    }
    Directory::~Directory()
    {
        for (size_t i = 0; i < m_contents.size(); i++)
        {
            delete m_contents[i];
        }
    }
}
