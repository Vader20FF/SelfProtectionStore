
#include <sstream>
#include <exceptions/Exceptions.h>
#include "model/Nightstick.h"

using namespace std;


Nightstick::Nightstick(const string &productName, double price, const string &manufacturer, const string &material)
                       : Product(productName, price, manufacturer), material(material)
                       {
                           if(productName.empty() || price <=0 || manufacturer.empty() || material.empty()){
                               throw ConstructorException("Invalid data");
                           }
                       }

Nightstick::~Nightstick()
{
}

const string &Nightstick::getMaterial() const {
    return material;
}

std::string Nightstick::getProductInfo() {
    ostringstream sout;
    sout << Product::getProductInfo();
    sout << "   Material: " << getMaterial();
    return sout.str();
}




