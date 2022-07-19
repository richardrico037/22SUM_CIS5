/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Savitch Chapter 4 Problem 4 Inflation
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
    
    float price1, price2, rate;
    char ans = 'y';
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout << fixed << setprecision(2);
    
    while (ans == 'y')
    {
        cout << "Enter current price:" << endl;
        cin >> price1;
        cout << "Enter year-ago price:" << endl;
        cin >> price2;
        rate = ((price1 - price2)/price2) * 100;
        cout << "Inflation rate: " << rate << "%" << endl << endl;
        cout << "Again:" << endl;
        cin >> ans;
        if (ans == 'y')
        {
            cout << endl;
        }
        
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}