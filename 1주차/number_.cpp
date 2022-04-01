#include <string>
#include <iostream>
using namespace std;

int exchange(string s) {
    int ans = 0;
    
    string str = ""; 
    for(int i = 0; i < s.size(); i++) {
        if('0'<=s[i] && s[i]<='9') {
            str.push_back(s[i]); //append element to string vector
            continue;
        }
        //s.size()-i>=n && 
        else if(s.substr(i,3)=="one") str.push_back('1');
        else if(s.substr(i,3)=="two") str.push_back('2');
        else if(s.substr(i,5)=="three") str.push_back('3');
        else if(s.substr(i,4)=="four") str.push_back('4');
        else if(s.substr(i,4)=="five") str.push_back('5');
        else if(s.substr(i,3)=="six") str.push_back('6');
        else if(s.substr(i,5)=="seven") str.push_back('7');
        else if(s.substr(i,5)=="eight") str.push_back('8');
        else if(s.substr(i,4)=="nine") str.push_back('9');
        else if(s.substr(i,4)=="zero") str.push_back('0');      
    }
    
    ans = stoi(str); // string to int
    return ans;
}

int main() {
    int ans;
    ans = exchange("one4threenine5");
    cout << ans << endl;

    int ans2;
    ans2 = exchange("on4threenine5");
    cout << ans2;
}