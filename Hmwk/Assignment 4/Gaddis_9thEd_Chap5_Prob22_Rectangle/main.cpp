/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 5 Problem 22 Rectangle
 */

//System Libraries
#include <iostream>
#include <string>
#include <sstream>          //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    int num;
    char lttr;

    //Initialize or input i.e. set variable values
    
    cin >> num >> lttr;
    
    //Map inputs -> outputs
    
    for (int j = 0; j < num; j++)
    {
        for (int i = 0; i < num; i++)
        {
            cout << lttr;
        }
        if (j < num - 1)
        {
            cout << endl;
        }
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}