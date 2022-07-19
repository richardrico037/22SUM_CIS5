/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Gaddis 9th Edition Chapter 3 Problem 8 Insurance
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
    int weight, soda;
    
    //Initialize or input i.e. set variable values
    
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;
    cin >> weight;
    
    //Map inputs -> outputs
    
    soda = ( (weight *  453.592) * (.14285714285)) /.35;
    
    //Display the outputs
    
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << soda << " cans";
    
    //Exit stage right or left!
    return 0;
}