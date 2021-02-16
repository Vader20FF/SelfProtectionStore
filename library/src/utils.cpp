//
// Created by student on 6/11/20.
//

#include "utils.h"

using namespace std;

void Fill(ClientManagerPtr clientManager, OrderManagerPtr orderManager)
{
    ClientAddressPtr clientAddress1(new ClientAddress("Klientowa", "18", "92", "23-254", "Lodz", "Polska"));
    ClientAddressPtr clientAddress2(new ClientAddress("Klientowa2", "56", "432", "42-523", "Poznan", "Azerbejdzan"));
    ShippingAddressPtr shippingAddress1(new ShippingAddress("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska"));
    ShippingAddressPtr shippingAddress2(new ShippingAddress("Wysylkowa2", "43", "363", "34-395", "Krakow", "Niemcy"));

    clientManager->registerClient("Patryk", "Makowski", "email1@email.com", "574637857", clientAddress1, shippingAddress1);
    clientManager->registerClient("Szymon", "Blazynski", "email2@email.com", "123456789", clientAddress2, shippingAddress2);

    TaserPtr taser(new Taser("paralizator", 100, "firma1", "500"));
    PepperSprayPtr pepperSpray(new PepperSpray("gaz pieprzowy", 40, "firma2", "400ml"));
    NightstickPtr nightstick1(new Nightstick("palka1", 80, "firma2", "metal"));
    NightstickPtr nightstick2(new Nightstick("palka2", 65, "firma2", "plastik"));

    ShoppingCartPtr shoppingCart1(new ShoppingCart);
    shoppingCart1->repositoryAdd(taser);
    shoppingCart1->repositoryAdd(pepperSpray);
    ShoppingCartPtr shoppingCart2(new ShoppingCart);
    shoppingCart2->repositoryAdd(taser);
    shoppingCart2->repositoryAdd(pepperSpray);

    orderManager->makeOrder(clientManager->getClient("574637857"), shoppingCart1, "za pobraniem");
    orderManager->makeOrder(clientManager->getClient("123456789"), shoppingCart2, "platnosc online");

}