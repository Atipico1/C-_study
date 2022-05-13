#pragma once
#include <iostream>
#include <vector>

class helper; 
class prolog;

class Character{
    public:
    friend class helper;
    friend class prolog;
    Character(bool g, int a, int b){
        gender = g;
        age = a;
        birth = b;
        prob = 0;
    }
    bool gender;
    virtual bool getGender();
    virtual int getAge();
    virtual int getBirth(); // 980619 
    virtual int setProb();

    protected:
    int age;
    int birth;
    int prob;
};

class villain : public Character{
    public: 
    villain(bool g, int a, int b) : Character(g,a,b) {};
    virtual bool getGender();
    virtual int getAge();
    virtual int getBirth();
    virtual int setProb();
};

class helper{
    public:
    int prob_1, prob_2, prob_3;
    void getprob(Character* c, Character* d, Character* e);
};

class prolog{
    public:
    enum fact { Diamond_is_carbon = 1, Heart_is_organ, Sun_is_one_of_stars };
    void ask(Character* x,int f);
};