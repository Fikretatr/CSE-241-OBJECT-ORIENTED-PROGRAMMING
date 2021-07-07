#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Payment
{
private:
	float amountOfPayment;

public:
	Payment();
	Payment(float amount);
	float getAmountOfPayment();
	void setAmountOfPayment(float pAmountOfPayment);
	void paymentDetails();
};
#endif