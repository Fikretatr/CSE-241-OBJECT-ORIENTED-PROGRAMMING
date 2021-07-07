#include "creditcardpayment.h"

CreditCardPayment::CreditCardPayment() 
	: Payment(), nameOnCard(""), expirationDate(""), cardNumber("")
{
	// deliberately empty
}

CreditCardPayment::CreditCardPayment(float ccpAmountOfPayment, 
	string ccpNameOnCard, string ccpExpirationDate, string ccpCardNumber)
	: Payment(ccpAmountOfPayment), nameOnCard(ccpNameOnCard), 
	expirationDate(ccpExpirationDate), cardNumber(ccpCardNumber)
{
	// deliberately empty
}

void CreditCardPayment::paymentDetails()
{
	cout << "Amount of credit card payment: $" << getAmountOfPayment() << endl;
	cout << "Name on the credit card: " << nameOnCard << endl;
	cout << "Expiration date: " << expirationDate << endl;
	cout << "Credit card number: " << cardNumber << endl;	
}