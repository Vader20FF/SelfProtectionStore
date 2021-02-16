//
// Created by student on 6/11/20.
//

#include "managers/ClientManager.h"
#include "exceptions/Exceptions.h"

using namespace std;

ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName, const std::string &emailAddress, const std::string &phoneNumber, ClientAddressPtr clientAddress, ShippingAddressPtr shippingAddress)
try {
    PhoneNumberPredicate predicate(phoneNumber);
    ClientPtr Check=find<PhoneNumberPredicate>(predicate);
    if (Check != nullptr)
    {
        return Check;
    } else if (clientAddress==nullptr || shippingAddress==nullptr) {
        return nullptr;
    } else{
        ClientPtr newClient(new Client(firstName, lastName, emailAddress, phoneNumber, clientAddress, shippingAddress));
        clientManagerRepositoryList->repositoryAdd(newClient);
        return newClient;
    }}catch(exception &e){
        throw FunctionException("Invalid data, cannot register Client");
    }



void ClientManager::unregisterClient(ClientPtr client)
{
    if(client == nullptr){
        throw FunctionException("Invalid data");
    }
    else clientManagerRepositoryList->repositoryRemove(client);
}


ClientPtr ClientManager::getClient(const string &phoneNumber)
{
    if(phoneNumber.empty()){
        throw FunctionException("Invalid data");
    }
    else{
    PhoneNumberPredicate predicate(phoneNumber);
    ClientPtr Check=find<PhoneNumberPredicate>(predicate);
    return Check;
    }
}


std::string ClientManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<ClientPtr>::const_iterator iter = clientManagerRepositoryList->begin(); iter != clientManagerRepositoryList->end(); iter++)
    {
        sout << (*iter)->getClientInfo() << endl;
    }
    return sout.str();
}


unsigned int ClientManager::size()
{
    return clientManagerRepositoryList->repositorySize();
}
