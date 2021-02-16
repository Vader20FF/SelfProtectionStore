//
// Created by student on 6/6/20.
//

#ifndef SELFPROTECTIONSHOP_ORDERREPOSITORY_H
#define SELFPROTECTIONSHOP_ORDERREPOSITORY_H
#include "repositories/Repository.h"

class OrderRepository : public Repository<Order>
{
public:
    OrderRepository();
    virtual ~OrderRepository();

};

#endif //SELFPROTECTIONSHOP_ORDERREPOSITORY_H
