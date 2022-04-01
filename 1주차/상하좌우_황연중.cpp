#include <iostream>
#include <string>
using namespace std;
int main()
{
	int x_pos = 1;
	int y_pos = 1;
	int size;
	cin >> size;
	cin.ignore(); // ignore, 입력 버퍼 비우기
	
	string move;
	getline(cin, move);
	for (int n = 0; n <= move.size(); n++) {
		if (move[n] == 'R') {
			if (x_pos+1 > size) {
				continue;
			}
			x_pos += 1;

		}
		if (move[n] == 'U') {
			if (y_pos - 1 < 1) {
				continue;
			}
			y_pos -= 1;

		}
		if (move[n] == 'D') {

			if (y_pos + 1 > size) {
				continue;
			}
			y_pos += 1;
		}
		if (move[n] == 'L') {

			if (x_pos - 1 < 1){
				continue;
			}
			x_pos += 1;


		}
	}

	cout << y_pos <<" " << x_pos;

	return 0;


};