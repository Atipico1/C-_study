#pragma once

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <random>


using namespace std;

class LinearRegression
{
private:

	double mRsquared;
	unsigned long mSize;
	double mMean_x;
	double mMean_y;

public:
	double mCoef;
	double mIntercept;
	void Fit(vector <double> tTrain_x, vector <double> tTrain_y);
	void GetParams();
	void GetScore();
	void Predict(vector <double> tTest_x, vector <double> tTest_y);
};


class DataGenerator
{
public:
	static double Coef;
	static double Intercept;
	static double Std;
	static int Size;
	static int Min;
	static int Max;
	vector <double> Vector_x;
	vector <double> Vector_y;

private:
	double mRandValue;
	double mRandNoise;

public:
	void Generate();
	
	vector<double> SampleX();
	
	vector<double> SampleY();

};
