/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 30, 2022, 1:20 PM
 * Purpose: Problem 5 from Gaddis Chapter 2
 */

//System Libraries
#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    
    int x = 28, y = 32, z = 37, v = 24, n = 33;
    float sum, avg;
    
    sum = x + y + z + v + n;
    avg = sum/5;
    cout << "Average: " << avg << endl;        
    return 0;
}



