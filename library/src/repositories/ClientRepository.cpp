//
// Created by student on 6/6/20.
//

#include <exceptions/Exceptions.h>
#include "repositories/ClientRepository.h"

ClientRepository::ClientRepository() try{

}catch(...){
    throw ConstructorException("cannot create Repository");
}

ClientRepository::~ClientRepository() {

}