//
// Created by student on 6/11/20.
//

#ifndef SELFPROTECTIONSHOP_PREDICATES_H
#define SELFPROTECTIONSHOP_PREDICATES_H
#include "model/typedefs.h"
#include "model/Order.h"
#include <regex>

class FirstNamePredicate {
private:
    std::string pattern;

public:
    explicit FirstNamePredicate(const std::string &pattern);
    bool operator()(const ClientPtr &ptr) const;
};


class LastNamePredicate{
private:
    std::string pattern;

public:
    explicit LastNamePredicate(const std::string &pattern);
    bool operator()(const ClientPtr &ptr) const;
};


class EmailAddressPredicate
{
private:
    std::string pattern;

public:
    explicit EmailAddressPredicate(const std::string &pattern);
    bool operator()(const ClientPtr &ptr) const;
};


class PhoneNumberPredicate
{
private:
    std::string pattern;

public:
    explicit PhoneNumberPredicate(const std::string &pattern);
    bool operator()(const ClientPtr &ptr) const;
};


class ProductNamePredicate
{
private:
    std::string pattern;

public:
    explicit ProductNamePredicate(const std::string &pattern);
    bool operator()(const ProductPtr &ptr) const;
};


class ManufacturerPredicate
{
private:
    std::string pattern;

public:
    explicit ManufacturerPredicate(const std::string &pattern);
    bool operator()(const ProductPtr &ptr) const;
};


#endif //SELFPROTECTIONSHOP_PREDICATES_H
