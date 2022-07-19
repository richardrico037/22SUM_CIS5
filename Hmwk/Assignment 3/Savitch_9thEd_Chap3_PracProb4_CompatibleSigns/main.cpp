/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 3 problem 4 Compatible Signs
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
    
    string input1, input2;
    
    //Initialize or input i.e. set variable values
    
    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;
    cin >> input1;
    cin >> input2;
    
    //Map inputs -> outputs
    
    if (input1 == "Aries" || input1 == "Leo" || input1 == "Sagittarius")
    {
        if (input2 == "Aries" || input2 == "Leo" || input2 == "Sagittarius")
        {
            cout << input1 << " and " << input2 << " are compatible Fire signs.";
        }
        else
        {
            cout << input1 << " and " << input2 << " are not compatible signs.";
        }
    }
    
    else if  (input1 == "Taurus" || input1 == "Virgo" || input1 == "Capricorn")
    {
        if (input2 == "Taurus" || input2 == "Virgo" || input2 == "Capricorn")
        {
            cout << input1 << " and " << input2 << " are compatible Earth signs.";
        }
        else
        {
            cout << input1 << " and " << input2 << " are not compatible signs.";
        }
    }
    
    else if  (input1 == "Gemini" || input1 == "Libra" || input1 == "Aquarius")
    {
        if (input2 == "Gemini" || input2 == "Libra" || input2 == "Aquarius")
        {
            cout << input1 << " and " << input2 << " are compatible Air signs.";
        }
        else
        {
            cout << input1 << " and " << input2 << " are not compatible signs.";
        }
    }
    
    else if  (input1 == "Cancer" || input1 == "Scorpio" || input1 == "Pisces")
    {
        if (input2 == "Cancer" || input2 == "Scorpio" || input2 == "Pisces")
        {
            cout << input1 << " and " << input2 << " are compatible Water signs.";
        }
        else
        {
            cout << input1 << " and " << input2 << " are not compatible signs.";
        }
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}