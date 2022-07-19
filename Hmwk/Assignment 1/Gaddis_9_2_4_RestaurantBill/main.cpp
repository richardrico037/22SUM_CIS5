/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 30, 2022, 1:20 PM
 * Purpose: Problem 4 from Gaddis Chapter 2
 */

//System Libraries
#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    
    float Cost = 88.67, Tax = .0675, Tip = .2, Total;
    
    Tax *= Cost;
    Tip *= (Tax + Cost);
    cout << "Cost: " << Cost << endl; 
    cout << "Tax: " << Tax << endl;
    cout << "Tip: " << Tip << endl;        
    Total = Cost + Tax + Tip;
    cout << "Total: " << Total << endl;
    
    return 0;
}



