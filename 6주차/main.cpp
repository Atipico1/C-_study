#include "linear_regression.h"
#include "wafer.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <random>



using namespace std;

class equip {
protected:
	// equip parameter
	double mcoef;
	double mintercept;
public:
	//default parameter 0
	equip() {
		mcoef = 0;
		mintercept = 0;
	}
	bool issetup() {
		if (mcoef == 0 && mintercept == 0) {
			return false;
		}
		else {
			return true;
		}
	}
	//equip setup using linear regression e
	void setup() {
		DataGenerator Sample;
		Sample.Generate();
		vector<double> X = Sample.SampleX();
		vector<double> Y = Sample.SampleY();
		LinearRegression Tuning;
		Tuning.Fit(X, Y);
		mcoef = Tuning.mCoef;
		mintercept = Tuning.mIntercept;
		Tuning.GetParams();
	}
	virtual double process(wafer A, double target) {
		return 0;
	}

};


class etch :public equip {
	//Etch process using setup parameter
	double process(wafer A, double target) {
		if (not(this->issetup())) {
			cout << "Need Setup";
		}
		//if target is smaller than wafer thk stop depo
		if (*(A.poly_thk) < target) {
			cout << "Process Stop and Go Etch STEP";
			return 0;

		}
		else {
			double time;
			time = (*(A.poly_thk) - target - mintercept) / mcoef;
			//*(A.poly_thk) -= ((5 * time) + 10);
			A.etch(((5 * time) + 10));
			return time;
		}
	}

};
class depo :public equip {
	//Depo process using setup parameter
	double process(wafer A, double target) {
		if (not(this->issetup())) {
			cout << "Need Setup"<<endl;
		}
		//if target is bigger than wafer thk stop etch
		if (*(A.poly_thk) > target) {
			
			cout << "Process Stop and Go DEPO STEP"<<endl;
			return 0;
		}
		else {
			cout << "Processing" << endl;
			double time;
			time = (target-*(A.poly_thk)- mintercept) / mcoef;
			cout << time << endl;
			//*(A.poly_thk)) += ((5 * time) + 10);
			A.depo(((5 * time) + 10));
			return time;
		}
	}

};

double DataGenerator::Coef = 5;
double DataGenerator::Intercept = 10;
double DataGenerator::Std = 10;
int DataGenerator::Min = 0;
int DataGenerator::Max = 1000;
int DataGenerator::Size = 10;

int main() {
	equip *A, *B;
	wafer QLOD01;
	depo DEPO01;
	etch ETCH01;
	A = &DEPO01;
	B = &ETCH01;

	A->setup();
	B->setup();
	B->process(QLOD01, 4000);


}