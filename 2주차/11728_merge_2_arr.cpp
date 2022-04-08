#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N, M;                           //global var, length of two arrays

void MergeArray(vector<int> A, vector<int> B){
    sort(A.begin(), A.end());       //Algoritm header에 있는 sort()
    sort(B.begin(), B.end());

    vector<int> ans(N+M);
    int ptrA = 0;
    int ptrB = 0;

    while(ptrA < N && ptrB < M){
        if (A[ptrA] < B[ptrB]){
            ans[ptrA+ptrB] = A[ptrA];
            ptrA++;
        }
        else{
            ans[ptrA+ptrB] = B[ptrB];
            ptrB++;
        }
    }

    while(ptrA<N){                  //A vector 탐색 미완
        ans[M+ptrA] = A[ptrA++];
    }
    while(ptrB<M){                  //B vector 탐색 미완
        ans[N+ptrB] = B[ptrB++];
    }

    cout <<"Answer : ";
    for (int i : ans){
        cout << i<<' ';
    }
}

int main(){
    cout << "Enter length of two arrays : ";
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);
    cout << "Enter array A : " ;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
    cout << "Enter array B : ";
    for (int j=0; j<M ; j++){
        cin >> B[j];
    }

    MergeArray(A, B);

    return 0;
}