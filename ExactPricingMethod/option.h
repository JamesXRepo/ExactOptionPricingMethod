#pragma once
class Option
{
public:
	virtual double calcCallOptionPrice(double T, double K, double sig, double r, double S, double b) = 0;
	virtual double calcPutOptionPrice(double T, double K, double sig, double r, double S, double b) = 0;
};

