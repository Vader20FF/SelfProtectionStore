

#ifndef SELFPROTECTIONSHOP_PEPPERSPRAY_H
#define SELFPROTECTIONSHOP_PEPPERSPRAY_H


#include "Product.h"

class PepperSpray : public Product{

private:
    std::string volume;

public:
    PepperSpray(const std::string &productName, double price, const std::string &manufacturer, const std::string &volume);

    virtual ~PepperSpray();

    const std::string &getVolume() const;

    std::string getProductInfo() override;
};


#endif //SELFPROTECTIONSHOP_PEPPERSPRAY_H
