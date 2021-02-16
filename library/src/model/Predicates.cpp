//
// Created by student on 6/11/20.
//

#include "model/Predicates.h"

using namespace std;


FirstNamePredicate::FirstNamePredicate(const std::string &pattern) : pattern(pattern)
{
}


bool FirstNamePredicate::operator()(const ClientPtr &ptr) const
{
    regex finalPattern{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getFirstName(), finalPattern);
}


LastNamePredicate::LastNamePredicate(const string &pattern) : pattern(pattern)
{
}


bool LastNamePredicate::operator()(const ClientPtr &ptr) const
{
    regex finalPattern{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getLastName(), finalPattern);
}


EmailAddressPredicate::EmailAddressPredicate(const string &pattern) : pattern(pattern)
{
}


bool EmailAddressPredicate::operator()(const ClientPtr &ptr) const
{
    regex finalPattern{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getEmailAddress(), finalPattern);
}


PhoneNumberPredicate::PhoneNumberPredicate(const string &pattern) : pattern(pattern)
{
}


bool PhoneNumberPredicate::operator()(const ClientPtr &ptr) const
{
    regex finalPattern{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getPhoneNumber(), finalPattern);
}

ProductNamePredicate::ProductNamePredicate(const string &pattern) : pattern(pattern)
{
}


bool ProductNamePredicate::operator()(const ProductPtr &ptr) const
{
    regex finalPattern{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getProductName(), finalPattern);
}

ManufacturerPredicate::ManufacturerPredicate(const string &pattern) : pattern(pattern)
{
}


bool ManufacturerPredicate::operator()(const ProductPtr &ptr) const
{
    regex finalPattern{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getManufacturer(), finalPattern);
}