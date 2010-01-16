#include <sstream> 

#include "PrimeFactorsMediator.hpp"


//PrimeFactorsMediator::PrimeFactorsMediator(IPrimeFactorsDialog *dialog)
//{
//	dialog->EnableOKButton(false);
//}

PrimeFactorsMediator::PrimeFactorsMediator(IPrimeFactorsDialog *dialog)
    : m_dialog(dialog)
{
    m_dialog->EnableOKButton(false);
}


PrimeFactorsMediator::~PrimeFactorsMediator()
{
}

//void PrimeFactorsMediator::ValueTextChanged()
//{
//}

//void PrimeFactorsMediator::ValueTextChanged()
//{
//	m_dialog->EnableOKButton(true);
//}

//void PrimeFactorsMediator::ValueTextChanged()
//{
//    m_dialog->EnableOKButton(m_dialog->ValueText().length() > 0);
//}

void PrimeFactorsMediator::ValueTextChanged()
{
    std::istringstream stream(m_dialog->ValueText());
    int value;
    stream >> value;
    m_dialog->EnableOKButton(!stream.fail() && (m_dialog->ValueText().length() > 0));
}
