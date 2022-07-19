/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 3 problem 3 Roman Conversions
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
    
    int num, anum; 
    string roman [4];
    int digit [4];
    
    //Initialize or input i.e. set variable values
    
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;
    cin >> num;
    anum = num;
    
    //Map inputs -> outputs
    
    if (num < 1000 || num > 3000)
    {
        cout << num << " is Out of Range!";
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            digit [i] = num % 10;
            num /= 10;
        }
        switch(digit [0]) 
        {
            case 0: 
            break;
            case 1:
            roman [3] = "I";
            break;
            case 2:
            roman [3] = "II";
            break;
            case 3:
            roman [3] = "III";
            break;
            case 4:
            roman [3] = "IV";
            break;
            case 5:
            roman [3] = "V";
            break;
            case 6:
            roman [3] = "VI";
            break;
            case 7:
            roman [3] = "VII";
            break;
            case 8:
            roman [3] = "VIII";
            break;
            case 9:
            roman [3] = "IX";
            break;
        }
        switch(digit [1])
        {
            case 0: 
            break;
            case 1:
            roman [2] = "X";
            break;
            case 2:
            roman [2] = "XX";
            break;
            case 3:
            roman [2] = "XXX";
            break;
            case 4:
            roman [2] = "XL";
            break;
            case 5:
            roman [2] = "L";
            break;
            case 6:
            roman [2] = "LX";
            break;
            case 7:
            roman [2] = "LXX";
            break;
            case 8:
            roman [2] = "LXXX";
            break;
            case 9:
            roman [2] = "XC";
            break;
        }
        switch(digit [2])
        {
            case 0: 
            break;
            case 1:
            roman [1] = "C";
            break;
            case 2:
            roman [1] = "CC";
            break;
            case 3:
            roman [1] = "CCC";
            break;
            case 4:
            roman [1] = "CD";
            break;
            case 5:
            roman [1] = "D";
            break;
            case 6:
            roman [1] = "DC";
            break;
            case 7:
            roman [1] = "DCC";
            break;
            case 8:
            roman [1] = "DCCC";
            break;
            case 9:
            roman [1] = "CM";
            break;
        }
        switch(digit [3])
        {
            case 0: 
            break;
            case 1:
            roman [0] = "M";
            break;
            case 2:
            roman [0] = "MM";
            break;
            case 3:
            roman [0] = "MMM";
            break;
        }
        
        cout << anum << " is equal to "; 
        for(int i = 0; i < 4; i++)
        {
            cout << roman [i];
        }
    }
    //Display the outputs
    
    //Exit stage right or left!
    return 0;
}