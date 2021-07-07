#include "cashpayment.h"

CashPayment::CashPayment() : Payment()
{
	// deliberately empty
}

CashPayment::CashPayment(float cpAmountOfPayment) : Payment(cpAmountOfPayment)
{
	// deliberately empty
}

void CashPayment::paymentDetails()
{
	cout << "Amount of cash payment: $" << getAmountOfPayment() << endl;
}