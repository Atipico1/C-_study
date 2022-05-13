#include <iostream>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include<ctime>

#define LOT_SIZE 20
#define INCOMING 2000

using namespace std;
double gaussianRandom(void)
{
	double v1, v2, s;

	do {
		v1 = 2 * ((double)rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
		v2 = 2 * ((double)rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
		s = v1 * v1 + v2 * v2;
	} while (s >= 1 || s == 0);

	s = sqrt((-2 * log(s)) / s);

	return v1 * s;
};
int main() {

	srand(GetTickCount());

	class wafer {

	public:
		double poly_thk;
		//wafer has 2000nm poly thinkness
		wafer() {poly_thk= INCOMING;}
		double Measure() {
			return poly_thk;
		}
		//deposition a nm (poly thikness increase a nm)
		void depo(double a) {
			double err2 = gaussianRandom(); //err2: wafer to wafer variance
			poly_thk += (a + err2);
		}
		//Etch a nm (poly thikness decrease a nm)
		void etch(double a) {
			double err2 = gaussianRandom(); // err2: wafer to wafer variance
			poly_thk -= (a + err2);
		}
	};

	class lot {

	public:
		//ALL wafer have 2000nm poly thickness
		double mean_poly_thk = INCOMING;
		wafer wf_num[20];
		lot() {
			wafer k;
			for (int i=0; i < 20; i++) {
				wf_num[i] = k;
			}
		}
		//deposit to make target poly_thickness (poly thickness increase (target-mean) nm)
		void depo_process(double target) {
			double err1 = 2*gaussianRandom(); //err1: Lot to Lot variance
			for (int i = 0; i < 20; i++) {
				if (wf_num[i].poly_thk != 0) {
					wf_num[i].depo(target - mean_poly_thk + err1);
					mean_poly_thk = target;
				}
			}
		};
		//Etch to make target poly_thickness (poly thickness decrease (mean-target) nm)
		void etch_process(double target) {
			double err1 = 2*gaussianRandom(); //err1: Lot to Lot variance
			for (int i = 0; i < 20; i++) {
				if (wf_num[i].poly_thk != 0) {
					wf_num[i].etch(mean_poly_thk-target + err1);
					mean_poly_thk = target;
				}
			}
		}

	};

	int input_lot;
	cout << "INPUT LOT NUMBER:";
	cin >> input_lot;
	int number_wafer = input_lot * 20;

	//make lot
	lot* test = new lot[input_lot];

	for (int i = 0; i < input_lot; i++) {
		lot k;
		test[i] = k;

	}

	int iter = 1;
	int count1 = 5; // 총 20번 DEPO/ETCH 반복
	int count2 = 4; //4번 반복마다 SPEC check 및 SCRAP 진행
	for (int x = 0; x < count2;x++) {
		for (int y = 0; y < count1; y++) {
			for (int i = 0; i < input_lot; i++) {
				test[i].depo_process(4000);
				test[i].etch_process(2000);

			};
			iter += 1;
		}
		// ALL WAFER MEASUREMENT
		cout << "ALL WAFER MEASUREMENT: SCRAP WHEN SPEC OUT OCCUR" <<  endl;
		for (int i = 0; i < input_lot; i++) {
			double tmp_measure = 0;
			int count_present = 0;
			for (int num = 0; num < 20; num++) {
				if (test[i].wf_num[num].poly_thk != 0) {
					if (test[i].wf_num[num].poly_thk < 1980.0 || test[i].wf_num[num].poly_thk > 2020.0) {
						//poly_thk SPEC OUT ->SCRAP
						test[i].wf_num[num].poly_thk = 0;
						cout << "LOTid " << i+1 << " WAFER NUMBER " << num+1 << " scrap" << endl;
						number_wafer -= 1;
					}
					else {
						count_present += 1;
						tmp_measure += test[i].wf_num[num].poly_thk;
					}

				}
				
			}
			test[i].mean_poly_thk = tmp_measure / count_present;

		
		}
		cout << "MEASUREMENT COMPLETE" << endl;
	}
	cout << "Number of WF: " << number_wafer<<endl;
	float survival = (float)number_wafer / (20 * (float)input_lot) * 100;
	cout << "Survival Rate " << survival << endl;


	delete test;

}
