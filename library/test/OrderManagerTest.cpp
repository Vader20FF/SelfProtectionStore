#include <boost/test/unit_test.hpp>
#include "utils.h"
#include "exceptions/Exceptions.h"

using namespace std;

struct TestSuiteOrderManagerFixture
{
    ClientAddressPtr testClientAddress1;
    ShippingAddressPtr testShippingAddress1;
    ClientPtr testClient;
    ShoppingCartPtr testShoppingCart;
    ShoppingCartPtr testShoppingCartTooMuch;
    TaserPtr taser;
    TaserPtr taserTooMuch;
    PepperSprayPtr pepperSpray;


    TestSuiteOrderManagerFixture()
    {
        testClientAddress1=std::make_shared<ClientAddress>("Klientowa", "18", "92", "23-254", "Lodz", "Polska");
        testShippingAddress1=std::make_shared<ShippingAddress>("Wysylkowa", "23", "34", "46-456", "Warszawa", "Polska");
        testClient=std::make_shared<Client>("Patryk", "Makowski", "patryk.makowski@gmail.com", "546784569", testClientAddress1, testShippingAddress1);
        testShoppingCart=std::make_shared<ShoppingCart>();
        testShoppingCartTooMuch=std::make_shared<ShoppingCart>();
        taser=std::make_shared<Taser>("paralizator", 500, "firma1", "500");
        taserTooMuch=std::make_shared<Taser>("paralizatorTooMuch", 6000, "firma1", "500");
        pepperSpray=std::make_shared<PepperSpray>("gaz pieprzowy", 500, "firma2", "400ml");
        testShoppingCart->repositoryAdd(taser);
        testShoppingCart->repositoryAdd(pepperSpray);
        testShoppingCartTooMuch->repositoryAdd(taserTooMuch);
    }

    ~TestSuiteOrderManagerFixture()
    {
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteManager, TestSuiteOrderManagerFixture)

    BOOST_AUTO_TEST_CASE(RepositoryConstructorTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ProductManagerPtr testProductManager(new ProductManager());
        OrderManagerPtr testOrderManager(new OrderManager());
        Fill(testClientManager,testOrderManager);
        OrderPtr test=testOrderManager->find([](OrderPtr order){return order->getClient()->getFirstName()=="Szymon";});
        BOOST_TEST_CHECK(test->getClient()->getFirstName()=="Szymon");
    }

    BOOST_AUTO_TEST_CASE(OrderRepositoryFindAllTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ProductManagerPtr testProductManager(new ProductManager());
        OrderManagerPtr testOrderManager(new OrderManager());
        Fill(testClientManager,testOrderManager);
        OrderPtr test=testOrderManager->find([](OrderPtr order){return order->getClient()->getFirstName()=="Szymon";});
        BOOST_TEST_CHECK(test->getClient()->getFirstName()=="Szymon");
    }

    BOOST_AUTO_TEST_CASE(OrderRepositoryFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ProductManagerPtr testProductManager(new ProductManager());
        OrderManagerPtr testOrderManager(new OrderManager());
        Fill(testClientManager,testOrderManager);
        OrderPtr test=testOrderManager->find([](OrderPtr order){return order->getClient()->getFirstName()=="Szymon";});
        BOOST_TEST_CHECK(test->getClient()->getFirstName()=="Szymon");
    }


    BOOST_AUTO_TEST_CASE(MakeOrderPositiveTest)
    {
        OrderManagerPtr testOrderManager(new OrderManager());
        BOOST_TEST_CHECK(testOrderManager->makeOrder(testClient,testShoppingCart,"za pobraniem")->getClient()==testClient);
        BOOST_TEST_CHECK(testOrderManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(OrderTotalPriceExceededClientOrderPriceLimit)
    {
        OrderManagerPtr testOrderManager(new OrderManager());
        //BOOST_TEST_CHECK(testOrderManager->makeOrder(testClient, testShoppingCartTooMuch, "za pobraniem")==nullptr);
        BOOST_CHECK_THROW(testOrderManager->makeOrder(testClient, testShoppingCartTooMuch, "za pobraniem"),FunctionException);
        BOOST_TEST_CHECK(testOrderManager->size()==0);
    }


    BOOST_AUTO_TEST_CASE(CancelOrderTest)
    {
        OrderManagerPtr testOrderManager(new OrderManager());
        ShoppingCartPtr shoppingCart2(new ShoppingCart);
        TaserPtr taser(new Taser("paralizator", 100, "firma1", "500"));
        PepperSprayPtr pepperSpray(new PepperSpray("gaz pieprzowy", 50, "firma2", "400ml"));
        shoppingCart2->repositoryAdd(taser);
        shoppingCart2->repositoryAdd(pepperSpray);
        OrderPtr newOrder=testOrderManager->makeOrder(testClient,shoppingCart2,"za pobraniem");
        BOOST_TEST_CHECK(testOrderManager->size()==1);
        testOrderManager->cancelOrder(newOrder);
        BOOST_TEST_CHECK(testOrderManager->size()==0);
    }


    BOOST_AUTO_TEST_CASE(ChangeClientTypeTest)
    {
        OrderManagerPtr testOrderManager(new OrderManager());
        BOOST_TEST_CHECK(testClient->getIsRegularCustomer()==0);
        TaserPtr taser1(new Taser("paralizator1", 100, "firma1", "500"));
        TaserPtr taser2(new Taser("paralizator2", 100, "firma1", "500"));
        TaserPtr taser3(new Taser("paralizator3", 100, "firma1", "500"));
        TaserPtr taser4(new Taser("paralizator4", 100, "firma1", "500"));
        TaserPtr taser5(new Taser("paralizator5", 100, "firma1", "500"));
        TaserPtr taser6(new Taser("paralizator6", 100, "firma1", "500"));
        ShoppingCartPtr shoppingCart2(new ShoppingCart);
        shoppingCart2->repositoryAdd(taser1);
        OrderPtr order1=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        shoppingCart2->repositoryAdd(taser2);
        OrderPtr order2=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        shoppingCart2->repositoryAdd(taser3);
        OrderPtr order3=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        shoppingCart2->repositoryAdd(taser4);
        OrderPtr order4=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        BOOST_TEST_CHECK(testClient->getIsRegularCustomer()==0);
        shoppingCart2->repositoryAdd(taser5);
        OrderPtr order5=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        BOOST_TEST_CHECK(testClient->getIsRegularCustomer()==1);
        shoppingCart2->repositoryAdd(taser6);
        OrderPtr order6=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        BOOST_TEST_CHECK(testClient->getIsRegularCustomer()==1);

        testOrderManager->cancelOrder(order6);
        testOrderManager->cancelOrder(order5);
        testOrderManager->cancelOrder(order4);
        BOOST_TEST_CHECK(testClient->getIsRegularCustomer()==0);

    }


    BOOST_AUTO_TEST_CASE(OrderFinalPrice)
    {
        OrderManagerPtr testOrderManager(new OrderManager());
        TaserPtr taser1(new Taser("paralizator1", 100, "firma1", "500"));
        TaserPtr taser2(new Taser("paralizator2", 100, "firma1", "500"));
        ShoppingCartPtr shoppingCart2(new ShoppingCart);
        shoppingCart2->repositoryAdd(taser1);
        OrderPtr order1=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        BOOST_TEST_CHECK(order1->getTotalCost()==100.0);
        testClient->setIsRegularCustomer(1);
        shoppingCart2->repositoryAdd(taser2);
        OrderPtr order2=testOrderManager->makeOrder(testClient, shoppingCart2, "za pobraniem");
        BOOST_TEST_CHECK(order2->getTotalCost()==160.0);
    }


    BOOST_AUTO_TEST_CASE(GetAllClientOrdersTest)
    {
        OrderManagerPtr testOrderManager(new OrderManager());
        testOrderManager->makeOrder(testClient,testShoppingCart,"za pobraniem");
        testOrderManager->makeOrder(testClient,testShoppingCart,"za pobraniem");
        std::list<OrderPtr> OrdersList=testOrderManager->getAllClientOrders(testClient);
        BOOST_TEST_CHECK(OrdersList.size()==2);
    }

BOOST_AUTO_TEST_SUITE_END()