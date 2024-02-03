#pragma once

#include "europeanOptions.h"
#include "dataStructure.h"

#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

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

	void calcCallOptionPrice(europeanOptions& obj);

	void printOptionPrice() const;




};

