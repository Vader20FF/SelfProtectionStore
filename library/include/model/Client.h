#ifndef SELFPROTECTIONSHOP_CLIENT_H
#define SELFPROTECTIONSHOP_CLIENT_H
#include <string>
#include <sstream>
#include <iostream>
#include "model/typedefs.h"
#include "model/ClientAddress.h"
#include "model/ShippingAddress.h"

class Client{
private:
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    std::string phoneNumber;
    ClientAddressPtr clientAddress;
    ShippingAddressPtr shippingAddress;
    bool isRegularCustomer=0;
    double orderPriceLimit=2000.0;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &emailAddress, const std::string &phoneNumber, ClientAddressPtr clientAddress, ShippingAddressPtr shippingAddress);
    virtual ~Client();

    std::string getClientInfo();

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getEmailAddress() const;
    const std::string &getPhoneNumber() const;
    ClientAddressPtr getClientAddress() const;
    ShippingAddressPtr getShippingAddress() const;
    const bool &getIsRegularCustomer() const;
    double getOrderPriceLimit();

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setEmailAddress(const std::string &emailAddress);
    void setPhoneNumber(const std::string &phoneNumber);
    void setClientAddress(ClientAddressPtr clientAddress);
    void setShippingAddress(ShippingAddressPtr shippingAddress);
    void setIsRegularCustomer(const bool &isRegularCustomer);
    void setOrderPriceLimit(double orderPriceLimit);


};


#endif //SELFPROTECTIONSHOP_CLIENT_H
