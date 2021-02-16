//
// Created by student on 6/6/20.
//

#ifndef SELFPROTECTIONSHOP_CLIENTREPOSITORY_H
#define SELFPROTECTIONSHOP_CLIENTREPOSITORY_H
#include "repositories/Repository.h"

class ClientRepository : public Repository<Client>
{
public:
    ClientRepository();
    virtual ~ClientRepository();

};


#endif //SELFPROTECTIONSHOP_CLIENTREPOSITORY_H
