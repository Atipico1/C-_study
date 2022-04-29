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
		v1 = 2 * ((double)rand() / RAND_MAX) - 1;      
		v2 = 2 * ((double)rand() / RAND_MAX) - 1;      
		s = v1 * v1 + v2 * v2;
	} while (s >= 1 || s == 0);

	s = sqrt((-2 * log(s)) / s);

	return v1 * s;
};
int main() {

	srand(GetTickCount());

	class wafer {

	public:
		double spec;
		wafer() {spec = INCOMING;}
		double Measure() {
			return spec;
		}
		void depo(double a) {
			double err2 = gaussianRandom();
			spec += (a + err2);
		}
		void etch(double a) {
			double err2 = gaussianRandom();
			spec -= (a + err2);
		}
	};

	class lot {

	public:
		double mean_spec = INCOMING;
		wafer wf_num[20];
		lot() {
			wafer k;
			for (int i=0; i < 20; i++) {
				wf_num[i] = k;
			}
		}
		void depo_process(double target) {
			double err1 = 2*gaussianRandom();
			for (int i = 0; i < 20; i++) {
				if (wf_num[i].spec != 0) {
					wf_num[i].depo(target - mean_spec + err1);
					mean_spec = target;
				}
			}
		};
		void etch_process(double target) {
			double err1 = 2*gaussianRandom();
			for (int i = 0; i < 20; i++) {
				if (wf_num[i].spec != 0) {
					wf_num[i].etch(mean_spec-target + err1);
					mean_spec = target;
				}
			}
		}

	};

	int input_lot;
	cout << "INPUT LOT NUMBER:";
	cin >> input_lot;
	int number_wafer = input_lot * 20;

	lot* test = new lot[input_lot];

	for (int i = 0; i < input_lot; i++) {
		lot k;
		test[i] = k;

	}

	int iter = 1;
	int count1 = 5;
	int count2 = 4;
	for (int x = 0; x < count2;x++) {
		for (int y = 0; y < count1; y++) {
			for (int i = 0; i < input_lot; i++) {
				test[i].depo_process(4000);
				test[i].etch_process(2000);

			};
			//cout << iter << "PROCESS"<< endl;
			iter += 1;
		}
		// ALL WAFER MEASUREMENT
		cout << "ALL WAFER MEASUREMENT: SCRAP WHEN SPEC OUT OCCUR" <<  endl;
		for (int i = 0; i < input_lot; i++) {
			double tmp_measure = 0;
			int count_present = 0;
			for (int num = 0; num < 20; num++) {
				if (test[i].wf_num[num].spec != 0) {
					if (test[i].wf_num[num].spec < 1980.0 || test[i].wf_num[num].spec > 2020.0) {
						//SPEC OUT ->SCRAP
						test[i].wf_num[num].spec = 0;
						cout << "LOTid " << i+1 << " WAFER NUMBER " << num+1 << " scrap" << endl;
						number_wafer -= 1;
					}
					else {
						count_present += 1;
						tmp_measure += test[i].wf_num[num].spec;
					}

				}
				
			}
			test[i].mean_spec = tmp_measure / count_present;

		
		}
		cout << "MEASUREMENT COMPLETE" << endl;
	}
	cout << "Number of WF: " << number_wafer<<endl;
	float survival = (float)number_wafer / (20 * (float)input_lot) * 100;
	cout << "Survival Rate " << survival << endl;


	delete test;

}
