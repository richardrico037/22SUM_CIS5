/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on July 24, 2022, 1:00 AM
 * Purpose: Project 1
 */

// ConsoleApplication85.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::setprecision;
using std::fixed;

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(NULL)));

    //Declare Variables/Initialize Variables
    char betltr, die1, die2, rolln, cont = 'y';
    float money, bet;
    int  point, sumdie, win = 0, lose = 0, startn;
    bool menu = true;
    bool hard;
    enum Status { POINT, PASS, NOPASS, NPOINT };
    Status game;

    do
    {
        //Read Main Menu from txt file
        fstream main_t;
        main_t.open("C:/Users/Roux Ben/Desktop/Craps.txt", std::ios::in);
        if (main_t.is_open())
        {
            string line;
            while (std::getline(main_t, line))
            {
                cout << line << endl;
            }
            main_t.close();
        }
        //User Input to output selection
        cin >> startn;
        switch (startn)
        {
            //Start the Game
        case 1:
            system("CLS");
            cout << "EASY MODE" << endl << endl;
            money = 1000.00;
            menu = false;
            hard = false;
            break;
            //Rules read from text file
        case 2:
        {
            system("CLS");
            fstream rules;
            rules.open("C:/Users/Roux Ben/Desktop/Rules.txt", std::ios::in);
            if (rules.is_open())
            {
                string line;
                while (std::getline(rules, line))
                {
                    cout << line << endl;
                }
                rules.close();
                system("pause");
            }
            system("CLS");
            break;
        }
        //Quit Game
        case 3:
            return 0;
        }
    } while (menu);
    //PLAY GAME
    do
    {
        cout << "MONEY = $" << money << endl;
        cout << "Type P to bet on pass line or Type D for don't pass line" << endl;
        cin >> betltr;
        bet = 0;
        for (int i = 0; bet > money || bet <= 0; i++)
        {
            cout << "How much do you want bet?" << endl;
            cin >> bet;
            if (bet > money)
            {
                cout << "NOT ENOUGH MONEY" << endl;
            }
            else if (bet <= 0)
            {
                cout << "INVALID BET" << endl;
            }
            if (i > 0 && (bet < money && bet > 0))
            {
                cout << "BET INCORRECTLY " << i << " TIMES" << endl << endl;
            }
        }
        money -= bet;
        cout << "TYPE R TO ROLL" << endl;
        cin >> rolln;
        if (rolln == 'r' || rolln == 'R')
        {
            die1 = rand() % 6 + 1;              //DICE ROLL
            die2 = rand() % 6 + 1;
            sumdie = die1 + die2;
            cout << "SUM OF DICE = " << sumdie << endl;
        }
        else
        {
            cout << "INVAILD INPUT";
            return 0;
        }
        //Interpret Dice Roll as Pass the line, not Pass The Line, or assign point
            switch (sumdie)     
            {
            case 2:
            case 3:
            case 12:
                game = NOPASS;
                cout << "DID NOT PASS THE LINE" << endl;
                break;
            case 7:
            case 11:
                game = PASS;
                cout << "PASS THE LINE" << endl;
                break;
            default:
                game = POINT;
                point = sumdie;
                cout << "POINT = " << point << endl;
                break;
            }
            while (game == POINT)
            {
                cout << "TYPE R TO ROLL" << endl;
                cin >> rolln;
                if (rolln == 'r' || rolln == 'R')
                {
                    die1 = rand() % 6 + 1;              //DICE ROLL
                    die2 = rand() % 6 + 1;
                    sumdie = die1 + die2;
                    cout << "SUM OF DICE = " << sumdie << endl;
                }
                else
                {
                    cout << "INVAILD INPUT";
                    return 0;
                }
                //Test Case sum of dice is equal to point
                if (sumdie == point)            
                {
                    money += (2.0 * bet);
                    cout << "YOU WIN" << endl;
                    cout << "MONEY WON = " << 2.0 * bet << endl;
                    win++;
                    game = NPOINT;
                }
                else if (sumdie == 7)
                {
                    cout << "YOU LOSE" << endl;
                    cout << "MONEY LOST = " << bet << endl;
                    lose++;
                    game = NPOINT;
                }
            }
            //Did not pass the line and bet on outcome
            if (game == NOPASS && (betltr == 'D' || betltr == 'd'))         
            {
                money += (2.0 * bet);
                cout << "YOU WIN" << endl;
                cout << "MONEY WON = " << 2.0 * bet << endl;
                win++;
            }
            //Pass the line and bet on outcome
            else if (game == PASS && (betltr == 'P' || betltr == 'p'))     
            {
                money += (2.0 * bet);
                cout << "YOU WIN" << endl;
                cout << "MONEY WON = " << 2.0 * bet << endl;
                win++;
            }
            //Outcome bet on did not occur
            else if (game == PASS || game == NOPASS)            
            {
                cout << "YOU LOSE" << endl;
                cout << "MONEY LOST = " << bet << endl;
                lose++;
            }
            //User input to end or continue game
            cout << endl << "CONTINUE?(y/n)" << endl;
            cin >> cont;
            system("CLS");
    } while (money > 0 && (cont == 'y' || cont == 'Y'));
    //Display Results
        cout << "THANKS FOR PLAYING!" << endl;
        cout << "GAMES LOST = " << lose << endl;
        cout << "GAMES WON = " << win << endl;

        if (money > 100)        //EARNINGS
        {
            cout << "MONEY WON = $" << fixed << setprecision(2) << (money - 1000);
        }
        else if (money < 100)              //LOSSES 
        {
            cout << "MONEY LOST = $" << fixed << setprecision(2) << (1000 - money);
        }
        else
        {
            cout << "BREAK EVEN" << endl;
            cout << "MONEY = $" << fixed << setprecision(2) << money;
        }
        //Exit stage right
        return 0;
}
