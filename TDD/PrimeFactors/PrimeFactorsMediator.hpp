#include <string>

#if !defined(PRIME_FACTORS_MEDIATOR_H)
#define PRIME_FACTORS_MEDIATOR_H

class IPrimeFactorsDialog
{
public:
    virtual ~IPrimeFactorsDialog() { }
    virtual void EnableOKButton(bool enabled) = 0;
	virtual std::string ValueText() = 0;
};

class PrimeFactorsMediator
{
public:
    PrimeFactorsMediator(IPrimeFactorsDialog *dialog);
    ~PrimeFactorsMediator();

	void ValueTextChanged();

private:
    IPrimeFactorsDialog *m_dialog;

};

#endif
