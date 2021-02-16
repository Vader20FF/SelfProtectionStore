#include <boost/test/unit_test.hpp>
#include "model/Product.h"
#include "model/Nightstick.h"
#include "model/Taser.h"
#include "model/PepperSpray.h"
#include "exceptions/Exceptions.h"

using namespace std;
/*
struct TestSuiteProductFixure
{
    const string testProductName = "pc";
    const string testManufacturer = "intel";
    const double testPrice1 = 10;
    const double testPrice2 = -30;
    const double testPrice3 = 99.99;
    boost::uuids::uuid testproductID;
    const string testmaterial = "szkĹo";
    const string testvoltage =  "200";
    const string testvolume = "100";

    NightstickPtr   testNightStick1;
    NightstickPtr   testNightStick2;
    TaserPtr        testTaser;
    PepperSprayPtr  testPepperSpray;


    TestSuiteProductFixure()
    {
        testNightStick1 = make_shared<Nightstick>(testProductName, testPrice1, testManufacturer, testmaterial);
        testNightStick2 = make_shared<Nightstick>(testProductName, testPrice2, testManufacturer, testmaterial);
        testTaser = make_shared<Taser>(testProductName, testPrice1, testManufacturer, testvoltage);
        testPepperSpray = make_shared<PepperSpray>(testProductName, testPrice1, testManufacturer, testvolume);
    }

    ~TestSuiteProductFixure()
    {
    }
};
*/
BOOST_AUTO_TEST_SUITE(ProductTest)

    BOOST_AUTO_TEST_CASE(NIGHTSTICKConstructorTest){
        /*BOOST_TEST(testNightStick1->getProductName() == testProductName);
        BOOST_TEST(testNightStick1->getPrice() == testPrice1);
        BOOST_TEST(testNightStick1->getManufacturer() == testManufacturer);
        BOOST_TEST(testNightStick1->getMaterial() == testmaterial);
        BOOST_TEST(testNightStick2->getPrice() == -testPrice2);*/
        BOOST_CHECK_THROW(NightstickPtr test(new Nightstick("A",5,"v","")),ConstructorException);
    }

    BOOST_AUTO_TEST_CASE(TaserConstructorTest)
    {
        /*BOOST_TEST(testTaser->getProductName() == testProductName);
        BOOST_TEST(testTaser->getPrice() == testPrice1);
        BOOST_TEST(testTaser->getManufacturer() == testManufacturer);
        BOOST_TEST(testTaser->getVoltage() == testvoltage);*/
        BOOST_CHECK_THROW(TaserPtr test(new Taser("A",-300,"v","b")),ConstructorException);

    }

    BOOST_AUTO_TEST_CASE(PepperSprayConstructorTest)
    {
        /*BOOST_TEST(testPepperSpray->getProductName() == testProductName);
        BOOST_TEST(testPepperSpray->getPrice() == testPrice1);
        BOOST_TEST(testPepperSpray->getManufacturer() == testManufacturer);
        BOOST_TEST(testPepperSpray->getVolume() == testvolume);*/
        BOOST_CHECK_THROW(PepperSprayPtr test(new PepperSpray("",22,"v","b")),ConstructorException);

    }

    BOOST_AUTO_TEST_CASE(PriceSetterTest)
    {
        /*
        testPepperSpray->setPrice(testPrice3);
        BOOST_TEST(testPepperSpray->getPrice() == testPrice3);

        testPepperSpray->setPrice(testPrice2);
        BOOST_TEST(testPepperSpray->getPrice() == testPrice3);

        testPepperSpray->setPrice(0);
        BOOST_TEST(testPrice3 == testPepperSpray->getPrice());*/

        double *test = new double[3];
        test[0] = 0; test [1] = -200; test[2] = 300;
        PepperSprayPtr test1(new PepperSpray("a",22,"v","b"));
        BOOST_CHECK_THROW(test1->setPrice(test[0]),FunctionException);
        BOOST_CHECK_THROW(test1->setPrice(test[1]),FunctionException);
        test1->setPrice(test[2]);
        BOOST_CHECK_EQUAL(test1->getPrice(),300);
        delete[] test;
    }

BOOST_AUTO_TEST_SUITE_END()