#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "story.h"
#include <vector>
using namespace std;

int Character:: setProb(){
    prob = rand() % 10;
    return 1; // 10번중에 거짓말을 하는 횟수 (즉, prob/10 = 거짓말할 확률)
}

bool Character:: getGender(){
    //거짓말
    if (rand() % 10 < prob) 
        return gender;
    //진실
    else
        return !gender; 
}

int Character:: getAge(){
    //거짓
    if (rand() % 10 < prob) 
        return (age+1);
    //진실
    else
        return age;
}

int Character:: getBirth(){
    //거짓
    if (rand() % 10 < prob) 
        return (birth+10000);
    //진실
    else
        return birth;
}

int villain:: setProb(){
    prob = 10; 
    return 1;// 10번중에 거짓말을 하는 횟수 (즉, prob/10 = 거짓말할 확률)
}

bool villain:: getGender(){return !gender; }

int villain:: getAge(){ return (age+1);}

int villain:: getBirth(){return (birth+1);}

void helper::getprob(Character* c, Character* d, Character* e){
    prob_1 = c->prob;
    prob_2 =d->prob;
    prob_3 = e->prob;
}

void prolog:: ask(Character* x,int f){
    switch (f)
    {
        case 1:
            cout<<"[Diamond_is_carbon]";
            break;
        case 2:
            cout<<"[Heart_is_organ]";
            break;
        case 3:
            cout<<"[Sun_is_one_of_stars]";
            break;
    }
    if (rand() % 10 < x->prob) 
        cout<<" is false";
    //진실
    else
        cout<<"is True";
}


