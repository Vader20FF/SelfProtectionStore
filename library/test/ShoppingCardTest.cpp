#include <boost/test/unit_test.hpp>
#include <model/typedefs.h>
#include "model/Taser.h"
#include "model/ShoppingCart.h"


using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteSchopingCart)

    BOOST_AUTO_TEST_CASE(GetShoppingCartTotalCostTest){
    TaserPtr test1(new Taser("aa",20,"bbb","ccc"));
    TaserPtr test2(new Taser("aa",30,"bbb","ccc"));
    TaserPtr test3(new Taser("aa",40,"bbb","ccc"));
    ShoppingCartPtr testCard(new ShoppingCart());
    testCard->repositoryAdd(test1);
    testCard->repositoryAdd(test2);
    testCard->repositoryAdd(test3);
    BOOST_REQUIRE_EQUAL(testCard->repositorySize(),3);
    BOOST_REQUIRE_EQUAL(testCard->getShoppingCartTotalCost(),90);
    }

BOOST_AUTO_TEST_SUITE_END()


