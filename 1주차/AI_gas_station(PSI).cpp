#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    

    cout << "Welcome to ai gas station!\n" << endl;
    start:
    cout << "If you want to fill up, please type 'OK' : ";
    
    string car;
    cin >> car;
    if (car != "OK")
    goto start;

    cout << "\n" << "please let me know about your car.\n" << endl;
    cout << "------------------------------------------" << endl;
    cout << "---gasoline : 2030won---diesel : 1970won--" << endl;
    cout << "------------------------------------------" << endl;
    cout << "gasoline(G) or diesel(D) : ";
    string oil_type;
    cin >> oil_type;
    int price = (oil_type == "G") ? 2030 : 1970;

    cout << "capacity of the oil tank (only number) : ";
    double capacity;
    cin >> capacity;

    cout << "remain of oil in your car (only number) : ";
    double remain;
    cin >> remain;

    choice:
    cout << "------------------------------------------" << endl;
    cout << "Thank you! Please choose one of the following options." << endl;
    cout << "1. Fill it as much as the liter you choose" << endl;
    cout << "2. Fill it as much as the money you choose" << endl;
    cout << "3. Fill it up!" << endl;
    cout << "------------------------------------------" << endl;
    cout << "choose the number : ";
    int option;
    cin >> option;
    cout << "\n";

    double cost = 0;

    switch (option)
    {
    case 1:
        {a:
        double max_liter = capacity - remain;
        double liter;
        cout << "write liter you want (max " << max_liter << " L) : ";
        
        cin >> liter;
        if (liter > max_liter)
        goto a;
        cost = liter * price;
        remain += liter;}
        break;
    case 2:
        {b:
        double max_money = (capacity - remain) * price;
        double money;
        cout << "write money you will pay (max " << max_money << " won) : ";
        cin >> money;
        if (money > max_money)
        goto b;
        cost += money;
        remain += money / price;
        break;}
    case 3:
        cost += (capacity - remain) * price;
        remain = capacity;
        break;
    default:
        goto choice;
        break;
    }
    cout << "fueling.... plz wait--------------------------" << endl;
    Sleep(1300);
    cout << "-------------fueling.... plz wait-------------" << endl;
    Sleep(1300);
    cout << "--------------------------fueling.... plz wait" << endl;
    Sleep(1300);
    cout << "-------------fueling.... plz wait-------------" << endl;
    Sleep(1300);
    cout << "fueling.... plz wait--------------------------" << endl;
    Sleep(1300);

    cout << "\n" << "complete! \n" << "Cost : " << cost << "\n" << "remain : " << remain << endl;

    cout << "type 're' to restart or 'end' to exit : ";
    
    string answer;
    cin >> answer;
    if (answer == "re")
    goto start;

    return 0;

}
