/*
   This class contains functions to enable the ability to set ranges of parameters and calculate user-selected option metrics.
*/

#pragma once

#include "europeanOptions.h" // Including header file for European options class
#include "dataStructure.h" // Including header file for data structures

#include <vector> // Including vector header for using std::vector
#include <cmath> // Including cmath header for mathematical functions
#include <string> // Including string header for using std::string

using std::cin; // Using cin from the standard input stream
using std::cout; // Using cout from the standard output stream
using std::endl; // Using endl for newline character

// Defining a function pointer type
typedef double (europeanOptions::* FunctionPtr)(double, double, double, double, double, double);

// Class declaration for parametersMatrix
class parametersMatrix
{
private:
    std::vector<double> parameter; // Vector to store parameters
    std::vector<std::vector<double>> optionPrices; // Vector of vectors to store option prices
    std::string metricName; // String to store metric name

    europeanOptions euroOption; // Object of europeanOptions class

    Range T; // Object of Range class for Execrise (Maturity) date parameter
    Range K; // Object of Range class for Strike price parameter
    Range sig; // Object of Range class for Volatility parameter
    Range r; // Object of Range class for Risk-free rate parameter
    Range S; // Object of Range class for Underlying asset price parameter
    double b; // Variable to store the cost of carry

    void printRangeValues(); // Function declaration to print range values

public:
    // Constructor declaration
    parametersMatrix();
    // Destructor declaration
    ~parametersMatrix();

    // Function declarations
    void setParameterRange(); // Function to set parameter ranges
    void calcOptionMetric(); // Function to calculate option metric
    void paramCalcOptionMetrics(europeanOptions& obj, FunctionPtr func); // Function to calculate option metrics with parameters
    void printOptionPrice(); // Function to print option prices
};