#pragma once

#include "option.h"
#include <iostream>
#include <boost/math/distributions/normal.hpp>

class europeanOptions : public Option
{
private:
	double d1; // Risk-adjusted distance between current and strike price
	double d2; // Risk-adjusted distance that d1 must move to account for time value of option

	boost::math::normal_distribution<> standardNormal;

	double calcD1(double T, double K, double sig, double r, double S, double b);
	double calcD2(double T, double K, double sig, double r, double S, double b);

public:
	europeanOptions();
	~europeanOptions();

	double calcCallOptionPrice(double T, double K, double sig, double r, double S, double b) override;
	double calcPutOptionPrice(double T, double K, double sig, double r, double S, double b) override;

	double calcGamma(double T, double K, double sig, double r, double S, double b); // Gamma for call and put is the same
	double calcCallDelta(double T, double K, double sig, double r, double S, double b);
	double calcPutDelta(double T, double K, double sig, double r, double S, double b);

};
