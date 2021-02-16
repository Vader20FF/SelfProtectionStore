//
// Created by student on 06.06.2020.
//

#ifndef SELFPROTECTIONSHOP_NIGHTSTICK_H
#define SELFPROTECTIONSHOP_NIGHTSTICK_H


#include "Product.h"

class Nightstick : public Product {

private:
    std::string material;

public:
    Nightstick(const std::string &productName, double price, const std::string &manufacturer, const std::string &material);

    virtual ~Nightstick();

    const std::string &getMaterial() const;

    std::string getProductInfo() override ;
};


#endif //SELFPROTECTIONSHOP_NIGHTSTICK_H
