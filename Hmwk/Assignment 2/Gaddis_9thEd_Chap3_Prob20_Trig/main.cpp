/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Gaddis 9th Edition Chapter 3 Problem 20 Trig
 */

//System Libraries
#include <iostream>
#include <iomanip>  
#include <cmath>  
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float pi = 3.14159265359f;
//Function Prototypes

float cnvrtRd(float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float angle, anglerad,s, c, t;
    //Initialize or input i.e. set variable values
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    cin >> angle;
    //Map inputs -> outputs
    anglerad = pi * angle /180;
    s = sin(anglerad);
    c = cos(anglerad);
    t = tan(anglerad);
    //Display the outputs
    cout << "sin(" << setprecision(0) << fixed << setw(1) << angle << ") = " << setprecision(4) << fixed << setw(1) << s << endl;
    cout << "cos(" << setprecision(0) << fixed << setw(1) << angle << ") = " << setprecision(4) << fixed << setw(1) << c << endl;
    cout << "tan(" << setprecision(0) << fixed << setw(1) << angle << ") = " << setprecision(4) << fixed << setw(1) << t;
    //Exit stage right or left!
    return 0;
}