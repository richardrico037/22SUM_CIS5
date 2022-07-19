/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Gaddis 9th Edition Chapter 3 Problem 3 Average 
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
    int x, y, z, v, n;
    float sum, avg;
    //Initialize or input i.e. set variable values
    cout << "Input 5 numbers to average." << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    cin >> v;
    cin >> n;
    //Map inputs -> outputs
    sum = x + y + z + v + n;
    avg = sum/5;
    //Display the outp
    cout << "The average = " << setprecision(1) << fixed << setw(1) << avg;
    //Exit stage right or left!
    return 0;
}