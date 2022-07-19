/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Gaddis Chapter 4 problem 8 sort names
 */

//System Libraries
#include <iostream>
#include <iomanip>              //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    string name1, name2, name3;
    
    //Initialize or input i.e. set variable values
    
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    cin >> name1;
    cin >> name2;
    cin >> name3;
    
    //Map inputs -> outputs
    
    if(name1<name2 && name1<name3)
    {
        cout << name1 << endl;
        if (name2<name3)
        {
            cout << name2 << endl;
            cout << name3;
        }
        else
        {
            cout << name3 << endl;
            cout << name2;
        }
    }
    else if(name2<name1 && name2<name3)
    {
        cout << name2 << endl;
        if (name1<name3)
        {
            cout << name1 << endl;
            cout << name3;
        }
        else
        {
            cout << name3 << endl;
            cout << name1;
        }
    }
    else if(name3<name1 && name3<name2)
    {
        cout << name3 << endl;
        if (name1<name2)
        {
            cout << name1 << endl;
            cout << name2;
        }
        else
        {
            cout << name2 << endl;
            cout << name1;
        }
    }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}