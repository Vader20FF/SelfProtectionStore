//
// Created by student on 6/11/20.
//

#ifndef SELFPROTECTIONSHOP_ORDERMANAGER_H
#define SELFPROTECTIONSHOP_ORDERMANAGER_H


#include <model/Order.h>
#include <repositories/OrderRepository.h>
#include <model/Predicates.h>
#include "managers/ProductManager.h"
#include <iostream>


class OrderManager{
private:
    OrderRepositoryPtr orderManagerRepositoryList=std::make_shared<OrderRepository>();

public:
    OrderPtr makeOrder(ClientPtr client, ShoppingCartPtr shoppingCart, const std::string &shippingMethod);
    void cancelOrder(OrderPtr order);
    void changeClientType(ClientPtr client);
    std::list<OrderPtr> getAllClientOrders(ClientPtr client);
    std::list<OrderPtr> findAll(OrderPredicate check);
    OrderPtr find(OrderPredicate check);
    std::string report();
    unsigned int size();
};


#endif //SELFPROTECTIONSHOP_ORDERMANAGER_H
