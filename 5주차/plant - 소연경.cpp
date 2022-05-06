#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class Plant{
  public:
    int base_hp, cur_hp;
    string stats;
    void select(int);
    void water();
    void watch();
    void insect();
    void kill();
};

void Plant::select(int n){
    if (n==1){
        base_hp = 10;
    }
    else if (n==2){
        base_hp = 15;
    }
    else if (n==3){
        base_hp = 30;
    }
    else{
        cout << "You entered the wrong number.\n";
        select(n);
    }
    cur_hp = 10;
    stats = "alive";
}

void Plant::water(){
    if (stats=="watered"){
        stats="watered";
        if (cur_hp > 5) cur_hp -= 5;
        else{
            cur_hp = 0;
        }
    }
    else if (stats=="insects") stats="insects";
    else if (stats=="dry"){
        stats="watered";
        if (base_hp > cur_hp+5) cur_hp += 5;
        else cur_hp = base_hp;
    }
    else{
        stats="watered";
        if (base_hp > cur_hp+3) cur_hp += 3;
        else cur_hp = base_hp;
    }
}
void Plant::watch(){
    if (cur_hp==0) cur_hp = 0;
    else if (stats == "insects"){
        stats = "insects";
        if (cur_hp > 2) cur_hp -= 2;
        else{
            cur_hp = 0;
        }
    }
    else if (stats == "dry"){
        stats = "dry";
        if (cur_hp > 2) cur_hp -= 2;
        else{
            cur_hp = 0;
        }
    }
    else if (stats == "watered"){
        stats = "dry";
        if (base_hp > cur_hp+3) cur_hp += 3;
        else cur_hp = base_hp;
    }
    else {
        stats = "dry";
        if (base_hp > cur_hp+1) cur_hp += 1;
        else cur_hp = base_hp;
    }
}
void Plant::insect(){
    srand(time(0));
    if(rand()%10>7){
        stats = "insects";
    }
}
void Plant::kill(){
    if (stats=="insects"){
        stats = "alive";
        if (base_hp > cur_hp+5) cur_hp += 5;
        else cur_hp = base_hp;
    }
    else {
        if (cur_hp > 3) cur_hp -= 3;
        else{
            cur_hp = 0;
        }
    }
}



int main(){
    int p_num;
    int b_num;
    Plant p;
    cout << "Please select one plant and type its number:\n1.strawberry 2.cherry tomato 3.basil\n";
    cin >> p_num;
    p.select(p_num);
    for (int i;i<100;i++){
        cout << "+++++++++++++++++++++++++\nDAY " << i << "\n";
        cout << "Plant's health is:" << p.cur_hp << "\n";
        cout << "Plant's status is:" << p.stats << "\n";
        cout << "Please select one behavior and type its number:\n1.water 2.watch 3.kill insects\nto end, please enter 0\n";
        cin >> b_num;
        if (b_num==0){
            break;
        }
        else if (b_num==1){
            p.water();
        }
        else if (b_num==2){
            p.watch();
        }
        else if (b_num==3){
            p.kill();
        }
        else{
            cout << "You entered the wrong number. Try again.\n";
            break;
        }

        if (p.cur_hp == 0){
            cout << "Your plant died. Try again.\n";
            break;
        }
        p.insect();
    }

    return 0;
}