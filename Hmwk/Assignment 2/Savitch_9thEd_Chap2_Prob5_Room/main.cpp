/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Savitch 9th Edition Chapter 2 Problem 5 Room
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
   int cap = 0, ppl = 0;
    
    //Initialize or input i.e. set variable values
    
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> cap >> ppl;
    
    //Map inputs -> outputs
    
    //Display the outputs

    if (ppl > cap)  {
        cout << "Meeting cannot be held." << endl;
        cout << "Reduce number of people by " << (ppl - cap) << " to avoid fire violation.";
    }
    
    else if (ppl <= cap) {
        cout << "Meeting can be held." << endl;
        cout << "Increase number of people by " << (cap - ppl) << " will be allowed without violation.";
    }
    
    //Exit stage right or left!
    return 0;
}