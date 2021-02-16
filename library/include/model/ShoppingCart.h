//
// Created by student on 6/6/20.
//

#ifndef SELFPROTECTIONSHOP_SHOPPINGCART_H
#define SELFPROTECTIONSHOP_SHOPPINGCART_H
#include "repositories/Repository.h"
#include "model/Product.h"
#include "model/Taser.h"
#include "model/Nightstick.h"
#include "model/PepperSpray.h"
#include <sstream>
#include <string>


class ShoppingCart : public Repository<Product>
{
private:
    double shoppingCartTotalCost=0;

public:
    ShoppingCart();
    virtual ~ShoppingCart();

    std::string getShoppingCartInfo();

    double getShoppingCartTotalCost();

};

#endif //SELFPROTECTIONSHOP_SHOPPINGCART_H
