// http://legalizeadulthood.wordpress.com/2009/07/05/c-unit-tests-with-boost-test-part-4/



#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

#include "PrimeFactorsMediator.hpp"

class FakePrimeFactorsDialog : public IPrimeFactorsDialog
{
public:
    FakePrimeFactorsDialog()
        : EnableOKButtonCalled(false),
        EnableOKButtonLastEnabled(false)
    {
    }
    virtual ~FakePrimeFactorsDialog()
    {
    }
    bool EnableOKButtonCalled;
    bool EnableOKButtonLastEnabled;

    virtual void EnableOKButton(bool enabled)
    {
        EnableOKButtonCalled = true;
        EnableOKButtonLastEnabled = enabled;
    }

	//virtual std::string ValueText()
	//{
	//	return "123";
	//}

	virtual std::string ValueText()
	{
		ValueTextCalled = true;
		return ValueTextFakeResult;
	}


	void AssertOKButtonEnabled(bool enabled)
	{
		BOOST_REQUIRE(EnableOKButtonCalled);
		BOOST_REQUIRE_EQUAL(enabled, EnableOKButtonLastEnabled);
	}

public:
	bool ValueTextCalled;
	std::string ValueTextFakeResult;
};






//BOOST_AUTO_TEST_CASE(OKButtonInitiallyDisabled)
//{
//    FakePrimeFactorsDialog dialog;
//    PrimeFactorsMediator mediator(&dialog);
//    BOOST_REQUIRE(dialog.EnableOKButtonCalled);
//    BOOST_REQUIRE(!dialog.EnableOKButtonLastEnabled);
//}
//
////BOOST_AUTO_TEST_CASE(OKButtonEnabledWithValidInteger)
////{
////    FakePrimeFactorsDialog dialog;
////    PrimeFactorsMediator mediator(&dialog);
////    mediator.ValueTextChanged();
////    BOOST_REQUIRE(dialog.EnableOKButtonCalled);
////    BOOST_REQUIRE(dialog.EnableOKButtonLastEnabled);
////}
//
//BOOST_AUTO_TEST_CASE(OKButtonEnabledWithValidInteger)
//{
//    FakePrimeFactorsDialog dialog;
//    dialog.ValueTextFakeResult = "123";
//    PrimeFactorsMediator mediator(&dialog);
//    mediator.ValueTextChanged();
//    BOOST_REQUIRE(dialog.ValueTextCalled);
//    BOOST_REQUIRE(dialog.EnableOKButtonCalled);
//    BOOST_REQUIRE(dialog.EnableOKButtonLastEnabled);
//}
//
//
//BOOST_AUTO_TEST_CASE(OKButtonDisabledWithEmptyText)
//{
//    FakePrimeFactorsDialog dialog;
//    PrimeFactorsMediator mediator(&dialog);
//    mediator.ValueTextChanged();
//    BOOST_REQUIRE(dialog.EnableOKButtonCalled);
//    BOOST_REQUIRE(!dialog.EnableOKButtonLastEnabled);
//}
//
////BOOST_AUTO_TEST_CASE(OKDisabledWithInvalidIntegerText)
////{
////    FakePrimeFactorsDialog dialog;
////    dialog.ValueTextFakeResult = "Invalid";
////    PrimeFactorsMediator mediator(&dialog);
////    mediator.ValueTextChanged();
////    BOOST_REQUIRE(dialog.ValueTextCalled);
////    BOOST_REQUIRE(dialog.EnableOKButtonCalled);
////    BOOST_REQUIRE(!dialog.EnableOKButtonLastEnabled);
////}
//
//
//
//BOOST_AUTO_TEST_CASE(OKDisabledWithInvalidIntegerText)
//{
//    FakePrimeFactorsDialog dialog;
//    dialog.ValueTextFakeResult = "Invalid";
//    PrimeFactorsMediator mediator(&dialog);
//    mediator.ValueTextChanged();
//    BOOST_REQUIRE(dialog.ValueTextCalled);
//    dialog.AssertOKButtonEnabled(false);
//}







struct TestPrimeFactorsMediator
{
    TestPrimeFactorsMediator()
        : m_dialog(), m_mediator(&m_dialog)
    {
    }

    FakePrimeFactorsDialog m_dialog;
    PrimeFactorsMediator m_mediator;
};

//BOOST_AUTO_TEST_SUITE( GUI_PrimeFactorsSuite )

BOOST_FIXTURE_TEST_CASE(OKButtonInitiallyDisabled, TestPrimeFactorsMediator)
{
    m_dialog.AssertOKButtonEnabled(false);
}

BOOST_FIXTURE_TEST_CASE(OKButtonEnabledWithValidInteger, TestPrimeFactorsMediator)
{
    m_dialog.ValueTextFakeResult = "123";
    m_mediator.ValueTextChanged();
    BOOST_REQUIRE(m_dialog.ValueTextCalled);
    m_dialog.AssertOKButtonEnabled(true);
}

BOOST_FIXTURE_TEST_CASE(OKButtonDisabledWithEmptyText, TestPrimeFactorsMediator)
{
    m_mediator.ValueTextChanged();
    BOOST_REQUIRE(m_dialog.ValueTextCalled);
    m_dialog.AssertOKButtonEnabled(false);
}

BOOST_FIXTURE_TEST_CASE(OKDisabledWithInvalidIntegerText, TestPrimeFactorsMediator)
{
    m_dialog.ValueTextFakeResult = "Invalid";
    m_mediator.ValueTextChanged();
    BOOST_REQUIRE(m_dialog.ValueTextCalled);
    m_dialog.AssertOKButtonEnabled(false);
}

BOOST_FIXTURE_TEST_CASE(OKDisabledWithInvalidIntegerText2, TestPrimeFactorsMediator)
{
    m_dialog.ValueTextFakeResult = "Invalid";
    m_mediator.ValueTextChanged();
    BOOST_REQUIRE(m_dialog.ValueTextCalled);
    m_dialog.AssertOKButtonEnabled(true);
}
//BOOST_AUTO_TEST_SUITE_END()
