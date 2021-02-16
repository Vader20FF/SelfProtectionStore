//
// Created by student on 6/11/20.
//

#ifndef SELFPROTECTIONSHOP_CLIENTMANAGER_H
#define SELFPROTECTIONSHOP_CLIENTMANAGER_H
#include <model/Client.h>
#include <repositories/ClientRepository.h>
#include <model/Predicates.h>

using namespace std;

class ClientManager{
private:
    ClientRepositoryPtr clientManagerRepositoryList=std::make_shared<ClientRepository>();

public:
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &emailAddress, const std::string &phoneNumber, ClientAddressPtr clientAddress, ShippingAddressPtr shippingAddress);
    void unregisterClient(ClientPtr client);
    ClientPtr getClient(const std::string &phoneNumber);
    template <class P> std::list<ClientPtr> findAll(const P &predicate) const;
    template <class P> ClientPtr find(const P &check);
    std::string report();
    unsigned int size();

};


template<class P> std::list<ClientPtr> ClientManager::findAll(const P &predicate) const
{
    std::list<ClientPtr> Searched;
    for (std::list<ClientPtr>::const_iterator iter = this->clientManagerRepositoryList->begin(), end = this->clientManagerRepositoryList->end(); iter != end; ++iter)
    {
        if(predicate(*iter))
        {
            Searched.push_back(*iter);
        }

    }

    return Searched;
}


template<class P> ClientPtr ClientManager::find(const P &predicate)
{
    for (std::list<ClientPtr>::const_iterator iter = this->clientManagerRepositoryList->begin(); iter != this->clientManagerRepositoryList->end(); ++iter)
    {
        if(predicate(*iter))
        {
            return *iter;
        }

    }

    return nullptr;
}



#endif //SELFPROTECTIONSHOP_CLIENTMANAGER_H
