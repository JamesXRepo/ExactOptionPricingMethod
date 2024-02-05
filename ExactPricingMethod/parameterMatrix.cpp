#include "parametersMatrix.h"

parametersMatrix::parametersMatrix() {}

parametersMatrix::~parametersMatrix() {}

void parametersMatrix::setParameterRange() {
	// Function to prompt the user to input values for a Range struct
	auto promptRangeValues = [](const std::string& name, Range& range) {
		std::cout << "Enter the start value for " << name << ": ";
		std::cin >> range.start;

		std::cout << "Enter the end value for " << name << ": ";
		std::cin >> range.end;

		std::cout << "Enter the step value for " << name << ": ";
		std::cin >> range.step;

		system("cls");

	};

	// Prompt the user to input values for each Range struct
	promptRangeValues("T", this->T);
	promptRangeValues("K", this->K);
	promptRangeValues("sig", this->sig);
	promptRangeValues("r", this->r);
	promptRangeValues("S", this->S);

}

void parametersMatrix::printRangeValues() {
	// Output the values entered by the user for each Range struct
	auto printRangeValues = [](const std::string& name, const Range& range) {
		std::cout << "Range defined for " << name << ": ";
		std::cout << "Start: " << range.start << ", ";
		std::cout << "End: " << range.end << ", ";
		std::cout << "Step: " << range.step << std::endl;
	};

	printRangeValues("T", T);
	printRangeValues("K", K);
	printRangeValues("sig", sig);
	printRangeValues("r", r);
	printRangeValues("S", S);
}

void parametersMatrix::calcOptionMetric() {
	int choice;
	cout << "(1) for Call Option \n(2) for Put Option\n(3) for Gamma\n(4) for Call Delta\n(5) for Put Delta\n"
		<< "Which metric do you want to calculate: ";
	cin >> choice;

	switch (choice) {
	case 1:
		this->paramCalcOptionMetrics(this->euroOption, &europeanOptions::calcCallOptionPrice);
		this->metricName = "Call Option";
		break;
	case 2:
		this->paramCalcOptionMetrics(this->euroOption, &europeanOptions::calcPutOptionPrice);
		this->metricName = "Put Option";
		break;
	case 3:
		this->paramCalcOptionMetrics(this->euroOption, &europeanOptions::calcGamma);
		this->metricName = "Gamma";
		break;
	case 4:
		this->paramCalcOptionMetrics(this->euroOption, &europeanOptions::calcCallDelta);
		this->metricName = "Call Delta";
		break;
	case 5:
		this->paramCalcOptionMetrics(this->euroOption, &europeanOptions::calcPutDelta);
		this->metricName = "Put Delta";
		break;
	default:
		break;
	}

	system("cls");
	this->printOptionPrice();
}

void parametersMatrix::paramCalcOptionMetrics(europeanOptions& obj, FunctionPtr func) {

	for (double TT = this->T.start; TT <= this->T.end; TT += this->T.step) {
		for (double KK = this->K.start; KK <= this->K.end; KK += this->K.step) {
			for (double sigg = this->sig.start; sigg <= this->sig.end; sigg += this->sig.step) {
				for (double rr = this->r.start; rr <= this->r.end; rr += this->r.step) {
					for (double SS = this->S.start; SS <= this->S.end; SS += this->S.step) {
						b = rr;
						this->optionPrices.emplace_back(std::vector<double>{TT, KK, sigg, SS, rr, b, (obj.*func)(TT, KK, sigg, rr, SS, b)});
					}
				}
			}
		}
	}
}

void parametersMatrix::printOptionPrice() {
	this->printRangeValues();
	cout << "T\tK\tSig\tS\tr\tb\t" << this->metricName << endl;
	for (std::vector<double> vec : this->optionPrices) {
		cout << vec[0] << "\t" << vec[1] << "\t" << vec[2] << "\t" << vec[3] << "\t" << vec[4] << "\t" << vec[5] << "\t" << vec[6]
			<< endl;
	}
}