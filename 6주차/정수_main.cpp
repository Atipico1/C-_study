#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "story.h"
#include <vector>
using namespace std;

int main(){
    label:
    Character* A;
    Character person(true,25,980321);
    A = &person;

    Character* B;
    Character human(false,27,960412);
    B=&human;

    Character* C;
    switch (rand() % 2)
        {
        case 1:
            C = new villain(false, 25,980202);
            break;
        case 2: 
            C = new Character(true,26,970403);
            break;
        }
    
    A->setProb();
    B->setProb();
    C->setProb();
    cout<<"A and B said [q] killed x"<<endl;
    cout<<"C said [q] did not kill x."<<endl;
    cout<<"is [q] a killer? A,B,C has their own probability to lie."<<endl;
    cout<<"you will infer each's probability using 5 questions."<<endl;
    cout<<"you can use 3 personal questions(from age, gender, birth)"<<endl;
    for (int i=0; i<3;i++){
        int ans ;
        cout<<"1: age, 2:gender, 3:birth"<<endl;
        cin>>ans;
        cout<<"answer: ";
        switch (ans){
            case 1:
            cout<< A->getAge()<<endl;
            break;

            case 2:
            cout<<A->getGender()<<endl;
            break;
            
            case 3:
            cout<<A->getBirth()<<endl;
            break;
        }
    }

    for (int i=0; i<3;i++){
        int ans ;
        cout<<"1: age, 2:gender, 3:birth"<<endl;
        cin>>ans;
        cout<<"answer: ";
        switch (ans){
            case 1:
            cout<< B->getAge()<<endl;
            break;

            case 2:
            cout<<B->getGender()<<endl;
            break;
            
            case 3:
            cout<<B->getBirth()<<endl;
            break;
        }
    }

    for (int i=0; i<3;i++){
        int ans ;
        cout<<"1: age, 2:gender, 3:birth"<<endl;
        cin>>ans;
        cout<<"answer: ";
        switch (ans){
            case 1:
            cout<< C->getAge()<<endl;
            break;

            case 2:
            cout<<C->getGender()<<endl;
            break;
            
            case 3:
            cout<<C->getBirth()<<endl;
            break;
        }
    }
    
    helper h;
    int c1;
    int c2;
    c1 = h.prob_1*h.prob_2*(10-h.prob_3);
    c2 = (10-h.prob_1)*(10-h.prob_2)*h.prob_3;
    
    float p;
    p = c1/(c1+c2);

    int real;
    if (p>0.5){real = 1;}
    else {real=0;}

    cout<<"do u think [q] is killer? (yes:1, no:0)"<<endl;
    int y1;
    cin>>y1;
    if (y1 == real){cout<<"Congratulation!"<<endl;}
    else {
    cout<<"you need help? (yes or no)"<<endl;
    string y2;
    cin>>y2;
    
    if (y2 == "yes"){
        cout<<"prob1: "<<h.prob_1<<"prob2: "<<h.prob_2<<"prob3: "<<h.prob_3<<endl;
        cout<<"real answer is "<<real<<endl;
    }
    else{
        cout<<"you restart the game"<<endl;
        goto label;
    }
    }
}
