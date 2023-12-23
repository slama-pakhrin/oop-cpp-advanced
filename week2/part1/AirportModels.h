#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
#include <string>
namespace sdds
{
    class Airport
    {
        std::string code;
        std::string name;
        std::string city;
        std::string state;
        std::string country;
        double latitude;
        double longitude;
    public:
        friend std::ostream& operator << (std::ostream& obj, const Airport& Airport);
    }
}

#endif