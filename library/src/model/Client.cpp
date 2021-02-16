#include <exceptions/Exceptions.h>
#include "model/Client.h"

using namespace std;


Client::Client(const std::string &firstName, const std::string &lastName, const std::string &emailAddress, const std::string &phoneNumber,
               ClientAddressPtr clientAddress, ShippingAddressPtr shippingAddress)
        : firstName(firstName), lastName(lastName), emailAddress(emailAddress), phoneNumber(phoneNumber)
{
    if(firstName.empty() || lastName.empty() || emailAddress.empty() || phoneNumber.empty() || clientAddress == nullptr || shippingAddress ==
                                                                                                                                   nullptr)
    {
        throw ConstructorException("Invalid date");
    }

    this->clientAddress = clientAddress;
    this->shippingAddress = shippingAddress;
}


Client::~Client()
{
}



std::string Client::getClientInfo()
{
    ostringstream sout;
    sout << "Informacje o kliencie: " << endl;
    sout << Client::getFirstName() << " " << Client::getLastName() << "  " << endl;
    sout << Client::getEmailAddress() << endl;
    sout << Client::getPhoneNumber() << endl;
    sout << endl;
    sout << "Adres korespondencyjny klienta:" << endl;
    sout << clientAddress->getAddressInfo() << endl;
    sout << "Adres wysylkowy klienta:" << endl;
    sout << shippingAddress->getAddressInfo() << endl;

    if (getIsRegularCustomer()==0)
    {
        sout << Client::getFirstName() << " " << Client::getLastName() << " nie jest stalym klientem." << endl;
    }
    else
    {
        sout << Client::getFirstName() << " " << Client::getLastName() << " jest stalym klientem." << endl;
    }
    sout << "Limit zakupow dla tego klienta wynosi: " << Client::getOrderPriceLimit() << endl;

    return sout.str();
}



const std::string &Client::getFirstName() const
{
    return Client::firstName;
}

const std::string &Client::getLastName() const
{
    return Client::lastName;
}

const std::string &Client::getEmailAddress() const
{
    return Client::emailAddress;
}

const std::string &Client::getPhoneNumber() const
{
    return Client::phoneNumber;
}

ClientAddressPtr Client::getClientAddress() const
{
    return Client::clientAddress;
}

ShippingAddressPtr Client::getShippingAddress() const
{
    return Client::shippingAddress;
}

const bool &Client::getIsRegularCustomer() const
{
    return Client::isRegularCustomer;
}

double Client::getOrderPriceLimit()
{
    if (Client::getIsRegularCustomer()==1)
    {
        return 4000;
    } else {
        return Client::orderPriceLimit;
    }
}



void Client::setFirstName(const std::string &firstName)
{
    if (firstName.empty())
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::firstName=firstName;
    }
}

void Client::setLastName(const std::string &lastName)
{
    if (lastName.empty())
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::lastName=lastName;
    }
}

void Client::setEmailAddress(const std::string &emailAddress)
{
    if (emailAddress.empty())
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::emailAddress=emailAddress;
    }
}

void Client::setPhoneNumber(const std::string &phoneNumber)
{
    if (phoneNumber.empty())
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::phoneNumber=phoneNumber;
    }
}

void Client::setClientAddress(ClientAddressPtr clientAddress)
{
    if (clientAddress==nullptr)
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::clientAddress=clientAddress;
    }
}

void Client::setShippingAddress(ShippingAddressPtr shippingAddress)
{
    if (shippingAddress==nullptr)
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::shippingAddress=shippingAddress;
    }
}

void Client::setIsRegularCustomer(const bool &isRegularCustomer)
{
    Client::isRegularCustomer=isRegularCustomer;
}

void Client::setOrderPriceLimit(double orderPriceLimit)
{
    if (orderPriceLimit>2000.0)
    {
        throw FunctionException("Invalid date!");
    } else {
        Client::orderPriceLimit=orderPriceLimit;
    }
}