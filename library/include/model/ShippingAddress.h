#ifndef SELFPROTECTIONSHOP_SHIPPINGADDRESS_H
#define SELFPROTECTIONSHOP_SHIPPINGADDRESS_H
#include "model/Address.h"

class ShippingAddress : public Address<ShippingAddress> {
public:
    ShippingAddress(const std::string &streetName, const std::string &streetNumber, const std::string &apartmentNumber, const std::string &postalCode, const std::string &cityName, const std::string &country);
    virtual ~ShippingAddress();
};


#endif //SELFPROTECTIONSHOP_SHIPPINGADDRESS_H
