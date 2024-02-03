#include "parametersMatrix.h"

parametersMatrix::parametersMatrix() {}

parametersMatrix::~parametersMatrix() {}

void parametersMatrix::setParameterRange(Range T, Range K, Range sig, Range r, Range S) {
	this->T = T;
	this->K = K;
	this->sig = sig;
	this->r = r;
	this->S = S;
}

void parametersMatrix::calcCallOptionPrice(europeanOptions& obj) {
	for (double TT = this->T.start; TT <= this->T.end; TT += this->T.step) {
		for (double KK = this->K.start; KK <= this->K.end; KK += this->K.step) {
			for (double sigg = this->sig.start; sigg <= this->sig.end; sigg += this->sig.step) {
				for (double rr = this->r.start; rr <= this->r.end; rr += this->r.step) {
					for (double SS = this->S.start; SS <= this->S.end; SS += this->S.step) {
						b = rr;
						this->optionPrices.emplace_back(std::vector<double>{TT, KK, sigg, SS, rr, b, obj.calcCallOptionPrice(TT, KK, sigg, rr, SS, b)});
					}
				}
			}
		}
	}
}

void parametersMatrix::printOptionPrice() const {
	for (std::vector<double> vec : this->optionPrices) {
		cout << " For T: " << vec[0] << " K: " << vec[1] << " Sig: " << vec[2] << " S: " << vec[3] << " r: " << vec[4] << " b: " << vec[5]
			<< " Option Price: " << vec[6]
			<< endl;
	}
}