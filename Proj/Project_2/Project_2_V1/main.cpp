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
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::setprecision;
using std::fixed;
using std::pow;

//Function Pre-Intialization
bool menu();
void roll(int *dice);
void e_lose(int);
void e_win(int);
void die1();
void die2();
void die3();
void die4();
void die5();
void die6();

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variables/Initialize Variables
    char betltr, die1, die2, rolln, cont = 'y';
    float money, bet, debt, mom;
    int  point, sumdie, win = 0, lose = 0;
    int dice[2];
    int bets[3][3];
    string users[3];
    enum Status { POINT, PASS, NOPASS, NPOINT };
    bool hard;
    Status game;
    //initializer
    money = 1000.00;
    //PLAY GAME
    hard = menu();
   if(hard == true )
   {
       mom = 1000;
       debt = money;
   }
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
        cout << endl;
        if (rolln == 'r' || rolln == 'R')
        {
            sumdie = 0;
            roll(dice);
            for (int i = 0; i < 2; i++)
            {
                sumdie += dice[i];
            }
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
            cout << "POINT = " << point << endl << endl;
            break;
        }
        while (game == POINT)
        {
            cout << "TYPE R TO ROLL" << endl;
            cin >> rolln;
            cout << endl;
            if (rolln == 'r' || rolln == 'R')
            {
                sumdie = 0;
                roll(dice);
                for (int i = 0; i < 2; i++) 
                {
                    sumdie += dice[i];
                }
                cout << "SUM OF DICE = " << sumdie << endl << endl;
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
                e_win(bet);
                win++;
                game = NPOINT;
            }
            else if (sumdie == 7)
            {
                e_lose(bet);
                lose++;
                game = NPOINT;
            }
        }
        //Did not pass the line and bet on outcome
        if (game == NOPASS && (betltr == 'D' || betltr == 'd'))
        {
            money += (2.0 * bet);
            e_win(bet);
            win++;
        }
        //Pass the line and bet on outcome
        else if (game == PASS && (betltr == 'P' || betltr == 'p'))
        {
            money += (2.0 * bet);
            e_win(bet);
            win++;
        }
        //Outcome bet on did not occur
        else if (game == PASS || game == NOPASS)
        {
            e_lose(bet);
            lose++;
        }
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
    } while (money > 0 && (cont == 'y' || cont == 'Y'));
    //Display Results
    if (hard == false)
    {
        cout << "THANKS FOR PLAYING!" << endl;
        cout << "GAMES LOST = " << lose << endl;
        cout << "GAMES WON = " << win << endl;

        if (money > 1000)        //EARNINGS
        {
            cout << "MONEY WON = $" << fixed << setprecision(2) << (money - 1000);
        }
        else if (money < 1000)              //LOSSES 
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
    else if (hard == true)
    {
        if (money >= (debt + mom))
        {
            cout << "You win enough money playing Craps to pay off your loan and your mother's medical bills." << endl;
            cout << "You and your mother live happily ever after." << endl;
            cout << "MONEY = $" << fixed << setprecision(2) << money - (debt + mom) << endl;
            cout << "GAME OVER";
            return 0;
        }
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
            else
            {
                cout << "You didn't win enough money to pay off your mother's medical bills or your loan." << endl;
                cout << "Your mother dies soon after and you spend the rest of your life running from debt collectors." << endl;
                cout << "MONEY = $" << fixed << setprecision(2) << money - debt << endl;
                cout << "GAMEOVER";
                return 0;
            }
        }
    }
}
bool menu() 
{
    bool hard, menu = true;
    int start;
    do
    {
        //Read Main Menu from txt file
        fstream main_t;
        main_t.open("C:/Users/woodc/OneDrive/Desktop/Project_1/Craps.txt", std::ios::in);
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
        cin >> start;
        switch (start)
        {
            //Start the Game
        case 1:
            cout << "EASY MODE" << endl << endl;
            menu = false;
            hard = false;
            break;
            //Rules read from text file
        case 2:
        {
            fstream story;
            story.open("C:/Users/woodc/OneDrive/Desktop/Project_1/Story.txt", std::ios::in);
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
            menu = false;
            break;
        }
        case 3:
        {
            fstream rules;
            rules.open("C:/Users/woodc/OneDrive/Desktop/Project_1/Rules.txt", std::ios::in);
            if (rules.is_open())
            {
                string line;
                while (std::getline(rules, line))
                {
                    cout << line << endl;
                }
            }
            break;
        }
        //Quit Game
        case 4:
            exit(0);
        }
    } while (menu);
    return hard; 
}

void roll(int *dice)
{
    for(int i = 0; i < 2; i++)
    {
        dice[i] = rand() % 6 + 1;              //DIE ROLL
    }
    for(int i = 0; i < 2; i++)
    {
        switch (dice[i]) 
        {
            case 1:
                die1();
                break;
            case 2:
                die2();
                break;
            case 3:
                die3();
                break;
            case 4:
                die4();
                break;
            case 5:
                die5();
                break;
            case 6:
                die6();
                break;
        }   
    }
};
void e_win(int b)
{
    cout << "YOU WIN" << endl << endl;
    cout << "MONEY WON = $" << 2 * b << endl;
};
void e_lose(int b)
{
    int lose;
    cout << "YOU LOSE" << endl << endl;
    cout << "MONEY LOST = $" << b << endl;
};
void die1()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Die/Die_1.txt", std::ios::in);
    if (die.is_open())
    {
        string line;
        while (std::getline(die, line))
        {
            cout << line << endl;
        }
        die.close();
    }
};
void die2()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Die/Die_2.txt", std::ios::in);
    if (die.is_open())
    {
        string line;
        while (std::getline(die, line))
        {
            cout << line << endl;
        }
        die.close();
    }
};
void die3()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Die/Die_3.txt", std::ios::in);
    if (die.is_open())
    {
        string line;
        while (std::getline(die, line))
        {
            cout << line << endl;
        }
        die.close();
    }
};
void die4()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Die/Die_4.txt", std::ios::in);
    if (die.is_open())
    {
        string line;
        while (std::getline(die, line))
        {
            cout << line << endl;
        }
        die.close();
    }
};
void die5()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Die/Die_5.txt", std::ios::in);
    if (die.is_open())
    {
        string line;
        while (std::getline(die, line))
        {
            cout << line << endl;
        }
        die.close();
    }
};
void die6()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Die/Die_6.txt", std::ios::in);
    if (die.is_open())
    {
        string line;
        while (std::getline(die, line))
        {
            cout << line << endl;
        }
        die.close();
    }
};