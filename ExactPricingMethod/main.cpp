#include "europeanOptions.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main() {
	europeanOptions euroOption;

	double T = 0.5;
	double K = 100;
	double sig = 0.36;
	double r = 0.1;
	double S = 105;
	double b = 0;

	double callPrice = euroOption.calcCallOptionPrice(T, K, sig, r, S, b);
	double putPrice = euroOption.calcPutOptionPrice(T, K, sig, r, S, b);
	
	double Gamma = euroOption.calcGamma(T, K, sig, r, S, b);
	double callDelta = euroOption.calcCallDelta(T, K, sig, r, S, b);
	double putDelta = euroOption.calcPutDelta(T, K, sig, r, S, b);

	cout << "Call: " << callPrice << endl
		<< "Put: " << putPrice << endl
		<< "Call Delta: " << callDelta << endl
		<< "Put Delta: " << putDelta << endl;

	return 0;
}