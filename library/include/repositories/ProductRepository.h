//
// Created by student on 6/6/20.
//

#ifndef SELFPROTECTIONSHOP_PRODUCTREPOSITORY_H
#define SELFPROTECTIONSHOP_PRODUCTREPOSITORY_H
#include "model/Nightstick.h"
#include "model/Taser.h"
#include "model/PepperSpray.h"
#include "model/Product.h"
#include "repositories/Repository.h"

class ProductRepository : public Repository<Product>
{
public:
    ProductRepository();
    virtual ~ProductRepository();

};


#endif //SELFPROTECTIONSHOP_PRODUCTREPOSITORY_H
