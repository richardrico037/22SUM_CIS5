/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Gaddis 9th Edition Chapter 3 Problem 7 Cookies
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
    float f, c;
    //Initialize or input i.e. set variable values
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;
    cin >> f;
    //Map inputs -> outputs
    c = 5 * (f-32) / 9;
    //Display the outputs
    cout << "" << setprecision(1) << fixed << setw(1) << f << " Degrees Fahrenheit = " << setprecision(1) << fixed << setw(1) << c << " Degrees Centigrade"; 
    //Exit stage right or left!
    return 0;
}