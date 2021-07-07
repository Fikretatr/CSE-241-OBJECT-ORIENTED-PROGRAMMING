#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H
#include "payment.h"

class CashPayment : public Payment
{
public:
	CashPayment();
	CashPayment(float cpAmountOfPayment);
	void paymentDetails();
};
#endif