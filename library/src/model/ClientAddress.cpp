#include <exceptions/Exceptions.h>
#include "model/ClientAddress.h"

ClientAddress::ClientAddress(const std::string &streetName, const std::string &streetNumber, const std::string &apartmentNumber, const std::string &postalCode,
                             const std::string &cityName, const std::string &country)
       : Address(streetName, streetNumber, apartmentNumber, postalCode, cityName, country)
{
    if(streetName.empty() || streetNumber.empty() || apartmentNumber.empty() || postalCode.empty() || cityName.empty() || country.empty())
    {
        throw ConstructorException("Invalid date");
    }
}


ClientAddress::~ClientAddress()
{
}



void ClientAddress::setStreetName(const std::string &streetName)
{
    if (streetName.empty())
    {
        throw FunctionException("Invalid data!");
    } else {
        ClientAddress::streetName=streetName;
    }
}

void ClientAddress::setStreetNumber(const std::string &streetNumber)
{
    if (streetNumber.empty())
    {
        throw FunctionException("Invalid data!");
    } else {
        ClientAddress::streetNumber=streetNumber;
    }
}

void ClientAddress::setApartmentNumber(const std::string &apartmentNumber)
{
    if (apartmentNumber.empty())
    {
        throw FunctionException("Invalid data!");
    } else {
        ClientAddress::apartmentNumber=apartmentNumber;
    }
}

void ClientAddress::setPostalCode(const std::string &postalCode)
{
    if (postalCode.empty())
    {
        throw FunctionException("Invalid data!");
    } else {
        ClientAddress::postalCode=postalCode;
    }
}

void ClientAddress::setCityName(const std::string &cityName)
{
    if (cityName.empty())
    {
        throw FunctionException("Invalid data!");
    } else {
        ClientAddress::cityName=cityName;
    }
}

void ClientAddress::setCountry(const std::string &country)
{
    if (country.empty())
    {
        throw FunctionException("Invalid data!");
    } else {
        ClientAddress::country=country;
    }
}