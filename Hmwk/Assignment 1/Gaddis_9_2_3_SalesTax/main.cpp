/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 30, 2022, 1:20 PM
 * Purpose: Problem 3 from Gaddis Chapter 2
 */

//System Libraries
#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    
    int Purchase, State, County;
    float Total;
    
    Purchase = 95;
    State = 4;
    County = 2;
            
    Total = Purchase*State*.01 + Purchase*County*.01;
    cout << "Total Sales Tax: " << Total << endl;
    
    return 0;
}



