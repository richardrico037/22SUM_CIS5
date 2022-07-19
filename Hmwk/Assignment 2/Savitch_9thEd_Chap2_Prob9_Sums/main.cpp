/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Savitch 9th Edition Chapter 2 Problem 9 Sums
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
   int num = 0, count = 0, psum = 0, nsum = 0, pcount = 0, ncount = 0, total;
    
    //Initialize or input i.e. set variable values
    
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    
    for (int i=0; i < 10; i++)
    
    {
        cin >> num;
    if (num  >= 0)    
    {
        psum += num;
        pcount++;
    }
    else 
    {
        nsum += num;
        ncount++;
    }
    }
    //Map inputs -> outputs
    
    total = nsum + psum;
    
    //Display the outputs

    cout << fixed;
    cout << "Negative sum =" << setw(4) << nsum << endl;
    cout << "Positive sum =" << setw(4) << psum << endl;
    cout << "Total sum    =" << setw(4) << total;
    
    
    //Exit stage right or left!
    return 0;
}