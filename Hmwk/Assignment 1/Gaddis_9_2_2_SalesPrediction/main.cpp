/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 30, 2022, 1:00 PM
 * Purpose: Problem 2 from Gaddis Chapter 2
 */

//System Libraries
#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    
    int Percent = 58, Sales = 8600000, Total;
    Total = Percent* .01 * Sales;
    cout << "Total Sales Generated: " << Total << endl;
    
    return 0;
}

