/*
This class contains functions to calculate the followig for european option prices:
- call price
- put option
- gamma option
- call / put delta option

The option model is based off Black-Scholes
*/
#pragma once

#include "option.h"
#include <iostream>
#include <boost/math/distributions/normal.hpp>

class europeanOptions : public Option
{
private:
	double d1; // Risk-adjusted distance between current and strike price
	double d2; // Risk-adjusted distance that d1 must move to account for time value of option

	boost::math::normal_distribution<> standardNormal; // Standard normal distribution function

	double calcD1(double T, double K, double sig, double r, double S, double b); // Helper function to calculate option call/put price
	double calcD2(double T, double K, double sig, double r, double S, double b); // Helper function to calculate option call/put price

	/*
	Parameter Definition:
	- S: Asset Price
	- K: Strike Pirce
	- T: Exercise (maturity) Date
	- r: Risk-free Interest Rate
	- sig: Constant Volatility
	- b: Cost of Carry
	*/

public:
	europeanOptions(); // Constructor
	~europeanOptions(); // Destructor

	// Calculate call option price
	double calcCallOptionPrice(double T, double K, double sig, double r, double S, double b) override;

	// Calculate put option price
	double calcPutOptionPrice(double T, double K, double sig, double r, double S, double b) override;

	// Calculate gamma option price
	double calcGamma(double T, double K, double sig, double r, double S, double b);

	// Calculate call delta price
	double calcCallDelta(double T, double K, double sig, double r, double S, double b);

	// Calculate put delta price
	double calcPutDelta(double T, double K, double sig, double r, double S, double b);

};
