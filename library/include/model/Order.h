//
// Created by student on 6/6/20.
//

#ifndef SELFPROTECTIONSHOP_ORDER_H
#define SELFPROTECTIONSHOP_ORDER_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "model/typedefs.h"
#include <sstream>
#include <string>
#include "model/ShoppingCart.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


class Order{
private:
    boost::uuids::uuid orderID;
    pt::ptime orderDate;
    gr::date estimatedDeliveryDate;
    ClientPtr client;
    ShoppingCartPtr shoppingCart;
    std::string shippingMethod;
    double totalCost=0;

public:
    Order(ClientPtr client, ShoppingCartPtr shoppingCart, std::string shippingMethod);
    virtual ~Order();

    std::string getOrderInfo();

    const boost::uuids::uuid &getOrderID() const;
    const pt::ptime &getOrderDate() const;
    const gr::date &getEstimatedDeliveryDate() const;
    ClientPtr getClient() const;
    ShoppingCartPtr getShoppingCart() const;
    const std::string &getShippingMethod() const;
    const double &getTotalCost() const;

    void setEstimatedDeliveryDate(const gr::date &estimatedDeliveryDate);
};



#endif //SELFPROTECTIONSHOP_ORDER_H
