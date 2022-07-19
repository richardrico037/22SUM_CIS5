/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Savitch Chapter 4 Problem 9 2 or 3 Max
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
    
    float num1, num2, num3, num12;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    cout << "Enter first number:" << endl << endl;
    cin >> num1;
    cout << "Enter Second number:" << endl << endl;
    cin >> num2;
    cout << "Enter third number:" << endl << endl;
    cin >> num3;
    
    cout << "Largest number from two parameter function:" << endl;
    if (num1 > num2)
    {
        cout << num1 << endl << endl;
        num12 = num1;
    }
    else 
    {
        cout << num2 << endl << endl;
        num12 = num2;
    }
    
    cout << "Largest number from three parameter function:" << endl;
    if (num12 > num3)
    {
        cout << num12 << endl;
    }
    else 
    {
        cout << num3 << endl;
    }
    
    
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}