/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Savitch Chapter 4 Problem 2 Fuel Efficiency
 */

//System Libraries
#include <iostream>
#include <iomanip>          //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    float liters1, miles1, gals1, mpg1, liters2, miles2, gals2, mpg2; 
    char ans = 'y';
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs.
    
    cout << fixed << setprecision(2);
    
    while (ans == 'y')
    {
        cout << "Car 1" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters1;
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles1;
        gals1 = liters1 * 0.264179;
        mpg1 = miles1 / gals1;
        cout << "miles per gallon: " << mpg1 << endl << endl;
       
        cout << "Car 2" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters2;
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles2;
        gals2 = liters2 * 0.264179;
        mpg2 = miles2 / gals2;
        cout << "miles per gallon: " << mpg2 << endl << endl;
        
        if (mpg1 > mpg2)
        {
            cout << "Car 1 is more fuel efficient" << endl << endl;
        }
        else 
        {
            cout << "Car 2 is more fuel efficient" << endl << endl;
        }
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