//
// Created by student on 6/11/20.
//

#include <boost/test/unit_test.hpp>
#include "utils.h"

using namespace std;

struct TestSuiteClientManagerFixture
{
    const std::string testFirstName = "Patryk";
    const std::string testLastName = "Makowski";
    const std::string testEmailAddress = "email1@email.com";
    const std::string testPhoneNumber = "574637857";
    const std::string testNewName = "Szymon";
    ClientAddressPtr testClientAddress1;
    ClientAddressPtr testClientAddress2;
    ShippingAddressPtr testShippingAddress1;
    ShippingAddressPtr testShippingAddress2;
    ClientPtr testClient;
    ClientAddressPtr testClientAddress;
    ShippingAddressPtr testShippingAddress;


    TestSuiteClientManagerFixture()
    {
        testClientAddress1=std::make_shared<ClientAddress>("Klientowa", "18", "92", "23-254", "Lodz", "Polska");
        testClientAddress2=std::make_shared<ClientAddress>("Klientowa2", "56", "432", "42-523", "Poznan", "Azerbejdzan");
        testShippingAddress1=std::make_shared<ShippingAddress>("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska");
        testShippingAddress2=std::make_shared<ShippingAddress>("Wysylkowa2", "43", "363", "34-395", "Krakow", "Niemcy");
    }

    ~TestSuiteClientManagerFixture()
    {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindAllTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ProductManagerPtr testProductManager(new ProductManager());
        OrderManagerPtr testOrderManager(new OrderManager());
        Fill(testClientManager,testOrderManager);
        FirstNamePredicate predicate(testNewName);
        std::list<ClientPtr> Searched = testClientManager->findAll<FirstNamePredicate>(predicate);
        BOOST_TEST_CHECK(Searched.front()->getLastName()=="Blazynski");
        BOOST_TEST_CHECK(Searched.back()->getLastName()=="Blazynski");
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ProductManagerPtr testProductManager(new ProductManager());
        OrderManagerPtr testOrderManager(new OrderManager());
        Fill(testClientManager,testOrderManager);
        FirstNamePredicate predicate(testNewName);
        BOOST_TEST_CHECK(testClientManager->find(predicate)->getFirstName()==testNewName);
    }


    BOOST_AUTO_TEST_CASE(RegisterNewClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testEmailAddress,testPhoneNumber,testClientAddress1,testShippingAddress1)->getFirstName()==testFirstName);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerListSizeTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->registerClient(testFirstName,testLastName,testEmailAddress,testPhoneNumber,testClientAddress1,testShippingAddress1);
        BOOST_TEST_CHECK(testClientManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterExistingClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->registerClient(testFirstName,testLastName,testEmailAddress,testPhoneNumber,testClientAddress1,testShippingAddress1);
        FirstNamePredicate check(testFirstName);
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testEmailAddress,testPhoneNumber,testClientAddress1,testShippingAddress1)==(testClientManager->find(check)));
        BOOST_TEST_CHECK(testClientManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(RegisterNullClientAddressTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName, testLastName, testEmailAddress, testPhoneNumber, nullptr, testShippingAddress1)==nullptr);
    }

    BOOST_AUTO_TEST_CASE(RegisterNullShippingAddressTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, nullptr)==nullptr);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ClientPtr newClient=testClientManager->registerClient(testFirstName,testLastName,testEmailAddress,testPhoneNumber,testClientAddress1,testShippingAddress1);
        testClientManager->unregisterClient(newClient);
        BOOST_TEST_CHECK(testClientManager->size()==0);
    }

BOOST_AUTO_TEST_SUITE_END()