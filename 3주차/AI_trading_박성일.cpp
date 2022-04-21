#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

void init();
void inputKospi(int, int*);
int meanKospi(int, int*);
void result(double, int, int);

int main(){
	
	int n;
	int todayKospi;
	int profit; 
	int mean;
	
	init();
	startpoint:
	
	// n일 전까지 kospi index를 array에 int로 입력받을 지 묻고, pointer 지정	
	cout << "최근 몇일간의 코스피 지수를 입력할 것인가요 : ";
	cin >> n;
	int* ptr = new int[n];
	
	// array에 kospi index 입력 하는 function call 
	 
	inputKospi(n, ptr);
	mean = meanKospi(n, ptr);
	
	// 사용자로부터 kospi index와 목표 수익률을 입력받 
	cout << "오늘의 코스피 지수를 입력하세요 : ";
	cin >> todayKospi;
	cout << "목표 수익률(%)을 입력하세요 : ";
	cin >> profit;
	
	// 입력받은 kospi index와 목표 수익률로 투자 여부 결 
	result(mean, todayKospi, profit);
	
	// 다시 시작 여부 결정, 사용자가 Y를 입력하면 startpoint로 goto
	char k;
	cout << "다시 시작하시려면 Y, 끝내려면 N을 입력하세요 : ";
	cin >> k;
	if (k=='Y'){
		cout << "\n\n";
		goto startpoint;
	}
	delete[] ptr;
	return 0;
}

// 시작 시 print 
void init(){
	cout << "--------A I 퀀 트 투 자---------\n";
	cout << "------------당 신 도------------\n";
	cout << "-------부자가될수있습니다-------\n\n\n";
	char start;
	while(start != 'Y'){
		cout << "계속하려면 Y를 입력하세요(제발 대문자로) : ";
		cin >> start;
	}
	cout << '\n';
}


// for loop으로 array에 kospi index assign 
void inputKospi(int n, int* ptr){
	
	cout << "\n\n\n";
	for (;n>0;n--){
		cout << n << "일 전 코스피 지수를 입력하세요 : ";
		cin >> *(ptr+n-1);
	}
}

// for loop으로 array의 mean return 하는 function 
int meanKospi(int n, int* ptr){
	int i = n;
	int sum = 0;
	for (;n>0;n--){
		sum += *(ptr+n-1);
	}
	return sum/i;
}
// mean, today kospi index, 목표 수익률을 input으로 투자 여부 print 
void result(double mean, int todayKospi, int profit){
	
	double expectedKospi = mean*(100+profit)*0.01;
	 
	if (todayKospi > expectedKospi)
		cout << "예상 코스피지수가 " << (todayKospi-expectedKospi) << "p 높습니다 투자를 미루시길 권해드립니다" << endl;
	else cout << "예상 코스피지수보다 " << (expectedKospi-todayKospi) << "p 낮습니다 풀매수 타이밍입니다" << endl;

}
