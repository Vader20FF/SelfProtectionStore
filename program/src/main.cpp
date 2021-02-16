#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Order.h"
#include "model/ShoppingCart.h"
#include "managers/OrderManager.h"
#include "managers/ClientManager.h"
#include "managers/ProductManager.h"
#include <boost/date_time.hpp>


namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;

int main()
{

    ClientAddressPtr clientAddress(new ClientAddress("Klientowa", "18", "92", "23-254", "Lodz", "Polska"));
    ShippingAddressPtr shippingAddress(new ShippingAddress("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska"));
    ClientPtr client(new Client("Adam", "Glab", "adam.glab@poczta.pl", "233456938", clientAddress, shippingAddress));

//    cout << client->getClientInfo();

//    pt::ptime empty = pt::not_a_date_time;
//    cout << empty << endl;
//    pt::ptime now = pt::ptime(gr::date(2015,5,12),pt::hours(9)+pt::minutes(24));
//    cout << now << endl;
//    pt::ptime then = pt::ptime(gr::date(2015,5,12),pt::hours(7)+pt::minutes(23));
//    cout << then << endl;
//    pt::time_period period(then, now);
//    cout << period << endl;
//    cout << period.length() << endl << "TERAZ";
//    cout << period.length().hours() << endl << "TERAZ";
//    cout << period.length().minutes() << endl;
//    cout << (then>now) << endl;
//    cout << (then<=now) << endl;

    TaserPtr taser(new Taser("paralizator3000", 1600.0, "producent", "35V"));
    NightstickPtr nightStick(new Nightstick("palka", 100.0, "producent2", "tworzywo"));
    PepperSprayPtr pepperSpray(new PepperSpray("gaz", 50.0, "producent3", "200ml"));

//    cout << taser->getProductInfo();
//    cout << endl;




    ShoppingCartPtr shoppingCart(new ShoppingCart());
    shoppingCart->repositoryAdd(taser);
    shoppingCart->repositoryAdd(nightStick);
    shoppingCart->repositoryAdd(pepperSpray);

//    cout << endl;
//    cout << shoppingCart->getShoppingCartInfo();
//    cout << endl;

    OrderPtr order(new Order(client,shoppingCart,"za pobraniem"));
    cout << endl;
    cout << order->getOrderInfo();
    cout << endl;

    OrderManagerPtr testOrderManager(new OrderManager());
    cout << testOrderManager->makeOrder(client,shoppingCart,"za pobraniem")->getOrderInfo() << endl;
    //try {
     //   OrderPtr order (new Order(nullptr, nullptr,"aaa"));
   // }catch(exception &e){
   //     cout << e.what() << " yes ";
   // }

    return 0;
}