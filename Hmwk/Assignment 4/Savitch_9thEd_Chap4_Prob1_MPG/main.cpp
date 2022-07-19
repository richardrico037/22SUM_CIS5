/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Savitch Chapter 4 Problem 1 MPG
 */

//System Libraries
#include <iostream>
#include <iomanip>          //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    float liters, miles, gals, mpg;
    char ans = 'y';
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs.
    cout << fixed << setprecision(2);
    
    while (ans == 'y')
    {
        cout << "Enter number of liters of gasoline:" << endl << endl;
        cin >> liters;
        cout << "Enter number of miles traveled:" << endl << endl;
        cin >> miles;
        gals = liters * 0.264179;
        mpg = miles / gals;
        cout << "miles per gallon:" << endl;
        cout << mpg << endl;
        cout << "Again:" << endl;
        cin >> ans;
        if (ans == 'y')
        {
            cout << endl;
        }
    }
   
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}