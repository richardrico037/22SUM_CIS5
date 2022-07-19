/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 5 Problem 7 Pay In Pennies
 */
//System Libraries
#include <iostream> 
#include <iomanip>      //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    int num = 1, days;
    double pay = 0.01, total = 0;
    
    //Initialize or input i.e. set variable values
    
    cin >> days;
    
    //Map inputs -> outputs
    
       while (num <= days)
    {
        total += pay;
        pay *= 2;
        num++;
    }
 
    //Display the outputs

    cout << fixed << setprecision(2);
    cout << "Pay = $" << total;

    //Exit stage right or left!
    return 0;
}