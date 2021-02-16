//
// Created by student on 6/11/20.
//

#include "exceptions/Exceptions.h"
#include "managers/OrderManager.h"

using namespace std;


OrderPtr OrderManager::makeOrder(ClientPtr client, ShoppingCartPtr shoppingCart, const string &shippingMethod)
{
    if (shoppingCart->getShoppingCartTotalCost() > client->getOrderPriceLimit())
    {
        throw FunctionException("Cart Total Cost is higher than Order Price Limit");
    } else {
        OrderPtr newOrder(new Order(client, shoppingCart, shippingMethod));
        orderManagerRepositoryList->repositoryAdd(newOrder);
        changeClientType(client);
        return newOrder;
    }

}


void OrderManager::cancelOrder(OrderPtr order)
{
    if(order == nullptr){
        throw FunctionException("Invalid data");
    }
    else {
        orderManagerRepositoryList->repositoryRemove(order);
        changeClientType(order->getClient());
    }
}


void OrderManager::changeClientType(ClientPtr client)
{
    if(client == nullptr){
        throw FunctionException("Invalid data");
    }
    else {
        if (getAllClientOrders(client).size() >= 5) {
            if (client->getIsRegularCustomer() == 1) {
            } else {
                client->setIsRegularCustomer(1);
            }
        } else {
            if (client->getIsRegularCustomer() == 1) {
                client->setIsRegularCustomer(0);
            } else {
            }
        }
    }
}


std::list<OrderPtr> OrderManager::getAllClientOrders(ClientPtr client)
{
    if(client == nullptr){
        throw FunctionException("Invalid data");
    } else {
        list<OrderPtr> ClientTotalOrdersList = findAll(
                [client](OrderPtr order) { return order->getClient() == client; });
        return ClientTotalOrdersList;
    }
}


std::list<OrderPtr> OrderManager::findAll(OrderPredicate check)
{
    list<OrderPtr> Searched;


    for (std::list<OrderPtr>::const_iterator iter = orderManagerRepositoryList->begin(); iter != orderManagerRepositoryList->end(); iter++)
    {
        if (check(*iter))
            Searched.push_back(*iter);
    }

    return Searched;
}


OrderPtr OrderManager::find(OrderPredicate check)
{
    for (std::list<OrderPtr>::const_iterator iter = orderManagerRepositoryList->begin(); iter != orderManagerRepositoryList->end(); iter++)
    {
        if(check(*iter)==1)
        {
            return *iter;
        }
    }

    return nullptr;

}


std::string OrderManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<OrderPtr>::const_iterator iter = orderManagerRepositoryList->begin(); iter != orderManagerRepositoryList->end(); iter++)
    {
        sout << (*iter)->getOrderInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


unsigned int OrderManager::size()
{
    return orderManagerRepositoryList->repositorySize();
}
