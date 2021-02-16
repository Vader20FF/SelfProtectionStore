
#include <sstream>
#include <cmath>
#include "model/Product.h"
#include "exceptions/Exceptions.h"


using namespace std;

Product::Product(const string &productName, double price, const string &manufacturer)
                : productName(productName), price(fabs(price)), manufacturer(manufacturer)
                {
                    boost::uuids::random_generator gen;
                    Product::productID = gen();
                }

Product::~Product()
{
}



const string &Product::getProductName() const {
    return productName;
}

double Product::getPrice() const {
    return price;
}

const string &Product::getManufacturer() const {
    return manufacturer;
}

const boost::uuids::uuid &Product::getProductId() const {
    return productID;
}

std::string Product::getProductInfo() {
    ostringstream sout;
    sout << "Informacje o produkcie: " << endl;
    sout << "   Nazwa produktu: " << getProductName() << endl;
    sout << "   Cena: " << getPrice() << endl;
    sout << "   Producent: " << getManufacturer() << endl;
    sout << "   Id produktu: " << to_string(Product::productID) << endl;

    return sout.str();
}

void Product::setPrice(double price)
{
    if (price <= 0)
    {
        throw FunctionException("Invalid date!");
    }
    else Product::price = price;
}




