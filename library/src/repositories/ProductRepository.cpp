//
// Created by student on 6/6/20.
//

#include <exceptions/Exceptions.h>
#include "repositories/ProductRepository.h"

ProductRepository::ProductRepository() try{

}catch(...){
    throw ConstructorException("cannot create Repository");
}

ProductRepository::~ProductRepository() {

}