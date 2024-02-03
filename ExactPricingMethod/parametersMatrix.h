#pragma once

#include "europeanOptions.h"
#include "dataStructure.h"

#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

typedef double (europeanOptions::*FunctionPtr)(double, double, double, double, double, double);

class parametersMatrix
{
private:
	std::vector<double> parameter;
	std::vector<std::vector<double>> optionPrices;

	Range T;
	Range K;
	Range sig;
	Range r;
	Range S;
	double b;

public:

	parametersMatrix();
	~parametersMatrix();
	
	void setParameterRange(Range T, Range K, Range sig, Range r, Range S);
	void calcOptionPrice(europeanOptions& obj, FunctionPtr func);
	void printOptionPrice() const;

};

