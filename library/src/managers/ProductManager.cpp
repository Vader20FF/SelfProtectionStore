//
// Created by student on 6/11/20.
//

#include "managers/ProductManager.h"
#include <iostream>
#include "exceptions/Exceptions.h"

using namespace std;


ProductPtr ProductManager::registerNightstick(const std::string &productName, double basePrice, const std::string &manufacturer, const std::string &material)
try{
    ProductNamePredicate predicate(productName);
    ProductPtr wsk=find<ProductNamePredicate>(predicate);

    if (wsk != nullptr)
    {
        return wsk;
    }

    else{
        ProductPtr newNightstick(new Nightstick(productName, basePrice, manufacturer, material));
        productManagerRepositoryList->repositoryAdd(newNightstick);
        return newNightstick;
    }
}catch(exception &e) {
    throw FunctionException("Invalid data, cannot register NightStick");
}


ProductPtr ProductManager::registerTaser(const std::string &productName, double basePrice, const std::string &manufacturer, const std::string &voltage)
try{
    ProductNamePredicate predicate(productName);
    ProductPtr wsk=find<ProductNamePredicate>(predicate);

    if (wsk != nullptr)
    {
        return wsk;
    }

    else{
        ProductPtr newTaser(new Taser(productName, basePrice, manufacturer, voltage));
        productManagerRepositoryList->repositoryAdd(newTaser);
        return newTaser;
    }
}catch(exception &e) {
    throw FunctionException("Invalid data, cannot register Taser");
}


ProductPtr ProductManager::registerPepperSpray(const std::string &productName, double basePrice, const std::string &manufacturer, const std::string &volume)
try{
    ProductNamePredicate predicate(productName);
    ProductPtr wsk=find<ProductNamePredicate>(predicate);

    if (wsk != nullptr)
    {
        return wsk;
    }

    else{
        ProductPtr newPepperSpray(new PepperSpray(productName, basePrice, manufacturer, volume));
        productManagerRepositoryList->repositoryAdd(newPepperSpray);
        return newPepperSpray;
    }
}catch(exception &e) {
    throw FunctionException("Invalid data, cannot register PepperSpray");
}


void ProductManager::removeProduct(ProductPtr product)
{
    if(product == nullptr){
        throw FunctionException("Invalid data");
    }
    else productManagerRepositoryList->repositoryRemove(product);
}


ProductPtr ProductManager::getProduct(const string &productName)
{
    if(productName.empty()){
        throw FunctionException("Invalid data");
    }
    else {
        ProductNamePredicate predicate(productName);
        ProductPtr wsk = find<ProductNamePredicate>(predicate);
        return wsk;
    }
}


std::string ProductManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<ProductPtr>::const_iterator iter = productManagerRepositoryList->begin(); iter != productManagerRepositoryList->end(); iter++)
    {
        sout << (*iter)->getProductInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


unsigned int ProductManager::size()
{
    return productManagerRepositoryList->repositorySize();
}
