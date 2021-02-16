//
// Created by student on 6/11/20.
//

#ifndef SELFPROTECTIONSHOP_PRODUCTMANAGER_H
#define SELFPROTECTIONSHOP_PRODUCTMANAGER_H


#include <model/Product.h>
#include <repositories/ProductRepository.h>
#include <model/typedefs.h>
#include <model/Taser.h>
#include <model/Nightstick.h>
#include <model/PepperSpray.h>
#include <model/Predicates.h>

class ProductManager{
private:
    ProductRepositoryPtr productManagerRepositoryList=std::make_shared<ProductRepository>();

public:
    ProductPtr registerNightstick(const std::string &productName, double basePrice, const std::string &manufacturer, const std::string &material);
    ProductPtr registerTaser(const std::string &productName, double basePrice, const std::string &manufacturer, const std::string &voltage);
    ProductPtr registerPepperSpray(const std::string &productName, double basePrice, const std::string &manufacturer, const std::string &volume);
    void removeProduct(ProductPtr product);
    ProductPtr getProduct(const std::string &productName);

    template <class P> std::list<ProductPtr> findAll(const P &predicate);
    template <class P> ProductPtr find(const P &predicate);
    std::string report();
    unsigned int size();

};

template <class P> std::list<ProductPtr> ProductManager::findAll(const P &predicate)
{
    std::list<ProductPtr> Searched;

    for (std::list<ProductPtr>::const_iterator iter = productManagerRepositoryList->begin(); iter != productManagerRepositoryList->end(); iter++)
    {
        if(predicate(*iter)==1)
        {
            Searched.push_back(*iter);
        }

    }

    return Searched;
}


template <class P> ProductPtr ProductManager::find(const P &predicate)
{
    for (std::list<ProductPtr>::const_iterator iter = productManagerRepositoryList->begin(); iter != productManagerRepositoryList->end(); iter++)
    {
        if(predicate(*iter)==1)
        {
            return *iter;
        }

    }

    return nullptr;
}


#endif //SELFPROTECTIONSHOP_PRODUCTMANAGER_H
