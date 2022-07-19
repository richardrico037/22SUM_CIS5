/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 5 Problem 1 Sum
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    int sum = 0, num;
    
    //Initialize or input i.e. set variable values
    
    cin >> num;
   
    //Map inputs -> outputs
    
       for (int i = 1; i <= num; ++i)
    {
        sum += i; 
    }
    
    //Display the outputs

    cout << "Sum = " << sum; 

    //Exit stage right or left!
    return 0;
}