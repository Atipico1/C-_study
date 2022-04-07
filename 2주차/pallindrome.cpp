#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool is_pallindrome(string ipt){
    for (int i=0 ; i<ipt.length()/2 ; i++){
        if (ipt[i] != ipt[ipt.length()-i-1]){
            return false;
        }
    }
    return true;
}

int main(void){
    string ipt;
    int num;

    cout << "Enter number of strings to test : " ;
    cin >> num;

    while(num>0){
        cout << "Enter your string : ";
        //getline(cin, ipt); -> sol : 이거 이전에 cin.clear(); 해줄것. 
        cin >> ipt;

        if (is_pallindrome(ipt) == true){
            cout << "Your string is a pallindrome!" <<endl;
        }
        else{
            cout << "Your string is not a pallindrome!" << endl;
        }

        num--;
    }
    return 0;
}