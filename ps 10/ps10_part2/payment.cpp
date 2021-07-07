#include "payment.h"

Payment::Payment() : amountOfPayment(0)
{
	// deliberately empty
}

Payment::Payment(float pAmountOfPayment) : amountOfPayment(pAmountOfPayment)
{
	// deliberately empty
}

float Payment::getAmountOfPayment()
{
	return amountOfPayment;
}

void Payment::setAmountOfPayment(float pAmountOfPayment)
{
	amountOfPayment = pAmountOfPayment;
}

void Payment::paymentDetails()
{
	cout << "Amount of payment: $" << amountOfPayment << endl;
}