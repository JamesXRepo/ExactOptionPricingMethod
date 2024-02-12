#include "europeanOptions.h"
#include "parametersMatrix.h"
#include "dataStructure.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

bool reRunProgram() {
	char answer;
	cout << "Do you want to make another Option Metric Calculation? (Y/N): ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		system("cls");
		return true;
	}
	return false;
}

void run() {
	bool run_program = true;
	while (run_program) {
		parametersMatrix paraMatrix;
		paraMatrix.setParameterRange();
		paraMatrix.calcOptionMetric();
		run_program = reRunProgram();		
	}
}

int main() {
	run();
	
	return 0;
}