#include <exceptions/Exceptions.h>
#include "model/ShippingAddress.h"

ShippingAddress::ShippingAddress(const std::string &streetName, const std::string &streetNumber, const std::string &apartmentNumber, const std::string &postalCode,
                                 const std::string &cityName, const std::string &country)
        : Address(streetName, streetNumber, apartmentNumber, postalCode, cityName, country)
{
    if(streetName.empty() || streetNumber.empty() || apartmentNumber.empty() || postalCode.empty() || cityName.empty() || country.empty())
    {
        throw ConstructorException("Invalid date");
    }
}/*catch (std::exception &e){
    throw ConstructorException("Invalid date! cannot construct ShippingAddress");*/


ShippingAddress::~ShippingAddress()
{
}