#include "student.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 7

using namespace std;

int main(void){
    int i = 0;
    int mypick;
    int myhr;
    Student *A;

    
        // 랜덤으로 Student Object 만들기
        switch (rand() % 2)
        {
        case 1:
            A = new UnderGradStudent;
            break;
        case 2: 
            A = new GradStudent;
            break;
        }
        cout << "Assignment Completed" << endl;
    
    //일주일 시뮬레이션
    while (i < NUM) {
        cout << "Day" << i+1 <<". Choose one of two - 1: Study 2: Hang out" << endl;
        cin >> mypick;
        cout << "How long?"<< endl;
        cin >> myhr;
        switch (mypick){ 
            case 1:
                A->Study(myhr);
                break;
            case 2:
                A->HangOut(myhr);
        
        }
        i = i+1;
    }
    
    A->Status();
}

