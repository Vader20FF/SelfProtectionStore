#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "exceptions/Exceptions.h"

using namespace std;

struct TestSuiteClientFixture
{
    const std::string testFirstName = "Adam";
    const std::string testLastName = "Glab";
    const std::string testEmailAddress = "adam.glab@poczta.pl";
    const std::string testPhoneNumber = "233456938";
    ClientAddressPtr testClientAddress1;
    ClientAddressPtr testClientAddress2;
    ShippingAddressPtr testShippingAddress1;
    ShippingAddressPtr testShippingAddress2;
    const std::string testNewName = "Kamil";

    TestSuiteClientFixture()
    {
        testClientAddress1=std::make_shared<ClientAddress>("Klientowa", "18", "92", "23-254", "Lodz", "Polska");
        testClientAddress2=std::make_shared<ClientAddress>("Klientowa2", "56", "432", "42-523", "Poznan", "Azerbejdzan");
        testShippingAddress1=std::make_shared<ShippingAddress>("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska");
        testShippingAddress2=std::make_shared<ShippingAddress>("Wysylkowa2", "43", "363", "34-395", "Krakow", "Niemcy");
    }

    ~TestSuiteClientFixture()
    {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)


    BOOST_AUTO_TEST_CASE(ClientConstructorTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        BOOST_TEST_CHECK(client->getFirstName()==testFirstName);
        BOOST_TEST_CHECK(client->getLastName()==testLastName);
        BOOST_TEST_CHECK(client->getEmailAddress()==testEmailAddress);
        BOOST_TEST_CHECK(client->getPhoneNumber()==testPhoneNumber);
        BOOST_TEST_CHECK(client->getClientAddress()==testClientAddress1);
        BOOST_TEST_CHECK(client->getShippingAddress()==testShippingAddress1);

    }

    BOOST_AUTO_TEST_CASE(EmptyConstructorTest){

        BOOST_CHECK_THROW(ClientPtr client1(new Client("aaa", "", testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1)),ConstructorException);
        BOOST_CHECK_THROW(ClientPtr client2(new Client("aa", testLastName, testEmailAddress, testPhoneNumber, nullptr, testShippingAddress1)),ConstructorException);
    }

    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setFirstName("Adam");
        BOOST_TEST_CHECK(client->getFirstName() == "Adam");
    }

    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setFirstName("");
        //BOOST_TEST_CHECK(client->getFirstName() != "");
        BOOST_CHECK_THROW(client->setFirstName(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setLastName("Jeziorski");
        BOOST_TEST_CHECK(client->getLastName() =="Jeziorski");

    }

    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setLastName("");
        // BOOST_TEST_CHECK(client->getLastName() != "");
        BOOST_CHECK_THROW(client->setLastName(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(SetEmailAddressPositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setEmailAddress("cos@cos.pl");
        BOOST_TEST_CHECK(client->getEmailAddress()=="cos@cos.pl");

    }

    BOOST_AUTO_TEST_CASE(SetEmailAddressNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setEmailAddress("");
        //BOOST_TEST_CHECK(client->getEmailAddress() != "");
        BOOST_CHECK_THROW(client->setEmailAddress(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(SetPhoneNumberPositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setPhoneNumber("345123445");
        BOOST_TEST_CHECK(client->getPhoneNumber()=="345123445");
    }

    BOOST_AUTO_TEST_CASE(SetPhoneNumberNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setPhoneNumber("");
        //BOOST_TEST_CHECK(client->getPhoneNumber() != "");
        BOOST_CHECK_THROW(client->setPhoneNumber(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(SetClientAddressPositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setClientAddress(testClientAddress1);
        BOOST_TEST_CHECK(client->getClientAddress()==testClientAddress1);
    }

    BOOST_AUTO_TEST_CASE(SetClientAddressNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setClientAddress(nullptr);
        //BOOST_TEST_CHECK(client->getClientAddress() !=nullptr);
        BOOST_CHECK_THROW(client->setClientAddress(nullptr),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(SetShippingAddressPositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setShippingAddress(testShippingAddress1);
        BOOST_TEST_CHECK(client->getShippingAddress()==testShippingAddress1);
    }

    BOOST_AUTO_TEST_CASE(SetShippingAddressNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setShippingAddress(nullptr);
        // BOOST_TEST_CHECK(client->getShippingAddress()!=nullptr);
        BOOST_CHECK_THROW(client->setShippingAddress(nullptr),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(SetIsRegularCustomerPositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setIsRegularCustomer(1);
        BOOST_TEST_CHECK(client->getIsRegularCustomer()==1);
    }

    BOOST_AUTO_TEST_CASE(SetIsRegularCustomerNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setIsRegularCustomer(1);
        BOOST_TEST_CHECK(client->getIsRegularCustomer()!=0);
    }

    BOOST_AUTO_TEST_CASE(SetOrderPriceLimitPositiveTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        client->setOrderPriceLimit(600);
        BOOST_TEST_CHECK(client->getOrderPriceLimit()==600);
    }

    BOOST_AUTO_TEST_CASE(SetOrderPriceLimitNegativeTest)
    {
        ClientPtr client(new Client(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1));
        //client->setOrderPriceLimit(2200);
        //BOOST_TEST_CHECK(client->getOrderPriceLimit()!=2200);
        BOOST_CHECK_THROW(client->setOrderPriceLimit(2200),FunctionException);
    }

BOOST_AUTO_TEST_SUITE_END()