/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on July 8, 2022, 2:00 PM
 * Purpose: Lab Exercise 3
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float cost, gross, mod, tax;                     //user input/output 
    float exc = .39, cap = .10, fed = .184;          // flat tax 
    float prof = .065, sales = .08, ptax, pprof;     //percent tax and profit
    
   //user input
   cout << "Input cost of a gallon of gas." << endl; 
   cin >> cost;
   
   //calculations
   mod = cost - exc - cap - fed;
   sales *= mod; 
   mod -= sales;
   gross = mod * prof;
   tax = sales + exc + cap + fed;
   ptax = (tax/cost) * 100;
   pprof = (gross/cost) * 100;
   
   //output
   cout << setprecision(2) << fixed;
   cout << "Dollar amount Tax: $" << tax << endl;
   cout << "Dollar amount Profit: $" << gross << endl;
   cout << "Percentage Amount Tax: " << ptax << "%" << endl;
   cout << "Percentage Amount Profit: " << pprof << "%";
     
    return 0;
}

