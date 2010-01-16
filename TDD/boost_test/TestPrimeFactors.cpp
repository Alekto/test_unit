#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>
//#include <boost/test/included/unit_test_framework.hpp> 

#include "PrimeFactors.hpp"

BOOST_AUTO_TEST_CASE(OneHasNoFactors)
{
    std::list<int> result = PrimeFactors::Generate(1);
    BOOST_REQUIRE_EQUAL(0, result.size());
}

//BOOST_AUTO_TEST_CASE(TwoHasOneFactor)
//{
//    std::list<int> result = PrimeFactors::Generate(2);
//    int expected[] = { 2 };
//    BOOST_REQUIRE_EQUAL_COLLECTIONS(&expected[0], &expected[1], result.begin(), result.end());
//}
//
//BOOST_AUTO_TEST_CASE(ThreeHasOneFactor)
//{
//    std::list<int> result = PrimeFactors::Generate(3);
//    int expected[] = { 3 };
//    BOOST_REQUIRE_EQUAL_COLLECTIONS(&expected[0], &expected[1], result.begin(), result.end());
//}


static void AssertValueHasPrimeFactors(int value, int const *expected, int numExpected)
{
    std::list<int> result = PrimeFactors::Generate(value);
    BOOST_REQUIRE_EQUAL_COLLECTIONS(&expected[0], &expected[numExpected], result.begin(), result.end());
}

//BOOST_AUTO_TEST_SUITE( PrimeFactorsSuite )

BOOST_AUTO_TEST_CASE(TwoHasOneFactor)
{
    int const expected[] = { 2 };
    AssertValueHasPrimeFactors(2, expected, 1);
}

BOOST_AUTO_TEST_CASE(ThreeHasOneFactor)
{
    int const expected[] = { 3 };
    AssertValueHasPrimeFactors(3, expected, 1);
}

BOOST_AUTO_TEST_CASE(FourHasTwoFactors)
{
    int const expected[] = { 2, 2 };
    AssertValueHasPrimeFactors(4, expected, 2);
}

BOOST_AUTO_TEST_CASE(SixHasTwoFactors)
{
    int const expected[] = { 2, 3 };
    AssertValueHasPrimeFactors(6, expected, 2);
}

BOOST_AUTO_TEST_CASE(EightHasThreeFactors)
{
    int const expected[] = { 2, 2, 2 };
    AssertValueHasPrimeFactors(8, expected, 3);
}

BOOST_AUTO_TEST_CASE(NineHasTwoFactors)
{
    int const expected[] = { 3, 3 };
    AssertValueHasPrimeFactors(9, expected, 2);
}

//BOOST_AUTO_TEST_SUITE_END()
