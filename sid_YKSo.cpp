# include <iostream>
# include <string>
# include <stdio.h>
# include <stdlib.h>
using namespace std;

int main()
{   
    string cid;
    string year;
    cout << "Input your admission year.";
    getline(cin, year);
    cid += year+'-';

    string student;
    cout << "Are you a university student? Answer Yes/No.";
    getline(cin, student);
    if (student == "Yes"){
        cid += '1';
    }
    else {
        string grad;
        cout << "Are you studying for a master's degree? Answer Yes/No.";
        getline(cin, grad);
        if (grad == "Yes"){
            cid += '2';
        }
        else {
            string doc;
            cout << "Are you in the doctoral program? Anwer Yes/No.";
            getline(cin, doc);
            if (doc == "Yes"){
                cid += '3';
            }
            else {
                cout << "You are not student.";
                return 0;
            }
        }
    }

    for (int i=0;i<4;i++){
        int num;
        num = rand()%10;
        char ch = (char)(num+48);
        cid += ch;
    }

    cout << "Your student id is " << cid << ".\n";
    return 0;
}