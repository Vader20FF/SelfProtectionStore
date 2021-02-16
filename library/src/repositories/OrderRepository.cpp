//
// Created by student on 6/6/20.
//

#include <exceptions/Exceptions.h>
#include "repositories/OrderRepository.h"

OrderRepository::OrderRepository() try{

}catch(...){
    throw ConstructorException("cannot create Repository");
}

OrderRepository::~OrderRepository() {

}