#pragma once

#include "europeanOptions.h"
#include "option.h"

europeanOptions::europeanOptions() : d1(0), d2(0) {}

europeanOptions::~europeanOptions() {}

double europeanOptions::calcD1(double T, double K, double sig, double r, double S, double b) {
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));
	return d1;
}

double europeanOptions::calcD2(double T, double K, double sig, double r, double S, double b) {
	double d2 = this->d1 - sig * sqrt(T);
	return d2;
}

double europeanOptions::calcCallOptionPrice(double T, double K, double sig, double r, double S, double b) {
	this->d1 = this->calcD1(T, K, sig, r, S, b);
	this->d2 = this->calcD2(T, K, sig, r, S, b);
	// Calculate and store call price
	double price = (S * exp((b - r) * T) * cdf(standardNormal, this->d1)) - (K * exp(-r * T) * cdf(standardNormal, this->d2));
	return price;
}

double europeanOptions::calcPutOptionPrice(double T, double K, double sig, double r, double S, double b) {
	this->d1 = this->calcD1(T, K, sig, r, S, b);
	this->d2 = this->calcD2(T, K, sig, r, S, b);
	// Calculate and store put price
	double putPrice = K * exp(-r * T) * cdf(complement(standardNormal, d2)) - S * exp((b - r) * T) * cdf(complement(standardNormal, d1));
	return putPrice;
}

double europeanOptions::calcGamma(double T, double K, double sig, double r, double S, double b) {
	double gamma = exp((b - r) * T) * pdf(standardNormal, this->d1) / (S * sig * sqrt(T));

	return gamma;
}

double europeanOptions::calcCallDelta(double T, double K, double sig, double r, double S, double b) {
	double delta = exp((b - r) * T) * cdf(standardNormal, this->d1);

	return delta;

}

double europeanOptions::calcPutDelta(double T, double K, double sig, double r, double S, double b) {
	double delta = exp((b - r) * T) * (cdf(standardNormal, this->d1) - 1.0);

	return delta;
}