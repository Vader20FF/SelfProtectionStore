#ifndef SELFPROTECTIONSHOP_ADDRESS_H
#define SELFPROTECTIONSHOP_ADDRESS_H
#include <string>
#include <sstream>
#include <iostream>
#include "model/typedefs.h"

template<class T> class Address{
protected:
    std::string streetName;
    std::string streetNumber;
    std::string apartmentNumber;
    std::string postalCode;
    std::string cityName;
    std::string country;

public:
    Address(const std::string &streetName, const std::string &streetNumber, const std::string &apartmentNumber, const std::string &postalCode, const std::string &cityName, const std::string &country);

    std::string getAddressInfo();

    const std::string getStreetName() const;
    const std::string getStreetNumber() const;
    const std::string getApartmentNumber() const;
    const std::string getPostalCode() const;
    const std::string getCityName() const;
    const std::string getCountry() const;

};

template<class T>
Address<T>::Address(const std::string &streetName, const std::string &streetNumber, const std::string &apartmentNumber, const std::string &postalCode,
                    const std::string &cityName, const std::string &country)
        : streetName(streetName), streetNumber(streetNumber), apartmentNumber(apartmentNumber), postalCode(postalCode), cityName(cityName), country(country)
{
}

template<class T>
std::string Address<T>::getAddressInfo()
{
    std::ostringstream sout;
    sout << Address::getStreetName() << " " << Address::getStreetNumber() << "/" << Address::getApartmentNumber() << std::endl;
    sout << Address::getPostalCode() << " " << Address::getCityName() << std::endl;
    sout << Address::getCountry() << std::endl;
    return sout.str();
}



template<class T>
const std::string Address<T>::getStreetName() const
{
    return Address::streetName;
}

template<class T>
const std::string Address<T>::getStreetNumber() const
{
    return Address::streetNumber;
}

template<class T>
const std::string Address<T>::getApartmentNumber() const
{
    return Address::apartmentNumber;
}

template<class T>
const std::string Address<T>::getPostalCode() const
{
    return Address::postalCode;
}

template<class T>
const std::string Address<T>::getCityName() const
{
    return Address::cityName;
}

template<class T>
const std::string Address<T>::getCountry() const
{
    return Address<T>::country;
}

#endif //SELFPROTECTIONSHOP_ADDRESS_H


