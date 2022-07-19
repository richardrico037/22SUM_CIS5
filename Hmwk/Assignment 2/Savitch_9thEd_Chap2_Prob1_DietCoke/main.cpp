/* 
 * File:   main.cpp
 * Author: Richard Rico 
 * Created on July 6, 2022, 12:36 PM
 * Purpose:  Savitch 9th Edition Chapter 2 Problem 1 Diet Coke
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
    float replacement_cost, min_insurance;
    //Initialize or input i.e. set variable values
    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;
    cin >> replacement_cost;
    //Map inputs -> outputs
    min_insurance = replacement_cost * .8;
    //Display the outputs
    cout << "You need $" << min_insurance << " of insurance.";
    //Exit stage right or left!
    return 0;
}