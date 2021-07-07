#include "payment.h"
#include "cashpayment.h"
#include "creditcardpayment.h"

int main()
{
	CashPayment cp1(100.50);
	CashPayment cp2(45.60);
	CreditCardPayment ccp1(125.15, "Muhammet", "07/06/2020", "1801042693");
	CreditCardPayment ccp2(65.70, "Fikret", "10/09/2020", "1469301469");

	cout << "Details of Cash #1..." << endl;
	cp1.paymentDetails();
	
	cout << "\nDetails of Cash #2..." << endl;
	cp2.paymentDetails();
	
	cout << "\nDetails of Credit Card #1..." << endl;
	ccp1.paymentDetails();
	
	cout << "\nDetails of Credit Card #2..." << endl;
	ccp2.paymentDetails();
		
	return 0;
}