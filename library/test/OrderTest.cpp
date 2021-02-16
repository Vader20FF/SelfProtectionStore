#include <boost/test/unit_test.hpp>
#include <model/ShoppingCart.h>
#include "model/typedefs.h"
#include "model/Client.h"
#include "model/Order.h"
#include "exceptions/Exceptions.h"

using namespace std;

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteOrderFixture {

    string testname = "a";
    double testprice = 800;
    string testmanufacture = "aaa";
    string testwhatever = "Aaaaa";
    const std::string testFirstName = "Adam";
    const std::string testLastName = "Glab";
    const std::string testEmailAddress = "adam.glab@poczta.pl";
    const std::string testPhoneNumber = "233456938";

    ClientAddressPtr testClientAddress1;
    ShippingAddressPtr testShippingAddress1;
    TaserPtr taser1;
    TaserPtr taser2;
    ClientPtr testclient;
    ShoppingCartPtr testshopingcard;

    TestSuiteOrderFixture()
    {
        taser1 = make_shared<Taser>(testname,testprice,testmanufacture,testwhatever);
        taser2 = make_shared<Taser>(testname,testprice,testmanufacture,testwhatever);
        testClientAddress1=std::make_shared<ClientAddress>("Klientowa", "18", "92", "23-254", "Lodz", "Polska");
        testShippingAddress1=std::make_shared<ShippingAddress>("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska");
        testclient = make_shared<Client>(testFirstName, testLastName, testEmailAddress, testPhoneNumber, testClientAddress1, testShippingAddress1);
        testshopingcard = make_shared<ShoppingCart>();
        testshopingcard->repositoryAdd(taser1);
        testshopingcard->repositoryAdd(taser2);
    }

    ~TestSuiteOrderFixture()
    {
    }


};
BOOST_FIXTURE_TEST_SUITE(TestSuiteOrder,TestSuiteOrderFixture)

    BOOST_AUTO_TEST_CASE(ConstructorOrderTest){
        OrderPtr order(new Order(testclient,testshopingcard,"metoda"));
        pt::ptime testtime = pt::second_clock::local_time();
        gr::date today = testtime.date();
        today = today + gr::days(2);
        BOOST_REQUIRE_EQUAL(order->getShippingMethod(),"metoda");
        BOOST_TEST(testshopingcard->getShoppingCartTotalCost() < testclient->getOrderPriceLimit());
        BOOST_REQUIRE_EQUAL(order->getOrderDate(),testtime);
        BOOST_REQUIRE_EQUAL(order->getEstimatedDeliveryDate(),today);
        string a = "";
        BOOST_TEST(to_string(order->getOrderID())!=a);
        BOOST_REQUIRE_EQUAL(order->getTotalCost(),1600);
    }

    BOOST_AUTO_TEST_CASE(EmptyConstructorOrderTest){
        BOOST_CHECK_THROW(OrderPtr test(new Order(testclient,testshopingcard,"")),ConstructorException);
        BOOST_CHECK_THROW(OrderPtr test(new Order(testclient, nullptr,"aaa")),exception);
        //BOOST_CHECK_EXCEPTION(OrderPtr test1(new Order(nullptr,testshopingcard,"aa")),ConstructorException,[](const ConstructorException &e){
        //    return strcmp(e.what(), "Invalid date, cannot create Order") == 0;
        //});

    }

    BOOST_AUTO_TEST_CASE(FirstConditionNegativeConstructorOrderTest){
        testshopingcard->repositoryAdd(taser1);
        BOOST_CHECK_THROW(OrderPtr order(new Order(testclient,testshopingcard,"metoda")),FunctionException);
    }

    BOOST_AUTO_TEST_CASE(RegularConsumerConstructorTest){
        testclient->setIsRegularCustomer(true);
        OrderPtr order(new Order(testclient,testshopingcard,"metoda"));
        BOOST_REQUIRE_EQUAL(order->getTotalCost(),1280);
    }

    BOOST_AUTO_TEST_CASE(setEstimatedDeliveryDateTest){
        OrderPtr order(new Order(testclient,testshopingcard,"metoda"));
        pt::ptime now = pt::second_clock::local_time();
        gr::date today = now.date();
        gr::date dayAfterTommorrow = today + gr::days(10);
        order->setEstimatedDeliveryDate(dayAfterTommorrow);
        BOOST_REQUIRE_EQUAL(order->getEstimatedDeliveryDate(),dayAfterTommorrow);
        dayAfterTommorrow = today - gr::days(20);
        BOOST_CHECK_THROW(order->setEstimatedDeliveryDate(dayAfterTommorrow), FunctionException);
    }

BOOST_AUTO_TEST_SUITE_END()