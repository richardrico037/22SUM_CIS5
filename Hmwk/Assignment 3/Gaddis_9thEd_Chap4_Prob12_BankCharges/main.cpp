/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 4 problem 12 Bank Charges
 */

//System Libraries
#include <iostream>  
#include <iomanip>//Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    int chk;
    float chkfee, montfee = 10, lbalfee, bal, newbal;
    
    //Initialize or input i.e. set variable values
    
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    cin >> bal;
    cin >> chk;
    
    //Map inputs -> outputs
    
    {
        if (chk < 20)
            chkfee = 0.10 * chk;
        else if (chk >= 20 && chk < 40)
            chkfee = 0.08 * chk;
        else if (chk >= 40 && chk < 60)
            chkfee = 0.06 * chk;
        else chkfee = 0.04 * chk;
    }
    
    {
        if (bal < 400)
            lbalfee = 15;
        else lbalfee = 0;
    }
    
    newbal = bal - chkfee - montfee - lbalfee;    
    //Display the outputs

    cout << fixed << setprecision(2);
    cout << "Balance     $" << setw(9) << right << bal << endl;
    cout << "Check Fee   $" << setw(9) << right << chkfee << endl;
    cout << "Monthly Fee $" << setw(9) << right << montfee << endl;
    cout << "Low Balance $" << setw(9) << right << lbalfee << endl;
    cout << "New Balance $" << setw(9) << right << newbal;
    
    //Exit stage right or left!
    return 0;
}