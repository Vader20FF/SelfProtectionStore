
#include <sstream>
#include <exceptions/Exceptions.h>
#include "model/PepperSpray.h"

using namespace std;

PepperSpray::PepperSpray(const string &productName, double price, const string &manufacturer, const string &volume)
                        : Product(productName, price, manufacturer), volume(volume)
                        {
                            if(productName.empty() || price <=0 || manufacturer.empty() || volume.empty()){
                                throw ConstructorException("Invalid data");
                            }
                        }

PepperSpray::~PepperSpray()
{
}

const string &PepperSpray::getVolume() const {
    return volume;
}

std::string PepperSpray::getProductInfo() {
    ostringstream sout;
    sout << Product::getProductInfo();
    sout << "   Objetosc: " << getVolume();
    return sout.str();
}


