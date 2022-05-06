#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <random>

using namespace std;

class LinearRegression
{
private:
    double mCoef;
    double mIntercept;
    double mRsquared;
    unsigned long mSize;
    double mMean_x;
    double mMean_y;
    
public:
    void Fit(vector<double> tTrain_x, vector<double> tTrain_y)
    {
        mSize = tTrain_x.size();
        mMean_x = std::accumulate(tTrain_x.begin(), tTrain_x.end(), 0.0) / mSize;
        mMean_y = std::accumulate(tTrain_y.begin(), tTrain_y.end(), 0.0) / mSize;
        
        double temp_nr = 0.0;
        double temp_dr = 0.0;
        for (unsigned i = 0; i < mSize; i++)
        {
            temp_nr += (tTrain_x[i] - mMean_x) * (tTrain_y[i] - mMean_y);
            temp_dr += pow( (tTrain_x[i] - mMean_x), 2);
        }
        
        mCoef = temp_nr / temp_dr;
        mIntercept = mMean_y - mCoef * mMean_x;
        
        double rss = 0.0;
        double tss = 0.0;
        for (unsigned i = 0; i < mSize; i++)
        {
        rss += pow( (tTrain_y[i] - (tTrain_x[i] * mCoef + mIntercept)), 2);
        tss += pow( (tTrain_x[i] - mMean_x), 2);
        }
        
        mRsquared = 1.0 - (rss / tss);
    }
    
    void GetParams()
    {
        cout << "Coefficient = " << mCoef << ", Intercept = " << mIntercept << endl;
    }
    
    void GetScore()
    {
        cout << "R-squared = " << mRsquared << endl;
    }
    
    void Predict(vector<double> tTest_x, vector<double> tTest_y)
    {
        double mse = 0.0;
        for (unsigned i = 0; i < mSize; i++)
        {
            mse += pow( ( tTest_y[i] - (tTest_x[i] * mCoef + mIntercept) ), 2);
        }
        double rmse = sqrt(mse / mSize);
        cout << "RMSE = " << rmse << endl;
    }
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
    vector<double> Vector_x;
    vector<double> Vector_y;
    
private:
    double mRandValue;
    double mRandNoise;
    
public:
    void Generate()
    {
        std::random_device rand_seed;
        std::mt19937 generator(rand_seed());
        std::uniform_int_distribution<double> uniform(Min, Max);
        std::normal_distribution<double> normal(0, Std);
        
        for (unsigned i = 0; i < Size; i++)
        {
            mRandValue = uniform(generator);
            mRandNoise = normal(generator);
            Vector_x.push_back(mRandValue);
            Vector_y.push_back(mRandValue * Coef + Intercept + mRandNoise);
        }
    }
    
    vector<double> SampleX()
    {
        cout << '[';
        for (unsigned i = 0; i < 20; i++)
        {
            cout << Vector_x[i] << ", ";
        }
        cout << ']' << endl;
        return Vector_x;
    }
    
    vector<double> SampleY()
    {
        cout << '[';
        for (unsigned i = 0; i < 20; i++)
        {
            cout << Vector_y[i] << ", ";
        }
        cout << ']' << endl;
        return Vector_y;
    }
};

double DataGenerator::Coef = -5;
double DataGenerator::Intercept = 10;
double DataGenerator::Std = 10;
int DataGenerator::Min = 0;
int DataGenerator::Max = 1000;
int DataGenerator::Size = 100000;

int main()
{
    DataGenerator DataTrain;
    DataTrain.Generate();
    vector<double> dataTrain_x = DataTrain.SampleX();
    vector<double> dataTrain_y = DataTrain.SampleY();
    
    DataGenerator DataTest;
    DataTest.Generate();
    vector<double> dataTest_x = DataTest.SampleX();
    vector<double> dataTest_y = DataTest.SampleY();
    
    LinearRegression LinearModel;
    LinearModel.Fit(dataTrain_x, dataTrain_y);
    LinearModel.GetParams();
    LinearModel.GetScore();
    LinearModel.Predict(dataTest_x, dataTest_y);
}
