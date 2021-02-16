

#ifndef SELFPROTECTIONSHOP_PRODUCT_H
#define SELFPROTECTIONSHOP_PRODUCT_H

#include "model/typedefs.h"
#include "boost/uuid/uuid.hpp"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


class Product {

private:
    std::string productName;
    double price;
    std::string manufacturer;
    boost::uuids::uuid productID;

public:

    Product(const std::string &productName, double price, const std::string &manufacturer);

    virtual ~Product() = 0;

    const std::string &getProductName() const;
    double getPrice() const;
    const std::string &getManufacturer() const;
    const boost::uuids::uuid &getProductId() const;

    virtual std::string getProductInfo();

    void setPrice(double price);

};


#endif //SELFPROTECTIONSHOP_PRODUCT_H
