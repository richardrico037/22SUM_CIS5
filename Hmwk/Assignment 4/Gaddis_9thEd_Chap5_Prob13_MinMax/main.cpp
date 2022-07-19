/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 5 Problem 13 Min Max
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
    
    int num = 0, min = 1000, max = 0;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    while (num != -99)
    {
        cin >> num;
        
        if (num == -99)
        {
            break;
        }    
        if (num > max)
        {
            max = num;
        }    
        if (num < min)
        {
            min = num;
        }    
    }
    
    //Display the outputs

    cout << "Smallest number in the series is " << min << endl;
    cout << "Largest  number in the series is " << max;

    //Exit stage right or left!
    return 0;
}