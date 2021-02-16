
#ifndef SELFPROTECTIONSHOP_TASER_H
#define SELFPROTECTIONSHOP_TASER_H


#include "Product.h"

class Taser : public Product {

private:
    std::string voltage;

public:
    Taser(const std::string &productName, double price, const std::string &manufacturer, const std::string &voltage);

    virtual ~Taser();

    const std::string getVoltage() const;

    std::string getProductInfo() override;
};


#endif //SELFPROTECTIONSHOP_TASER_H
