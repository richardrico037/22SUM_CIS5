/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on July 24, 2022, 1:00 AM
 * Purpose: Project 1
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

     srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
     
    char startn, rulen, rolln, rerolln, betltr, betltr2, die1, die2, die3, die4;
    float money = 100, bet, bet2;
    int gme, ngmes = 1000, win, lose, point, sumdie, sumdie2;
    bool WorL;
    
    //Initialize Variables
    
    cout << "CRAPS" << endl;
    cout << "1. PLAY" << endl;
    cout << "2. HOW TO PLAY" << endl;
    cout << "3. QUIT" << endl;
    cin >> startn;
    
    //Map inputs to outputs -> The Process
    
    if (startn == '1')      //PLAY GAME
    {
        for (gme = 1; gme < ngmes; gme++)
        {
            cout << "Type P to bet on pass line or Type D for don't pass line" << endl;
            cin >> betltr;
            
            if (betltr == 'P' || betltr == 'p')       //PASS LINE BET
            {
                cout << "How much do you want bet" << endl;
                cin >> bet;
                money -= bet;
                cout << "Type R to roll" << endl;
                cin >> rolln;
                if (rolln == 'R' || rolln == 'r')   //COMEOUT ROLL
                {
                    die1 = rand()%6+1;              //DICE ROLL
                    die2 = rand()%6+1;
                    sumdie = die1 + die2;
                    if (sumdie == 7 || sumdie == 11)        //WIN
                    {
                        cout << "WIN" << endl;
                        cout << "SUM OF DICE = " << sumdie << endl;
                        money += (2 * bet);
                        cout << "MONEY LEFT = " << money << endl;
                        win++;
                    }
                    else if (sumdie == 2 || sumdie == 3 || sumdie == 12)       //LOSE
                    {
                        cout << "LOSE" << endl;
                        cout << "SUM OF DICE = " << sumdie << endl;
                        cout << "MONEY LEFT = " << money << endl;
                        lose++;
                    }
                    else                    //ESTABLISH POINT
                    {
                        cout << "POINT" << endl;
                        cout << "SUM OF DICE = " << sumdie << endl;
                        cout << "MONEY LEFT = " << money << endl;
                        sumdie = point;
                        cout << "Type 7 to bet on rolling a 7 first or Type P to bet on rolling the point first" << endl;
                        cin >> betltr2;
                        
                        if (betltr2 == 'P' || betltr2 == 'p')       //PASS LINE BET
                        {
                            cout << "How much do you want bet" << endl;
                            cin >> bet2;
                            money -= bet2;
                            do 
                            {
                                WorL = true;
                                die3 = rand()%6+1;              //DICE ROLL
                                die4 = rand()%6+1;
                                sumdie2 = die3 + die4;
                                if (sumdie == 7)
                                {
                                    cout << "LOSE" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    cout << "MONEY LEFT = " << money << endl;
                                    lose++;
                                    WorL = false;
                                }
                                else if (sumdie2 == sumdie)
                                {
                                    cout << "WIN" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    money += (2 * bet2);
                                    cout << "MONEY LEFT = " << money << endl;
                                    win++;
                                    WorL = false;
                                }
                            }
                            while (WorL);
                        }    
                        
                        else 
                        {
                            cout << "How much do you want bet" << endl;
                            cin >> bet2;
                            money -= bet2;
                            do 
                            {
                                WorL = true;
                                die3 = rand()%6+1;              //DICE ROLL
                                die4 = rand()%6+1;
                                sumdie2 = die3 + die4;
                                if (sumdie == 7)
                                {
                                    cout << "WIN" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    money += (2 * bet2);
                                    cout << "MONEY LEFT = " << money << endl;
                                    win++;
                                    WorL = false;
                                }
                                else if (sumdie2 == sumdie)
                                {
                                    cout << "LOSE" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    cout << "MONEY LEFT = " << money << endl;
                                    lose++;
                                    WorL = false;
                                }
                            }
                            while (WorL);
                        }    
                    }
                }    
            }
            
            else if (betltr == 'D' || betltr == 'd')     
            {
                cout << "How much do you want bet" << endl;
                cin >> bet;
                money -= bet;
                cout << "Type R to roll" << endl;
                cin >> rolln;
                if (rolln == 'R' || rolln == 'r')   //COMEOUT ROLL
                {
                    die1 = rand()%6+1;              //DICE ROLL
                    die2 = rand()%6+1;
                    sumdie = die1 + die2;
                    if (sumdie == 7 || sumdie == 11)        //WIN
                    {
                        cout << "LOSE" << endl;
                        cout << "SUM OF DICE = " << sumdie << endl;
                        cout << "MONEY LEFT = " << money << endl;
                        lose++;
                    }
                    else if (sumdie == 2 || sumdie == 3 || sumdie == 12)       //LOSE
                    {
                        cout << "WIN" << endl;
                        cout << "SUM OF DICE = " << sumdie << endl;
                        money += (2 * bet);
                        cout << "MONEY LEFT = " << money << endl;
                        win++;
                    }
                    else                    //ESTABLISH POINT
                    {
                        cout << "POINT" << endl;
                        cout << "SUM OF DICE = " << sumdie << endl;
                        cout << "MONEY LEFT = " << money << endl;
                        point = sumdie;
                        cout << "Type 7 to bet on rolling a 7 first or Type P to bet on rolling the point first" << endl;
                        cin >> betltr2;
                        
                        if (betltr2 == 'P' || betltr2 == 'p')       //PASS LINE BET
                        {
                            cout << "How much do you want bet" << endl;
                            cin >> bet2;
                            money -= bet2;
                            do 
                            {
                                WorL = true;
                                die3 = rand()%6+1;              //DICE ROLL
                                die4 = rand()%6+1;
                                sumdie2 = die3 + die4;
                                if (sumdie == 7)
                                {
                                    cout << "LOSE" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    cout << "MONEY LEFT = " << money << endl;
                                    lose++;
                                    WorL = false;
                                }
                                else if (sumdie2 == sumdie)
                                {
                                    cout << "WIN" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    money += (2 * bet2);
                                    cout << "MONEY LEFT = " << money << endl;
                                    win++;
                                    WorL = false;
                                }
                            }
                            while (WorL);
                        }    
                        
                        else 
                        {
                            cout << "How much do you want bet" << endl;
                            cin >> bet2;
                            money -= bet2;
                            do 
                            {
                                WorL = true;
                                die3 = rand()%6+1;              //DICE ROLL
                                die4 = rand()%6+1;
                                sumdie2 = die3 + die4;
                                if (sumdie == 7)
                                {
                                    cout << "WIN" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    money += (2 * bet2);
                                    cout << "MONEY LEFT = " << money << endl;
                                    win++;
                                    WorL = false;
                                }
                                else if (sumdie2 == sumdie)
                                {
                                    cout << "LOSE" << endl;
                                    cout << "SUM OF DICE = " << sumdie << endl;
                                    cout << "MONEY LEFT = " << money << endl;
                                    lose++;
                                    WorL = false;
                                }
                            }
                            while (WorL);
                        }    
                    }    
                }  
            }
        }
    }    
    else if (startn == '2')         //RULES 
    {
        cout << "HOW TO PLAY" << endl;
        cout << "RULES" << endl;
        cout << "1. All craps games begin with a pass line bet. (Players start off with $100)" << endl;
        cout << "A craps player must choose whether they think the dice will land on a combined 7 or 11 to win ('pass the line') or lose by landing on a 2, 3 or 12." << endl;
        cout << "2. The base dealers take all pass bets and add them to the craps table." << endl;
        cout << "3. The shooter starts the craps game with the first roll of the dice, known as the comeout roll." << endl;
        cout << "4.If the dice land on 7 or 11, pass line bettors win their wager." << endl;
        cout << "Alternately, if the dice land on a combined 2, 3 or 12, don't pass bettors win." << endl;
        cout << "Any other numbers the dice land on establishes a 'point' on the craps table, and the game continues." << endl;
        cout << "5. Once a point (4, 5, 6, 7, 8, 9, 10) is set on the craps table," << endl;
        cout << "craps players can bet on the dice landing the point or landing on 7." << endl;
        cout << "6. The shooter rolls the dice until they land a 7 or the point." << endl;
        cout << "1. PLAY" << endl;
        cout << "3. QUIT" << endl;

        cin >> rulen;
        
        if (rulen == '1')
        {
            
        }
        else        //QUIT GAME
        {
            return 0;
        }    
    }  
    else    //QUIT GAME
    {
        return 0;
    }
    
    //Display Results
    cout << "Thanks for playing!" << endl;
    cout << "Games Lost = " << lose << endl;
    cout << "Games Won = " << win << endl;
    if (money > 100)        //EARNINGS
    {
        cout << "Money Won = " << (money - 100);
    }
    else                    //LOSSES 
    {
        cout << "Money Lost = " << (100 - money);
    }
    
    
    //Exit stage right
    return 0;
}

