
#include <sstream>
#include "model/Taser.h"
#include <exceptions/Exceptions.h>

using namespace std;

Taser::Taser(const string &productName, double price, const string &manufacturer, const string &voltage)
            : Product(productName, price, manufacturer), voltage(voltage)
            {
            if(productName.empty() || price <=0 || manufacturer.empty() || voltage.empty()){
                throw ConstructorException("Invalid data");
            }
            }

Taser::~Taser()
{
}

const string Taser::getVoltage() const {
    return voltage;
}

std::string Taser::getProductInfo() {
    ostringstream sout;
    sout << Product::getProductInfo();
    sout << "   Moc: " << getVoltage();
    return sout.str();
}

