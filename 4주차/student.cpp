#include "student.h"
#include <iostream>
#include <stdio.h>

using namespace std;

/*Supper class*/
Student::Student(void){
    hp = 10;  //maximum 10
    sp = 0;  //maximum 10
}

void Student::Study(int hr){
    hp -= 1;
    sp += 1;
}

void Student::HangOut(int hr){
    hp -=1;
}

void Student::Status(void) {
    cout << "hp: " << hp << '\n' << "sp: " << sp << endl;
}

/*Sub classes*/
void UnderGradStudent:: Study(int hr){
    if (hp>0)
        {hp -= 1;
        sp += 1;}
    else
        {cout << "오늘은 쉬어야지!" << endl;}
}

void UnderGradStudent:: HangOut(int hr){
    hp -=1;
}

void GradStudent:: Study(int hr){
    hp -=2;
    sp +=2;
}

void GradStudent::HangOut(int hr){
    if (hp>0)
        {hp -=3;}
    else 
        {cout << "오늘은 쉬어야지.." << endl;}
}
