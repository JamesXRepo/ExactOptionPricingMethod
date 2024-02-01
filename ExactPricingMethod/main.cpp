#include "europeanOptions.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main() {
	europeanOptions euroOption;

	double T = 0.25;
	double K = 65;
	double sig = 0.30;
	double r = 0.08;
	double S = 60;
	double b = r;

	double callPrice = euroOption.calcCallOptionPrice(T, K, sig, r, S, b);
	double putPrice = euroOption.calcPutOptionPrice(T, K, sig, r, S, b);
	
	cout << "Call: " << callPrice << endl << "Put: " << putPrice << endl;

	return 0;
}