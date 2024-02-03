#include "europeanOptions.h"
#include "parametersMatrix.h"
#include "dataStructure.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	europeanOptions euroOption;
	parametersMatrix paraMatrix;

	Range T{ .25, 0.5, 0.25 };
	Range K{ 65, 130, 65 };
	Range sig{ 0.3, 0.6, 0.3 };
	Range r{ 0.08, 0.16, 0.08 };
	Range S{ 60,120,60 };

	paraMatrix.setParameterRange(T, K, sig, r, S);
	paraMatrix.calcCallOptionPrice(euroOption);
	paraMatrix.printOptionPrice();

	return 0;
}