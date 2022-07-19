/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Paycheck
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
    float payrate, hours, grosspay;
    //Initialize or input i.e. set variable values
    cout << "This program calculates the gross paycheck." << endl;
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;
    cin >> payrate;
    cin >> hours;
    //Map inputs -> outputs
    
    grosspay = payrate * hours;
    grosspay += hours > 40?payrate * (hours-40):0;
    
    //Display the outputs
    
    cout << fixed << setprecision(2) << showpoint;
    cout << "Paycheck = $" << setw(7) << grosspay;
     
    //Exit stage right or left!
    return 0;
}