/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Savitch 9th Edition Chapter 2 Problem 2 Pay
 */

//System Libraries
#include <iostream> 
#include <iomanip>   //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
    int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const float inc = .076;
    const int month = 12;
    float nsalary, rtropay, asalary, msalary; 
    
    //Initialize or input i.e. set variable values
    
    cout << "Input previous annual salary." << endl;
    cin >> asalary;
    
    //Map inputs -> outputs
    
    nsalary = asalary + asalary * inc;
    rtropay = (nsalary - asalary)/2;
    msalary = nsalary/month;
    
    //Display the outputs
    
    cout << fixed << setprecision(2);
    cout << "Retroactive pay    = $" << setw(7) << rtropay << endl;
    cout << "New annual salary  = $" << setw(3) << nsalary << endl;
    cout << "New monthly salary = $" << setw(7) << msalary;
    
    //Exit stage right or left!
    return 0;
}