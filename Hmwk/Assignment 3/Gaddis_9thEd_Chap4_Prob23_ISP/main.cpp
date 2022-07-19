/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 4 problem 23 ISP
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
    
    string pkg;
    float price, t;
    
    //Initialize or input i.e. set variable values
    
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    cin >> pkg;
    
    
    //Map inputs -> outputs
    
    if ((pkg == "A") || (pkg == "B") || (pkg == "C")) 
    {
     cin >> t;
     
    if (t <= 744)
        {
            if (pkg == "A")
            {
                if (t > 10)
                {
                    price = 9.95 + (t - 10) *2;
                }
                else 
                {
                    price = 9.95;
                }
            }
            else if (pkg == "B")
            {
                if (t > 20)
                {
                    price = 14.95 + (t - 20);
                }
                else 
                {
                    price = 14.95;
                }
            }
            else 
            {
                price = 19.95;
            }
        }
    }    
    //Display the outputs
    cout << "Bill = $ " << price;
    //Exit stage right or left!
    return 0;
}