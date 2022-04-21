#include <iostream>
#include <string>
using namespace std;

float cur_temp;

string clothes(float temp){

    // making point array
    string* ptray[8];
    string over_28 = "sleeveless, short-sleeved, linen";
    string from_23 = "short-sleeved, cotton";
    string from_20 = "long_sleeved, slacks";
    string from_17 = "thin cardigan, knitwear, pullover";
    string from_12 = "jacket, cardigan, knitwear";
    string from_9 = "trench, jumper, flannel";
    string from_5 = "wool, heattech, leather, flannel";
    string under_4 = "padded, thick coat, muffler";
    ptray[0] = &over_28;
    ptray[1] = &from_23;
    ptray[2] = &from_20;
    ptray[3] = &from_17;
    ptray[4] = &from_12;
    ptray[5] = &from_9;
    ptray[6] = &from_5;
    ptray[7] = &under_4;

    if (temp>28)
    return *ptray[0];
    else if (temp>=23)
    return *ptray[1];
    else if (temp>=20)
    return *ptray[2];
    else if (temp>=17)
    return *ptray[3];
    else if (temp>=12)
    return *ptray[4];
    else if (temp>=9)
    return *ptray[5];
    else if (temp>=5)
    return *ptray[6];
    else if (temp<5)
    return *ptray[7];
}

int main(){
    cout << "Please enter current temperature(Celsius): ";
    cin >> cur_temp;
    cout << "You can wear " << clothes(cur_temp);
    return 0;
}