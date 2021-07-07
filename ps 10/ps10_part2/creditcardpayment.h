#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H
#include "payment.h"

class CreditCardPayment : public Payment
{
private:
	string nameOnCard;
	string expirationDate;
	string cardNumber;

public:
	CreditCardPayment();
	CreditCardPayment(float ccpAmountOfPayment, string ccpNameOnCard, 
		string ccpExpirationDate, string ccpCardNumber);
	void paymentDetails();
};
#endif