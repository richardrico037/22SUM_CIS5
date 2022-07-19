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
    
    int x, y, s, p;
    
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    s = x + y;
    p = x * y;
    cout << "sum of x and y: " << s << endl;
    cout << "product of x and y: " << p << endl;
    return 0;
}

