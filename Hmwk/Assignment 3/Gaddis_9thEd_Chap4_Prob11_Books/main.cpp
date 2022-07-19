/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 4 problem 11 Books
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

    int nbooks;

    //Initialize or input i.e. set variable values

    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> nbooks;
    cout << "Books purchased =  " << nbooks << endl;
    
    //Map inputs -> outputs
    
    if (nbooks == 0)
        cout << "Points earned   =  0";
    else if (nbooks == 1)
        cout << "Points earned   =  5";
    else if (nbooks == 2)
        cout << "Points earned   = 15";
    else if (nbooks == 3)
        cout << "Points earned   = 30";
    else if (nbooks >= 4)
        cout << "Points earned   = 60";
    else
        cout << "That's an invalid number of books";
    
    
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}