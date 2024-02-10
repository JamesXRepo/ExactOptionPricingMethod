#include "parametersMatrix.h" // Including the header file for the parametersMatrix class

// Default constructor for the parametersMatrix class
parametersMatrix::parametersMatrix() {}

// Destructor for the parametersMatrix class
parametersMatrix::~parametersMatrix() {}

// Function to set parameter ranges
void parametersMatrix::setParameterRange() {
    // Lambda function to prompt the user to input values for a Range struct
    auto promptRangeValues = [](const std::string& name, Range& range) {
        std::cout << "Enter the start value for " << name << ": ";
        std::cin >> range.start;

        std::cout << "Enter the end value for " << name << ": ";
        std::cin >> range.end;

        std::cout << "Enter the step value for " << name << ": ";
        std::cin >> range.step;

        system("cls"); // Clearing the screen after input

    };

    // Prompting the user to input values for each Range struct
    promptRangeValues("T", this->T);
    promptRangeValues("K", this->K);
    promptRangeValues("sig", this->sig);
    promptRangeValues("r", this->r);
    promptRangeValues("S", this->S);
}

// Function to print parameter range values
void parametersMatrix::printRangeValues() {
    // Lambda function to output the values entered by the user for each Range struct
    auto printRangeValues = [](const std::string& name, const Range& range) {
        std::cout << "Range defined for " << name << ": ";
        std::cout << "Start: " << range.start << ", ";
        std::cout << "End: " << range.end << ", ";
        std::cout << "Step: " << range.step << std::endl;
    };

    // Printing parameter range values for each Range struct
    printRangeValues("T", T);
    printRangeValues("K", K);
    printRangeValues("sig", sig);
    printRangeValues("r", r);
    printRangeValues("S", S);
}

// Function to calculate option metrics based on user selection
void parametersMatrix::calcOptionMetric() {
    int choice;
    cout << "(1) for Call Option \n(2) for Put Option\n(3) for Gamma\n(4) for Call Delta\n(5) for Put Delta\n"
        << "Which metric do you want to calculate: ";
    cin >> choice;

    // Switch statement to handle user choice and calculate the corresponding metric
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

    system("cls"); // Clearing the screen after calculation
    this->printOptionPrice(); // Printing the calculated option prices
}

// Function to calculate option metrics with parameters
void parametersMatrix::paramCalcOptionMetrics(europeanOptions& obj, FunctionPtr func) {
    // Nested loops to iterate over parameter ranges and calculate option prices
    for (double TT = this->T.start; TT <= this->T.end; TT += this->T.step) {
        for (double KK = this->K.start; KK <= this->K.end; KK += this->K.step) {
            for (double sigg = this->sig.start; sigg <= this->sig.end; sigg += this->sig.step) {
                for (double rr = this->r.start; rr <= this->r.end; rr += this->r.step) {
                    for (double SS = this->S.start; SS <= this->S.end; SS += this->S.step) {
                        b = rr; // Setting the cost of carry
                        // Calculating and storing option prices
                        this->optionPrices.emplace_back(std::vector<double>{TT, KK, sigg, SS, rr, b, (obj.*func)(TT, KK, sigg, rr, SS, b)});
                    }
                }
            }
        }
    }
}

// Function to print option prices
void parametersMatrix::printOptionPrice() {
    this->printRangeValues(); // Printing parameter range values
    // Printing header for option prices table
    cout << "T\tK\tSig\tS\tr\tb\t" << this->metricName << endl;
    // Iterating over option prices and printing them
    for (std::vector<double> vec : this->optionPrices) {
        cout << vec[0] << "\t" << vec[1] << "\t" << vec[2] << "\t" << vec[3] << "\t" << vec[4] << "\t" << vec[5] << "\t" << vec[6]
            << endl;
    }
}