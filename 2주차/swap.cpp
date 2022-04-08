#include <iostream>
#define NUM 5
using namespace std;

int *new_list (int price){
    int price_arr[NUM];
    int i = 0;
    
    while(i<NUM){     
        if (price_arr[i]){
            i++;
        }
        else{
            price_arr[i] = price;
            break;
        }
    }
    
    if (price_arr[i]==price){
        cout << "New price " << price << " is appended." << endl;
    }
    else{
        cout << "Full list." << endl;
    }
    
    return price_arr;
}

void swap_todo(int *price_list, int a, int b){
    int* ptr1;
    int* ptr2;
    ptr1 = &price_list[a];
    ptr2 = &price_list[b];

    cout << a <<"-th price is " << *ptr1 << "\n" << b << "-th price is " << *ptr2 <<endl;
    
    int reserve = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = reserve;
    
    cout << a <<"-th price is " << *ptr1 << "\n" << b << "-th price is " << *ptr2 <<endl;
}

int main(){
    int* price_list;
    int user_input;
    cout << "To make new price, press 1 \n To chage the order of prices, press 2, \n Nothing to do, press 3." << endl;
    cout << "Input: ";
    cin >> user_input;

    switch (user_input)
        {
        case 1:
            int price;
            cout << "What is the new price?: " << endl;
            cin >> price;
            price_list = new_list(price);
            break;

        case 2:
            int price1;
            int price2;
            
            cout << "Move the price from : " <<endl;
            cin >> price1;
            cout << "Move the price to : " <<endl;
            cin >> price2;
            swap_todo(price_list, price1, price2);
            break;
        
        case 3: 
            cout << "--------------" << endl;
        default:
            break;
        }
                
}    

