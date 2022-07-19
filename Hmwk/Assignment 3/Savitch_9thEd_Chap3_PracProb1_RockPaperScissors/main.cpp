/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Savitch Chapter 3 problem 1 Rock Paper Scissors
 */

//System Libraries
#include <iostream> 
#include <iomanip>   
#include <cstdlib>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    char player1, player2;
    
    //Initialize or input i.e. set variable values
    
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    cin >> player1;
    cin >> player2;
    
    //Map inputs -> outputs
    
    if (player1 == player2)
    {
        cout << "Nobody wins" << endl;
    }
    else if (player1 == 'R' || player1 == 'r')
    {
        if (player2 == 'S' || player2 == 's')
        {
            cout << "Rock breaks scissors.";
        }
        else 
        {
            cout << "Paper covers rock.";
        }
    }
    else if (player1 == 'S' || player1 == 's')
    {
        if (player2 == 'R' || player2 == 'r')
        {
            cout << "Rock breaks scissors.";
        }
        else 
        {
            cout << "Scissors cuts paper.";
        }
    }
    else 
    {
        if (player2 == 'S' || player2 == 's')
        {
            cout << "Scissors cuts paper.";
        }
        else 
        {
            cout << "Paper covers rock.";
        }
    }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}