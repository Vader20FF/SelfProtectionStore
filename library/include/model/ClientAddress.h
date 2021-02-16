#ifndef SELFPROTECTIONSHOP_CLIENTADDRESS_H
#define SELFPROTECTIONSHOP_CLIENTADDRESS_H
#include "model/Address.h"

class ClientAddress : public Address<ClientAddress> {
public:
    ClientAddress(const std::string &streetName, const std::string &streetNumber, const std::string &apartmentNumber, const std::string &postalCode, const std::string &cityName, const std::string &country);
    virtual ~ClientAddress();

    void setStreetName(const std::string &streetName);
    void setStreetNumber(const std::string &streetNumber);
    void setApartmentNumber(const std::string &apartmentNumber);
    void setPostalCode(const std::string &postalCode);
    void setCityName(const std::string &cityName);
    void setCountry(const std::string &country);
};


#endif //SELFPROTECTIONSHOP_CLIENTADDRESS_H
