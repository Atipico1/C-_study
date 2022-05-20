#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Grid2D
{
public:
    int N;
    int **array;
    string filename;
    
public:
    Grid2D(const int n, const float b, const float g)
    {
        N = n;
        array = new int *[N];
        for (int i = 0; i < N; i++)
        {
            array[i] = new int[N];
            memset(array[i], 0, sizeof(int) * N);
        }
        filename = to_string(b);
        ofstream ofile("sir/"+filename+".txt");
        ofile.close();
    }
    
    ~Grid2D()
    {
        for(int i = 0; i < N; ++i)
        {
            delete [] array[i];
        }
        delete [] array;
    }
    
    void Print()
    {
        ofstream ofile("sir/"+filename+".txt", ios::app);
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofile << array[i][j] << " ";
            }
            ofile << endl;
        }
        ofile.close();
    }
};

class SIR : public Grid2D
{
public:
    float beta, gamma;
    int numS, numI, numR;
    vector<int> infected_X;
    vector<int> infected_Y;

public:
    SIR(const int n, const float b, const float g)
        : Grid2D(n, b, g), numS(n*n-4), numI(4), numR(0)
    {
        beta = (int) (b * 100);
        gamma = (int) (g * 100);
        
        array[9][9] = 1;
        array[19][19] = 1;
        array[29][29] = 1;
        array[39][39] = 1;
    }
    
    void Calculate()
    {
        vector<int> temp_X;
        vector<int> temp_Y;
        int countS = 0;
        int countI = 0;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (array[i][j] == 1)
                {
                    temp_X.push_back(i);
                    temp_Y.push_back(j);
                    countI += 1;
                }
                else if (array[i][j] == 0)
                {
                    countS += 1;
                }
            }
        }
        infected_X = temp_X;
        infected_Y = temp_Y;
        numS = countS;
        numI = countI;
        numR = N * N - countS - countI;
    }
    
    void Infect()
    {
        for (int i = 0; i < numI; i++)
        {
            int x = infected_X[i];
            int y = infected_Y[i];
            
            int neighbor = rand() %4;
            if (neighbor == 0)
            {
                x -= 1;
                if (x < 0) {x = N - 1;}
            }
            
            if (neighbor == 1)
            {
                x += 1;
                if (x > N - 1) {x = 0;}
            }
            
            if (neighbor == 2)
            {
                y -= 1;
                if (y < 0) {y = N - 1;}
            }
            
            if (neighbor == 3)
            {
                y += 1;
                if (y > N - 1) {y = 0;}
            }
            
            int infectProb = rand() %100;
            if  (infectProb < beta)
            {
                if (array[x][y] == 0)
                    array[x][y] = 1;
            }
        }
    }
    
    void Recover()
    {
        for (int i = 0; i < numI; i++)
        {
            int recoverProb = rand() %100;
            if  (recoverProb < gamma)
            {
                int x = infected_X[i];
                int y = infected_Y[i];
                array[x][y] = 2;
            }
        }
    }
};

void simulate(int N, float beta, float gamma)
{
    srand(int(time(0)));
    
    SIR model(N, beta, gamma);
    model.Calculate();
    model.Print();
    
    while (model.numI != 0)
    {
        model.Infect();
        model.Recover();
        model.Calculate();
        model.Print();
    }
}

float simulate2(int N, float beta, float gamma)
{
    srand(int(time(0)));
    SIR model(N, beta, gamma);
    model.Calculate();
    while (model.numI != 0)
    {
        model.Infect();
        model.Recover();
        model.Calculate();
    }
    return (float) model.numR;
}

int main()
{
    float beta = 0.1;
    for (int i = 0; i < 10; i++)
    {
        beta = (float) (0.1 * (i + 1));
        simulate(40, beta, 0.15);
    }
    return 0;
}
/*
int main()
{
    int N = 40;
    float result[50];
    float tempR = 0.0;
    float beta = 0.15;
    float gamma = 0.15;
    float ensemble = 200.0;
    
    for (int i = 0; i < 50; i++)
    {
        tempR = 0.0;
        for (int j = 0; j < ensemble; j++)
        {
            cout << i << ", " << j << endl;
            beta = (0.02 * ((float) i + 1));
            tempR += simulate2(N, beta, gamma);
        }
        result[i] = tempR / ensemble / ((float) (N * N));
    }
    
    ofstream ofile("sir/result.txt");
    for (int i = 0; i < 50; i++)
    {
        ofile << result[i] << endl;
    }
    ofile.close();
    
    return 0;
}
*/
