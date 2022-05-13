#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <random>
#include <Windows.h>
#include "linear_regression.h"

using namespace std;


void LinearRegression::Fit(vector<double> tTrain_x, vector<double> tTrain_y)
	{
		mSize = tTrain_x.size();
		mMean_x = std::accumulate(tTrain_x.begin(), tTrain_x.end(), 0.0) / mSize;
		mMean_y = std::accumulate(tTrain_y.begin(), tTrain_y.end(), 0.0) / mSize;

		double temp_nr = 0.0;
		double temp_dr = 0.0;
		for (unsigned i = 0; i < mSize; i++)
		{
			temp_nr += (tTrain_x[i] - mMean_x) * (tTrain_y[i] - mMean_y);
			temp_dr += pow((tTrain_x[i] - mMean_x), 2);
		}

		mCoef = temp_nr / temp_dr;
		mIntercept = mMean_y - mCoef * mMean_x;

		double rss = 0.0;
		double tss = 0.0;
		for (unsigned i = 0; i < mSize; i++)
		{
			rss += pow((tTrain_y[i] - (tTrain_x[i] * mCoef + mIntercept)), 2);
			tss += pow((tTrain_x[i] - mMean_x), 2);
		}

		mRsquared = 1.0 - (rss / tss);
	}

	void LinearRegression::GetParams()
	{
		cout << "Coefficient = " << mCoef << ", Intercept = " << mIntercept << endl;
	}

	void LinearRegression::GetScore()
	{
		cout << "R-squared = " << mRsquared << endl;
	}

	void LinearRegression::Predict(vector<double> tTest_x, vector<double> tTest_y)
	{
		double mse = 0.0;
		for (unsigned i = 0; i < mSize; i++)
		{
			mse += pow((tTest_y[i] - (tTest_x[i] * mCoef + mIntercept)), 2);
		}
		double rmse = sqrt(mse / mSize);
		cout << "RMSE = " << rmse << endl;
	}



	void DataGenerator::Generate()
	{
		std::random_device rand_seed;
		std::mt19937 generator(rand_seed());
		std::uniform_int_distribution<long> uniform(Min, Max);
		std::normal_distribution<double> normal(0, Std);

		for (unsigned i = 0; i < Size; i++)
		{
			mRandValue = uniform(generator);
			mRandNoise = normal(generator);
			Vector_x.push_back(mRandValue);
			Vector_y.push_back(mRandValue * Coef + Intercept + mRandNoise);
		}
	}

	vector<double> DataGenerator::SampleX()
	{
		cout << '[';
		for (unsigned i = 0; i < 5; i++)
		{
			cout << Vector_x[i] << ", ";
		}
		cout << ']' << endl;
		return Vector_x;
	}

	vector<double> DataGenerator::SampleY()
	{
		cout << '[';
		for (unsigned i = 0; i < 5; i++)
		{
			cout << Vector_y[i] << ", ";
		}
		cout << ']' << endl;
		return Vector_y;
	}


