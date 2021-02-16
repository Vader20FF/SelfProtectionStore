#include "model/Order.h"
#include "exceptions/Exceptions.h"

using namespace std;

Order::Order(ClientPtr client, ShoppingCartPtr shoppingCart, std::string shippingMethod)
        :  shippingMethod(shippingMethod) {

    if(client == nullptr || shoppingCart == nullptr || shippingMethod.empty()) {
        throw ConstructorException("Invalid Data");
    }
    else if (shoppingCart->getShoppingCartTotalCost() > client->getOrderPriceLimit()) {
        throw FunctionException("Card Total Cost is higher then Order Price Limit");
    }


    else {
        this->client = client;
        this->shoppingCart = shoppingCart;
        pt::ptime now = pt::second_clock::local_time();

        if (Order::orderDate == pt::not_a_date_time) {
            this->orderDate = now;
        }

        gr::date today = now.date();
        gr::date dayAfterTommorrow = today + gr::days(2);
        Order::estimatedDeliveryDate = dayAfterTommorrow;


        boost::uuids::random_generator gen;
        Order::orderID = gen();

        Order::totalCost = shoppingCart->getShoppingCartTotalCost();

        if (Order::getClient()->getIsRegularCustomer() == 1) {
            Order::totalCost = Order::totalCost * 0.8;
        }
    }
}


Order::~Order()
{

}



std::string Order::getOrderInfo()
{
    std::string stringID = to_string(Order::orderID);
    ostringstream sout;
    sout << "Informacje o zamowieniu: " << endl;
    sout << "-------------------------------------------" << endl;
    sout << "Numer zamowienia: " << stringID << endl;
    sout << "Data zlozenia zamowienia: " << Order::getOrderDate() << endl;
    sout << "Przewidywana data dostarczenia zamówienia: " << Order::getEstimatedDeliveryDate() << endl;
    sout << endl;
    sout << "Zamowienie zlozone przez klienta: " << endl;
    sout << Order::client->getClientInfo() << endl;
    sout << endl;
    sout << "Zamowienie zawiera: " << endl;
    sout << Order::shoppingCart->getShoppingCartInfo() << endl;
    sout << endl;
    sout << "Laczny koszt zamowienia: " << Order::getTotalCost() << endl;
    sout << "Wybrana metoda dostawy: " << Order::getShippingMethod() << endl;
    sout << "-------------------------------------------" << endl;

    return sout.str();
}



const boost::uuids::uuid &Order::getOrderID() const
{
    return Order::orderID;
}

const pt::ptime &Order::getOrderDate() const
{
    return Order::orderDate;
}

const gr::date &Order::getEstimatedDeliveryDate() const
{
    return Order::estimatedDeliveryDate;
}

ClientPtr Order::getClient() const
{
    return Order::client;
}

ShoppingCartPtr Order::getShoppingCart() const {
    return Order::shoppingCart;
}


const std::string &Order::getShippingMethod() const {
    return Order::shippingMethod;
}

const double &Order::getTotalCost() const
{
    return Order::totalCost;
}



void Order::setEstimatedDeliveryDate(const gr::date &estimatedDeliveryDate)
{
    gr::date orderDate1 = pt::second_clock::local_time().date();
    if((estimatedDeliveryDate < orderDate1) == 1){
        throw FunctionException("Invalid Data");
    }else Order::estimatedDeliveryDate=estimatedDeliveryDate;
}