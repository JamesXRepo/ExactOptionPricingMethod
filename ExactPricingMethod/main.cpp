#include "europeanOptions.h"
#include "parametersMatrix.h"
#include "dataStructure.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void run() {
	parametersMatrix paraMatrix;
	paraMatrix.setParameterRange();
	paraMatrix.calcOptionMetric();
}

int main() {
	run();
	
	return 0;
}