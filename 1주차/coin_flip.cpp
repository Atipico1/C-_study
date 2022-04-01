#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

void gamble(int & seed, int & goal, int & prob)
{
    srand(int(time(0)));
    string flip, guess;
    int bet, random, round = 0;
    while (seed > 0 & seed < goal & guess != "quit")
    {
        round++; sleep(1);
        cout << "-------------------------------------------------" << endl;
        cout << "#Round " << round << endl;
        cout << "#Seed: $" << seed << " & Goal: $" << goal << endl;
        
        do
        {
            cout << "#What is your guess: head or tail?" << endl;
            cin >> guess;
        }
        while (guess != "head" & guess != "tail" &  guess != "quit");
        
        if (guess == "quit") break;
        
        do
        {
            cout<< "#How much do you want to bet?" << endl;
            cin >> bet;
        }
        while (bet < 1 || bet > min(seed, goal-seed));

        random = rand() %100;
        cout<< "... Tossed a coin!" << endl; sleep(1);

        if (random < prob) flip = "head";
        else    flip = "tail";
        
        if (flip == guess)
        {
            cout<< "#Correct!" << endl; sleep(1);
            seed += bet;
            cout<< "#You gained $" << bet << ". Now you have $" << seed << endl;
        }
        else
        {
            cout << "#Wrong!" << endl; sleep(1);
            seed -= bet;
            cout<< "#You lost $" << bet << ". Now your have $" << seed << endl;
        }
    }
    sleep(1); cout << "-------------------------------------------------" << endl;
    if (seed <= 0)
        cout << "#You Lost!" << endl;
    else if (seed >= goal)
        cout << "#You Won!" << endl;
    else if (guess == "quit")
        cout << "#You Quit!" << endl;
}

int main()
{
    int seed, goal, prob;
    char answer;
    do
    {
        cout << "-------------------------------------------------" << endl;
        cout << "-------------------------------------------------" << endl;
        cout<<"#Welcome to Coin Filp Gamble\n"<<endl;

        do
        {
            cout<<"#Please enter the amount of your goal:"<<endl;
            cin >> goal;
        }
        while (goal <= 0);
        
        do
        {
            cout<<"#Please enter the amount of your seed:"<<endl;
            cin >> seed;
        }
        while (seed >= goal || seed <= 0);
        
        do
        {
            cout << "#Please enter the probability of head (1~99)" << endl;
            cin >> prob;
        }
        while (prob <= 0 || prob >= 100);
        
        gamble(seed, goal, prob); sleep(1);
        cout << "#Do you want to play again? (y/n)" << endl;
        cin >> answer;
    }
    while (answer == 'y');
}
