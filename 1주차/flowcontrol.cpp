// flow control (conditional statement)
// input & output (cin, cout)

#include <stdio.h>
#include <iostream>
using namespace std;

void make_ten(int n);
void is_(int n);

int main() {
 int a;

 cout << "Your number is: ";
 cin >> a;

 if (( a == 100) or (a == 0)) {
   is_(a);
 }
 else if (a<10) {
   cout << "Your number is smaller than 10." << endl;
   cout << "Let's make 10." << endl;
   make_ten(a);
 }
 else if (a > 10) {
   cout << "Your number is greater than 10." << endl;
   cout << "Let's make 10." << endl;
   make_ten(a);
 }
 else {
   cout << "a is 10." << endl;
 }
 return EXIT_SUCCESS;
}

void make_ten(int n){
  while (true) {
    if (n == 10) {
      cout << "Finally it's 10.";
      break;
    }
    else if (n < 10) {
     cout << n << " + 1 = " << n+1 << endl;
     n ++ ;
    }
    else {
     cout << n << " - 1 = " << n -1 << endl;
     n --;
    }
  }
}

void is_(int n) {
  switch (n) {
   case 100:{
    cout << n << " is my favorite number." << endl;
    cout << "There's no need to make 10." << endl;
    break;
    }
   case 0:{
    cout << n << " is special." << endl;
    cout << "There's no need to make 10." << endl;
    break;
    } 
  }
}


