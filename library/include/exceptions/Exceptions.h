//
// Created by student on 17.06.2020.
//

#ifndef SELFPROTECTIONSHOP_EXCEPTIONS_H
#define SELFPROTECTIONSHOP_EXCEPTIONS_H

#include <string>
#include <stdexcept>

class ConstructorException : public std::logic_error
{
public:
    explicit ConstructorException(const std::string& what_arg) : std::logic_error(what_arg) {}
};


class FunctionException : public std::logic_error
{
public:
    explicit FunctionException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

#endif //SELFPROTECTIONSHOP_EXCEPTIONS_H
