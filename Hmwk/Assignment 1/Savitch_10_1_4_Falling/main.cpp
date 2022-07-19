/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: C++ Template - To be used in all future Assignments
 */

//System Libraries
#include <iostream>

int main() {
    using std::cin; 
    using std::cout;
    using std::endl;
  
    int t, prod, d; 
    int g = 32;
    cout << "time= ";
    cin >> t;
    prod = g * t * t;
    d = prod/2;
    cout << "distance = " << d << endl;
    return 0;
}

