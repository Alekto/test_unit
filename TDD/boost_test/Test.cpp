// http://legalizeadulthood.wordpress.com/2009/07/04/c-unit-tests-with-boost-test-part-1/
// http://legalizeadulthood.wordpress.com/2009/07/05/c-unit-tests-with-boost-test-part-2/
// http://legalizeadulthood.wordpress.com/2009/07/05/c-unit-tests-with-boost-test-part-3/
// http://legalizeadulthood.wordpress.com/2009/07/05/c-unit-tests-with-boost-test-part-4/
// http://legalizeadulthood.wordpress.com/2009/07/05/c-unit-tests-with-boost-test-part-5/
// http://blogs.msdn.com/allen/archive/2009/10/26/using-boost.aspx

//** Troubleshooting **
//“ entry point must be defined” reported from VS. check the subsystem linker option and set it to CONSOLE explicitly!


//TODO:
//boost_test.exe --log_format=XML
//boost_test.exe --log_format=XML
//boost_test.exe --log_format=XML --log_level=test_suite



//#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
