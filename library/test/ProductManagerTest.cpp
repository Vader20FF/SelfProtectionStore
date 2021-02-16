//
// Created by student on 6/11/20.
//

#include <boost/test/unit_test.hpp>
#include "utils.h"

using namespace std;

struct TestSuiteProductManagerFixture
{
    const std::string testFirstName = "Patryk";
    const std::string testLastName = "Makowski";
    const std::string testEmailAddress = "email1@email.com";
    const std::string testPhoneNumber = "574637857";
    const std::string testNewName = "Szymon";
    const std::string testNewProductName = "nowaNazwa";
    ClientAddressPtr testClientAddress1;
    ClientAddressPtr testClientAddress2;
    ShippingAddressPtr testShippingAddress1;
    ShippingAddressPtr testShippingAddress2;
    ClientPtr testClient;
    ClientAddressPtr testClientAddress;
    ShippingAddressPtr testShippingAddress;


    TestSuiteProductManagerFixture()
    {
        testClientAddress1=std::make_shared<ClientAddress>("Klientowa", "18", "92", "23-254", "Lodz", "Polska");
        testClientAddress2=std::make_shared<ClientAddress>("Klientowa2", "56", "432", "42-523", "Poznan", "Azerbejdzan");
        testShippingAddress1=std::make_shared<ShippingAddress>("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska");
        testShippingAddress2=std::make_shared<ShippingAddress>("Wysylkowa2", "43", "363", "34-395", "Krakow", "Niemcy");
    }

    ~TestSuiteProductManagerFixture()
    {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteManager, TestSuiteProductManagerFixture)

//    BOOST_AUTO_TEST_CASE(ProductRepositoryFindAllTest)
//    {
//        ClientManagerPtr testClientManager(new ClientManager());
//        ProductManagerPtr testProductManager(new ProductManager());
//        OrderManagerPtr testOrderManager(new OrderManager());
//        Fill(testClientManager,testOrderManager);
//        ProductNamePredicate predicate(testNewProductName);
//        std::list<ProductPtr> Searched = testProductManager->findAll<ProductNamePredicate>(predicate);
//        BOOST_TEST_CHECK(Searched.front()->getProductName()=="nowaNazwa");
//        BOOST_TEST_CHECK(Searched.back()->getProductName()=="nowaNazwa");
//    }

    BOOST_AUTO_TEST_CASE(ProductRepositoryFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ProductManagerPtr testProductManager(new ProductManager());
        OrderManagerPtr testOrderManager(new OrderManager());
        Fill(testClientManager,testOrderManager);
        testProductManager->registerNightstick("palka1", 80, "firma2", "metal");
        ProductNamePredicate check("palka1");
        BOOST_TEST_CHECK(testProductManager->find(check)->getProductName()=="palka1");
    }


    BOOST_AUTO_TEST_CASE(RegisterNightstickTest)
    {
        ProductManagerPtr testProductManager(new ProductManager());
        BOOST_TEST_CHECK(testProductManager->registerNightstick("palka1", 80, "firma2", "metal")->getProductName()=="palka1");
        BOOST_TEST_CHECK(testProductManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterTaserTest)
    {
        ProductManagerPtr testProductManager(new ProductManager());
        BOOST_TEST_CHECK(testProductManager->registerTaser("paralizator", 100, "firma1", "500")->getProductName()=="paralizator");
        BOOST_TEST_CHECK(testProductManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterPepperSprayTest)
    {
        ProductManagerPtr testProductManager(new ProductManager());
        BOOST_TEST_CHECK(testProductManager->registerPepperSpray("gaz pieprzowy", 40, "firma2", "400ml")->getProductName()=="gaz pieprzowy");
        BOOST_TEST_CHECK(testProductManager->size()==1);
    }

BOOST_AUTO_TEST_SUITE_END()