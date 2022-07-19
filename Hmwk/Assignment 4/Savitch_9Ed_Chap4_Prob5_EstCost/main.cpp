/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Savitch Chapter 4 Problem 5 Estimated Cost
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
    
    float price1, price2, price1y, price2y, rate, perrate;
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
        rate = ((price1 - price2)/price2);
        perrate = rate * 100;
        cout << "Inflation rate: " << perrate << "%" << endl << endl;
        
        price1y = price1 * (1+rate);
        price2y = price1y * (1+rate);
        
        cout << "Price in one year: $" << price1y << endl;
        cout << "Price in two year: $" << price2y << endl << endl;
        
        
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