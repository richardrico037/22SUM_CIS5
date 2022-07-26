/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on July 24, 2022, 1:00 AM
 * Purpose: Project 1
 */

// ConsoleApplication85.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 

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
using std::pow;

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(NULL)));

    //Declare Variables/Initialize Variables
    char betltr, die1, die2, rolln, cont = 'y';
    float money, bet, debt, mom;
    int  point, sumdie, win = 0, lose = 0, startn;
    bool menu = true;
    bool hard;
    enum Status { POINT, PASS, NOPASS, NPOINT };
    Status game;

    do
    {
        //Read Main Menu from txt file
        fstream main_t;
        main_t.open("C:/Users/woodc/OneDrive/Desktop/Craps.txt", std::ios::in);
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
            //USER SELECTS EASY MODE
        case 1:
            cout << endl << endl << endl;
            cout << "EASY MODE" << endl << endl;
            money = 1000.00;
            menu = false;
            hard = false;
            break;
            //Rules read from text file
        //USER SELECTS STORY MODE
        case 2:
        {
            cout << endl << endl << endl;
        //PULLS TXT FILE FOR STORY
            fstream story;
            story.open("C:/Users/woodc/OneDrive/Desktop/Story.txt", std::ios::in);
            if (story.is_open())
            {
                string line;
                while (std::getline(story, line))
                {
                    cout << line << endl;
                }
                story.close();
            }
            hard = true;
            mom = 1000;
            money = 1000;
            debt = money;
            cout << endl << endl << endl;
            menu = false;
            break;
        }
        //USER SELECTS RULES
        case 3:
        {
            cout << endl << endl << endl;
            fstream rules;
            rules.open("C:/Users/woodc/OneDrive/Desktop/Rules.txt", std::ios::in);
            if (rules.is_open())
            {
                string line;
                while (std::getline(rules, line))
                {
                    cout << line << endl;
                }
                rules.close();
            }
            cout << endl << endl << endl;
            break;
        }
        //Quit Game
        case 4:
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
        //USER INPUTS BAD BET INPUT
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
        //USSER INPUT ROLL
        cout << "TYPE R TO ROLL" << endl;
        cin >> rolln;
        cout << endl;
        //DICE ROLL
        if (rolln == 'r' || rolln == 'R')
        {
            die1 = rand() % 6 + 1;              
            die2 = rand() % 6 + 1;
            sumdie = die1 + die2;
            cout << "SUM OF DICE = " << sumdie << endl;
        }
        //USER put something else besides r or R
        else
        {
            cout << "INVAILD INPUT";
            return 0;
        }
        //Interpret Dice Roll as Pass the line, not Pass The Line, or assign point
        switch (sumdie)
        {
        //USER GOT 2, 3, or 12
        case 2:
        case 3:
        case 12:
            game = NOPASS;
            cout << "DID NOT PASS THE LINE" << endl;
            break;
        //USER GOT 7 or 11
        case 7:
        case 11:
            game = PASS;
            cout << "PASS THE LINE" << endl;
            break;
        //USER GOT other number
        default:
            game = POINT;
            point = sumdie;
            cout << "POINT = " << point << endl << endl;
            break;
        }
        //ROLLS AGAIN to either get point or 7
        while (game == POINT)
        {
            cout << "TYPE R TO ROLL" << endl;
            cin >> rolln;
            cout << endl;
            //DICE ROLL
            if (rolln == 'r' || rolln == 'R')
            {
                die1 = rand() % 6 + 1;              
                die2 = rand() % 6 + 1;
                sumdie = die1 + die2;
                cout << "SUM OF DICE = " << sumdie << endl << endl;
            }
            //USER put something else besides r or R
            else
            {
                cout << "INVAILD INPUT";
                return 0;
            }
            //Test Case sum of dice is equal to point
            if (sumdie == point)
            {
                money += (2.0 * bet);
                cout << "YOU WIN" << endl << endl;
                cout << "MONEY WON = $" << 2.0 * bet << endl;
                win++;
                game = NPOINT;
            }
            else if (sumdie == 7)
            {
                cout << "YOU LOSE" << endl << endl;
                cout << "MONEY LOST = $" << bet << endl;
                lose++;
                game = NPOINT;
            }
        }
        //Did not pass the line and bet on outcome
        if (game == NOPASS && (betltr == 'D' || betltr == 'd'))
        {
            money += (2.0 * bet);
            cout << "YOU WIN" << endl << endl;
            cout << "MONEY WON = $" << 2.0 * bet << endl;
            win++;
        }
        //Pass the line and bet on outcome
        else if (game == PASS && (betltr == 'P' || betltr == 'p'))
        {
            money += (2.0 * bet);
            cout << "YOU WIN" << endl << endl;
            cout << "MONEY WON = $" << 2.0 * bet << endl;
            win++;
        }
        //Outcome bet on did not occur
        else if (game == PASS || game == NOPASS)
        {
            cout << "YOU LOSE" << endl << endl;
            cout << "MONEY LOST = $" << bet << endl;
            lose++;
        }
        //Story Mode Interest Calc
        if (hard)
        {
            debt *= pow((1 + .01), (win + lose));
            cout << "Current Loan Amount = $" << fixed << setprecision(2) << debt << endl;
            cout << "Mother's Medical Bills = $" << fixed << setprecision(2) << mom << endl;
        }
        //User input to end or continue game
        cout << "MONEY = $" << money << endl;
        cout << endl << "CONTINUE?(y/n)" << endl;
        cin >> cont;
        cout << endl << endl << endl;
    } while (money > 0 && (cont == 'y' || cont == 'Y'));
    //Display Results
    //Easy Mode Output
    if (hard == false)
    {
        cout << "THANKS FOR PLAYING!" << endl;
        cout << "GAMES LOST = " << lose << endl;
        cout << "GAMES WON = " << win << endl;
    //EARNINGS    
        if (money > 1000)        
        {
            cout << "MONEY WON = $" << fixed << setprecision(2) << (money - 1000);
        }
    //LOSSES     
        else if (money < 1000)            
        {
            cout << "MONEY LOST = $" << fixed << setprecision(2) << (1000 - money);
        }
    //BREAK EVEN
        else
        {
            cout << "BREAK EVEN" << endl;
            cout << "MONEY = $" << fixed << setprecision(2) << money;
        }
        //Exit stage right
        return 0;
    }
    //STORY MODE OUTPUT
    else if (hard == true)
    {
    //Happy Ending
        if (money >= (debt + mom))
        {
            cout << "You win enough money playing Craps to pay off your loan and your mother's medical bills." << endl;
            cout << "You and your mother live happily ever after." << endl;
            cout << "MONEY = $" << fixed << setprecision(2) << money - (debt + mom) << endl;
            cout << "GAME OVER";
            return 0;
        }
    //Happy Ending?
        else
        {
            if (money - debt > 0)
            {
                cout << "You win enough money to pay back your loan but don't have enough to pay you mother's medical bills." << endl;
                cout << "You leave your mother for dead and make off with the remaining money." << endl;
                cout << "You live happily ever after?" << endl;
                cout << "MONEY = $" << fixed << setprecision(2) << money - debt << endl;
                cout << "GAME OVER";
                return 0;
            }
    //SAD Ending
            else
            {
                cout << "You didn't win enough money to pay off your mother's medical bills or your loan." << endl;
                cout << "Your mother dies soon after and you spend the rest of your life running from debt collectors." << endl;
                cout << "MONEY = $" << fixed << setprecision(2) << money - debt << endl;
                cout << "GAMEOVER";
            }
        }
    }
}
