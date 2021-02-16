#include <boost/test/unit_test.hpp>
#include "model/ClientAddress.h"
#include "model/ShippingAddress.h"
#include "exceptions/Exceptions.h"

using namespace std;

struct TestSuiteAddressFixture
{

    const string testClientStreetName = "Klientowa";
    const string testClientStreetNumber = "18";
    const string testClientApartmentNumber = "92";
    const string testClientPostalCode = "23-254";
    const string testClientCityName = "Lodz";
    const string testClientCountry = "Polska";

    const string testShippingStreetName = "Wysylkowa";
    const string testShippingStreetNumber = "23";
    const string testShippingApartmentNumber = "34";
    const string testShippingPostalCode = "46-456";
    const string testShippingCityName = "Warszawa";
    const string testShippingCountry = "Polska";

    ClientAddressPtr testClientAddress;
    ShippingAddressPtr testShippingAddress;

    TestSuiteAddressFixture()
    {
        testClientAddress=make_shared<ClientAddress>(testClientStreetName, testClientStreetNumber, testClientApartmentNumber, testClientPostalCode, testClientCityName, testClientCountry);
        testShippingAddress=make_shared<ShippingAddress>(testShippingStreetName, testShippingStreetNumber, testShippingApartmentNumber, testShippingPostalCode, testShippingCityName, testShippingCountry);
    }

    ~TestSuiteAddressFixture()
    {
    }

};

BOOST_FIXTURE_TEST_SUITE(AddressTest,TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressContructorTest) {
        BOOST_TEST_CHECK(testClientAddress->getStreetName()==testClientStreetName);
        BOOST_TEST_CHECK(testClientAddress->getStreetNumber()==testClientStreetNumber);
        BOOST_TEST_CHECK(testClientAddress->getApartmentNumber()==testClientApartmentNumber);
        BOOST_TEST_CHECK(testClientAddress->getPostalCode()==testClientPostalCode);
        BOOST_TEST_CHECK(testClientAddress->getCityName()==testClientCityName);
        BOOST_TEST_CHECK(testClientAddress->getCountry()==testClientCountry);
    }

    BOOST_AUTO_TEST_CASE(ShippingAddressConstructorTest){
        BOOST_TEST_CHECK(testShippingAddress->getStreetName()==testShippingStreetName);
        BOOST_TEST_CHECK(testShippingAddress->getStreetNumber()==testShippingStreetNumber);
        BOOST_TEST_CHECK(testShippingAddress->getApartmentNumber()==testShippingApartmentNumber);
        BOOST_TEST_CHECK(testShippingAddress->getPostalCode()==testShippingPostalCode);
        BOOST_TEST_CHECK(testShippingAddress->getCityName()==testShippingCityName);
        BOOST_TEST_CHECK(testShippingAddress->getCountry()==testShippingCountry);
    }

    BOOST_AUTO_TEST_CASE(EmptyAddressConstructorTest){
        BOOST_CHECK_THROW(ClientAddressPtr test (new ClientAddress("","","","","","")),ConstructorException);
        BOOST_CHECK_THROW(ShippingAddressPtr test (new ShippingAddress("","","","","","")),ConstructorException);
    }

    BOOST_AUTO_TEST_CASE(ClientSetStreetNamePositiveTest)
    {
        testClientAddress->setStreetName("Nowa");
        BOOST_TEST_CHECK(testClientAddress->getStreetName()=="Nowa");
    }

    BOOST_AUTO_TEST_CASE(ClientSetStreetNameNegativeTest)
    {
        // testClientAddress->setStreetName("");
        // BOOST_TEST_CHECK(testClientAddress->getStreetName() != "");
        BOOST_CHECK_THROW(testClientAddress->setStreetName(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(ClientSetStreetNumberPositiveTest)
    {
        testClientAddress->setStreetNumber("69");
        BOOST_TEST_CHECK(testClientAddress->getStreetNumber()=="69");
    }

    BOOST_AUTO_TEST_CASE(ClientSetStreetNumberNegativeTest)
    {
        //testClientAddress->setStreetNumber("");
        //BOOST_TEST_CHECK(testClientAddress->getStreetNumber() != "");
        BOOST_CHECK_THROW(testClientAddress->setStreetNumber(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(ClientSetApartmentNumberPositiveTest)
    {
        testClientAddress->setApartmentNumber("96");
        BOOST_TEST_CHECK(testClientAddress->getApartmentNumber()=="96");
    }

    BOOST_AUTO_TEST_CASE(ClientSetApartmentNumberNegativeTest)
    {
        //testClientAddress->setApartmentNumber("");
        //BOOST_TEST_CHECK(testClientAddress->getApartmentNumber() != "");
        BOOST_CHECK_THROW(testClientAddress->setApartmentNumber(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(ClientSetPostalCodePositiveTest)
    {
        testClientAddress->setPostalCode("12-345");
        BOOST_TEST_CHECK(testClientAddress->getPostalCode()=="12-345");
    }

    BOOST_AUTO_TEST_CASE(ClientSetPostalCodeNegativeTest)
    {
        //testClientAddress->setPostalCode("");
        //BOOST_TEST_CHECK(testClientAddress->getPostalCode() !="" );
        BOOST_CHECK_THROW(testClientAddress->setPostalCode(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(ClientSetCityNamePositiveTest)
    {
        testClientAddress->setCityName("Katowice");
        BOOST_TEST_CHECK(testClientAddress->getCityName()=="Katowice");
    }

    BOOST_AUTO_TEST_CASE(ClientSetCityNameNegativeTest)
    {
        //testClientAddress->setCityName("");
        //BOOST_TEST_CHECK(testClientAddress->getCityName() != "");
        BOOST_CHECK_THROW(testClientAddress->setCityName(""),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(ClientSetCountryPositiveTest)
    {
        testClientAddress->setCountry("Rosja");
        BOOST_TEST_CHECK(testClientAddress->getCountry()=="Rosja");
    }

    BOOST_AUTO_TEST_CASE(ClientSetCountryNegativeTest)
    {
        //testClientAddress->setCountry("");
        //BOOST_TEST_CHECK(testClientAddress->getCountry().empty() == 0  );
        BOOST_CHECK_THROW(testClientAddress->setCountry(""),FunctionException);
    }

BOOST_AUTO_TEST_SUITE_END()