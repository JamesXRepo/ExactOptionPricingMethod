#pragma once

#include "europeanOptions.h"
#include "dataStructure.h"

#include <vector>
#include <cmath>
#include <string>

using std::cin;
using std::cout;
using std::endl;

typedef double (europeanOptions::*FunctionPtr)(double, double, double, double, double, double);

class parametersMatrix
{
	private:
		std::vector<double> parameter;
		std::vector<std::vector<double>> optionPrices;
		std::string metricName;

		europeanOptions euroOption;

		Range T;
		Range K;
		Range sig;
		Range r;
		Range S;
		double b;

		void printRangeValues();

	public:

		parametersMatrix();
		~parametersMatrix();
	
		void setParameterRange();
		void calcOptionMetric();
		void paramCalcOptionMetrics(europeanOptions& obj, FunctionPtr func);
		void printOptionPrice();

};

