#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

using namespace std;

typedef vector< vector<double> > ndarray;
typedef vector<double> onedarray;

class KNN {
    public:
    KNN(int inputK);
    void train(const ndarray &trainX, const onedarray &trainY);
    void inference(const ndarray &testX);
    void compute_distance(const ndarray &testX);
    void predict_labels(const ndarray &testX);
    double evaluate(const onedarray &textY);

    private:
    int numK;
    ndarray x_train;
    onedarray y_train;
    onedarray y_pred;
    ndarray dists;
    double accuracy;

};

KNN::KNN(int inputK){
    numK = inputK;
    cout << "K = " << numK << "  |";
}

void KNN::train(const ndarray &trainX, const onedarray &trainY){
    // copy the input values
    x_train.resize(trainX.size());
    y_train.resize(trainY.size());
    copy(trainX.begin(), trainX.end(), x_train.begin());
    copy(trainY.begin(), trainY.end(), y_train.begin());
}

void KNN::inference(const ndarray &testX){
    compute_distance(testX);
    predict_labels(testX);
}

void KNN::compute_distance(const ndarray &testX){
    for (unsigned i = 0; i < testX.size() ; i++){
        onedarray unitDist;
        for (unsigned j =0; j < x_train.size() ; j++){
            double distance;
            for (unsigned k = 0; k < 3 ; k++){
                distance += (x_train[j][k] - testX[i][k]) * (x_train[j][k] - testX[i][k]);
            }
            distance = sqrt(distance);
            unitDist.push_back(distance);
        }
        dists.push_back(unitDist);
    }
}

double KNN::evaluate(const onedarray &textY){

    double correct = 0.0, incorrect = 0.0;
    for (int i=0; i < textY.size(); i++){
        if (textY[i] == y_pred[i]) correct++;
        else incorrect++;
    }
    accuracy = correct / (correct + incorrect);
    return accuracy;

}

// dist[testX][each distance]
void KNN::predict_labels(const ndarray &testX){
    for (int i=0; i<dists.size(); i++){
        // find k smallest distance
        onedarray temp;
        temp.resize(dists[i].size());
        int label;
        copy(dists[i].begin(), dists[i].end(), temp.begin());
        sort(temp.begin(), temp.end());
        vector<int> nearData;

        for (int j=numK; j > 0; j--){
            nearData.push_back(dists[i][find(dists[i].begin(), dists[i].end(), temp[j])-dists[i].begin()]);
        }
        // majority vote (binary classification)
        sort(nearData.begin(), nearData.end());
        label = nearData[(nearData.size()+1)/2];
        y_pred.push_back(label);
    }
}

int main() {

    // Random
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dis(0, 1);
    uniform_int_distribution<int> dist(0, 1);
    ndarray xTrain, xTest;
    onedarray yTrain, yTest;
    
    // Generate train data set

    for (int i=0; i < 1000; i++){
        vector<double>tempX;
        for (int feat=0; feat<3; feat++){
            double inputX = dis(gen);
            tempX.push_back(inputX);
        }
        xTrain.push_back(tempX);
        yTrain.push_back(dist(gen));
    }

    // Generate test data set

    for (int j=0; j < 200; j++){
        vector<double>tempX;
        for (int feat=0; feat<3; feat++){
            double input = dis(gen);
            tempX.push_back(input);
        }
        xTest.push_back(tempX);
        yTest.push_back(dist(gen));
    }

    // Show data's information
    cout << "train size : " << xTrain.size() << " " << yTrain.size() << endl;
    cout << "test size : " << xTest.size() << " " << yTest.size() << endl; 

    // Parameter K
    array<int, 10> kArr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout.precision(5);

    // Loop for multiple test
    for (int c = 0; c< kArr.size(); c++){
        // Generate new model
        int param = kArr[c];
        KNN* mymodel = new KNN(param);

        // training model
        mymodel->train(xTrain, yTrain);
        mymodel->inference(xTest);

        // evaluate the model
        double modelAccuracy;
        modelAccuracy = mymodel->evaluate(yTest);

        cout << " Accuracy : " << modelAccuracy << endl;
        delete mymodel;
    }
    return 0;
}
