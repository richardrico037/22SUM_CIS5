/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 5 Problem 23 Pattern
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
    
    char wave = '+';
    int num;     
    
    //Initialize or input i.e. set variable values
    
    cin >> num;
    
    //Map inputs -> outputs
    
       for (int j = 0; j < num; j++)
    {
        for (int i = 0; i <= j; i++)
        {
            cout << wave;
        }
        cout << endl << endl;
    }
    
       for (int j = num + 1; j > 0; j--)
    {
        for (int i = 1; i < j; i++)
        {
            cout << wave;
        }
            if (j > 2)
        {
            cout << endl << endl;
        }
        cin >> num;
    }
    //Display the outputs
   
        
    //Exit stage right or left!
    return 0;
}