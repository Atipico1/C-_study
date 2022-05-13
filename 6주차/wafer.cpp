#include <iostream>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <ctime>
#include "wafer.h"

#define LOT_SIZE 20
#define INCOMING 2000

using namespace std;
double gaussianRandom(void)
{
	srand(GetTickCount());
	double v1, v2, s;

	do {
		v1 = 2 * ((double)rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
		v2 = 2 * ((double)rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
		s = v1 * v1 + v2 * v2;
	} while (s >= 1 || s == 0);

	s = sqrt((-2 * log(s)) / s);

	return v1 * s;
};


wafer::wafer() { 
	poly_thk = new double;
	*poly_thk = INCOMING;
	}

double wafer::Measure() {
		return *poly_thk;
	}
	//deposition a nm (poly thikness increase a nm)
void wafer::depo(double a) {
		double err2 = gaussianRandom(); //err2: wafer to wafer variance
		*poly_thk += (a + err2);
	}
	//Etch a nm (poly thikness decrease a nm)
void wafer::etch(double a) {
		double err2 = gaussianRandom(); // err2: wafer to wafer variance
		*poly_thk -= (a + err2);
	}


lot::lot() {
		wafer k;
		for (int i = 0; i < 20; i++) {
			wf_num[i] = k;
		}
	}
	//deposit to make target poly_thickness (poly thickness increase (target-mean) nm)
void lot::depo_process(double target) {
		double err1 = 2 * gaussianRandom(); //err1: Lot to Lot variance
		for (int i = 0; i < 20; i++) {
			if (*(wf_num[i].poly_thk) != 0) {
				wf_num[i].depo(target - mean_poly_thk + err1);
				mean_poly_thk = target;
			}
		}
	};
	//Etch to make target poly_thickness (poly thickness decrease (mean-target) nm)
void lot::etch_process(double target) {
		double err1 = 2 * gaussianRandom(); //err1: Lot to Lot variance
		for (int i = 0; i < 20; i++) {
			if (*(wf_num[i].poly_thk) != 0) {
				wf_num[i].etch(mean_poly_thk - target + err1);
				mean_poly_thk = target;
			}
		}
	}
