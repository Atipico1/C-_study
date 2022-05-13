#pragma once

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include<ctime>

#define LOT_SIZE 20
#define INCOMING 2000

using namespace std;
double gaussianRandom(void);

class wafer {

public:
	double *poly_thk;

	//wafer has 2000nm poly thinkness
	wafer();
	double Measure();
	void depo(double a);
	void etch(double a);

};
class lot {

public:
	//ALL wafer have 2000nm poly thickness
	double mean_poly_thk = INCOMING;
	wafer wf_num[20];
	lot();
		//deposit to make target poly_thickness (poly thickness increase (target-mean) nm)
	void depo_process(double target);
		//Etch to make target poly_thickness (poly thickness decrease (mean-target) nm)
	void etch_process(double target);

};