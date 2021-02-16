//
// Created by student on 6/6/20.
//

#include "model/ShoppingCart.h"
#include "exceptions/Exceptions.h"

using namespace std;

ShoppingCart::ShoppingCart()
try{


}catch(exception &e){
    throw ConstructorException("Cannot create ShoppingCart");
}


ShoppingCart::~ShoppingCart()
{
}



std::string ShoppingCart::getShoppingCartInfo() {
    ostringstream sout;
    sout << "Koszyk: " << endl;
    sout << "-------------------------------------------" << endl;
    for (list<ProductPtr>::const_iterator iter = objectsRepository.begin(); iter != objectsRepository.end(); iter++)
    {
        sout << (*iter)->getProductInfo() << endl;
        sout << endl;
    }

    return sout.str();
}



double ShoppingCart::getShoppingCartTotalCost()
{
    ShoppingCart::shoppingCartTotalCost=0;
    for (list<ProductPtr>::const_iterator iter = objectsRepository.begin(); iter != objectsRepository.end(); iter++)
    {
        ShoppingCart::shoppingCartTotalCost=ShoppingCart::shoppingCartTotalCost+(*iter)->getPrice();
    }

    return ShoppingCart::shoppingCartTotalCost;
}
