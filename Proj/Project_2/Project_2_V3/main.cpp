/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on July 27, 2022, 2:00 PM
 * Purpose: Project 2
 */

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
using std::getline;

//Function Pre-Intialization
bool menu();
void roll(int *dice);
void bubble(float *money, string *users);
void insert(int *win, string *users);
void e_lose(int, string);
void e_win(int, string);
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
    float debt, mom;
    int  bet, point, sumdie, win[2] = { 0, 0 }, lose[2] = { 0, 0 };
    int dice[2];
    int bets[2][2];
    float money[2];
    string users[2];
    enum Status { POINT, PASS, NOPASS, NPOINT };
    bool hard, zero = false;
    Status game;
    //initializer
    for (int i = 0; i < 2; i++)
    {
        money[i] = 1000;
    }
    //PLAY GAME
    hard = menu();
   if(hard == true )
   {
       mom = 1000;
       debt = money[0];
   }
   else
   {
       cout << "(NAME CANNOT CONTAIN SPACES)" << endl;
       for (int i = 0; i < 2; i++)
       {
           cout << "Enter Player " << i + 1 << ": ";
           cin >> users[i];
       }
   }    
    do
    {
        cout << endl;
        if (hard == false)
        {
            for (int i = 0; i < 2; i++)
            {
                cout << users[i] << " MONEY = $" << money[i] << endl;
                cout << "Type 1 to bet on pass line or Type 2 for don't pass line" << endl;
                cin >> bets[0][i];
                bets[1][i] = 0;
                for (int j = 0; bets[1][i] > money[i] || bets[1][i] <= 0; j++) 
                {
                    cout << "How much do you want bet?" << endl;
                    cin >> bets[1][i];
                    if (bets[1][i] > money[i]) 
                    {
                        cout << "NOT ENOUGH MONEY" << endl;
                    } 
                    else if (bets[1][i] <= 0) 
                    {
                        cout << "INVALID BET" << endl;
                    }
                    if (j > 0 && (bets[1][i] < money[i] && bets[1][i] > 0)) 
                    {
                        cout << "BET INCORRECTLY " << j << " TIMES" << endl << endl;
                    }
                }
                money[i] -= bets[1][i];
            }
        }
        else 
        {
            cout << "MONEY = $" << money[0] << endl;
            cout << "Type 1 to bet on pass line or Type 2 for don't pass line" << endl;
            cin >> bets[0][0];
            bet = 0;
            for (int i = 0; bet > money[0] || bet <= 0; i++) 
            {
                cout << "How much do you want bet?" << endl;
                cin >> bet;
                if (bet > money[0]) {
                    cout << "NOT ENOUGH MONEY" << endl;
                } else if (bet <= 0) {
                    cout << "INVALID BET" << endl;
                }
                if (i > 0 && (bet < money[0] && bet > 0)) {
                    cout << "BET INCORRECTLY " << i << " TIMES" << endl << endl;
                }
            }
            money[0] -= bet;
        }
        
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
            exit(0);
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
                exit(0);
            }
            //Test Case sum of dice is equal to point
            if (sumdie == point)
            {
                if (hard)
                {
                  money[0] += (2 * bet);
                  e_win(bet, "YOU");
                  win[0]++;
                  game = NPOINT;  
                }
                else 
                {
                    for (int i = 0; i < 2; i++)
                    {
                        money[i] += (2 * bets[1][i]);
                        e_win(bets[1][i], users[i]);
                        win[i]++;
                        game = NPOINT;       
                    }
                }
            }
            else if (sumdie == 7)
            {
                if (hard) 
                {
                    e_lose(bet, "YOU");
                    lose[0]++;
                    game = NPOINT;
                } 
                else 
                {
                    for (int i = 0; i < 2; i++) 
                    {
                        e_lose(bets[1][i], users[i]);
                        lose[i]++;
                        game = NPOINT;
                    }
                }
            }
        }
        //Did not pass the line and bet on outcome
        if (hard)   //STORY MODE
        {
            if (game == NOPASS && (bets[0][0] == 2)) 
            {
                money[0] += (2 * bet);
                e_win(bet, "YOU");
                win[0]++;
            }                //Pass the line and bet on outcome
            else if (game == PASS && (bets[0][0] == 1))
            {
                money[0] += (2 * bet);
                e_win(bet, "YOU");
                win[0]++;
            }                //Outcome bet on did not occur
            else if (game == PASS || game == NOPASS) 
            {
                e_lose(bet, "YOU");
                lose[0]++;
            }
        }
        else    //MULTIPLAYER MODE
        {
           for (int i = 0; i < 2; i++)
           {
                if (game == NOPASS && (bets[0][i] == 2 )) 
                {
                    money[i] += (2 * bets[1][i]);
                    e_win(bets[1][i], users[i]);
                    win[i]++;
                }                    //Pass the line and bet on outcome
                else if (game == PASS && (bets[0][i] == 1)) 
                {
                    money[i] += (2 * bets[1][i]);
                    e_win(bets[1][i], users[i]);
                    win[i]++;
                }                    //Outcome bet on did not occur
                else if (game == PASS || game == NOPASS) 
                {
                    e_lose(bets[1][i], users[i]);
                    lose[i]++;
                }
           }
        }
        if (hard)
        {
            debt *= pow((1 + .01), (win[0] + lose[0]));
            cout << "Current Loan Amount = $" << fixed << setprecision(2) << debt << endl;
            cout << "Mother's Medical Bills = $" << fixed << setprecision(2) << mom << endl;
        }
        //User input to end or continue game
        if (hard)
        {
            cout << "MONEY = $" << money[0] << endl;
        }
        else 
        {
            for (int i = 0; i < 2; i++)
            {
                cout << users[i] << " MONEY = $" << money[i] << endl;
            }
        }
        cout << endl << "CONTINUE?(y/n)" << endl;
        cin >> cont;
        if (hard == false && (bets[1][0] == 0 || bets[1][1] == 0))
        {
            zero = true;
        }
    } 
    while ( zero == false && (cont == 'y' || cont == 'Y'));
    //Display Results
    if (hard == false)
    {
        cout << "THANKS FOR PLAYING!" << endl;
        cout << "LEADERBOARD" << endl << endl;
        cout << "   FINAL BALANCE" << endl;
        bubble(money, users);
        cout << "Player                 MONEY" << endl;
        for (int i = 0; i < 2; i++)
        {
             cout << users[i] << "                      $" << fixed << setprecision(0) << money[i] << endl;
        }
        cout << "Player                 GAMES WON" << endl;
        insert(win, users);
        for (int i = 0; i < 2; i++)
        {
            cout << users[i] << "                      " << win[i] << endl;
        }
               //Exit stage right
        return 0;
    }
    else if (hard)
    {
        if (money[0] >= (debt + mom))
        {
            cout << "You win enough money playing Craps to pay off your loan and your mother's medical bills." << endl;
            cout << "You and your mother live happily ever after." << endl;
            cout << "MONEY = $" << fixed << setprecision(2) << money[0] - (debt + mom) << endl;
            cout << "GAME OVER";
            return 0;
        }
        else
        {
            if (money[0] - debt > 0)
            {
                cout << "You win enough money to pay back your loan but don't have enough to pay you mother's medical bills." << endl;
                cout << "You leave your mother for dead and make off with the remaining money." << endl;
                cout << "You live happily ever after?" << endl;
                cout << "MONEY = $" << fixed << setprecision(2) << money[0] - debt << endl;
                cout << "GAME OVER";
                return 0;
            }
            else
            {
                cout << "You didn't win enough money to pay off your mother's medical bills or your loan." << endl;
                cout << "Your mother dies soon after and you spend the rest of your life running from debt collectors." << endl;
                cout << "MONEY = $" << fixed << setprecision(2) << money[0] - debt << endl;
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
        main_t.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Craps.txt", std::ios::in);
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
            story.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Story.txt", std::ios::in);
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
            rules.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Rules.txt", std::ios::in);
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
void e_win(int b, string name)
{
    cout << name << " WON" << endl;
    cout << "MONEY WON = $" << fixed << setprecision(2) << 2 * b << endl;
};
void e_lose(int b, string name)
{
    int lose;
    cout << name << " LOST" << endl;
    cout << "MONEY LOST = $" << fixed << setprecision(2) << b << endl;
};
void die1()
{
    fstream die;
    die.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Die/Die_1.txt", std::ios::in);
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
    die.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Die/Die_2.txt", std::ios::in);
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
    die.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Die/Die_3.txt", std::ios::in);
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
    die.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Die/Die_4.txt", std::ios::in);
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
    die.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Die/Die_5.txt", std::ios::in);
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
    die.open("C:/Users/woodc/OneDrive/Desktop/Project_2/Die/Die_6.txt", std::ios::in);
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
void bubble(float *money, string *users)
{
    float temp;
    string temp2;
    for (int i = 0; i < 1; i++)
    {
        for (int j = i + 1; j < 2; j++)
        {
            if (money[i] < money[j])
            {
                temp = money[i];
                money[i] = money[j];
                money[j] = temp;
                temp2 = users[i];
                users[i] = users[j];
                users[j] = temp2;
            }
        }
    }
};
void insert(int *win, string *users)
{
    for(int i = 1; i < 2; i++)
    {
        int key = win[i];
        string temp = users[i];
        int j = i - 1;
        while (key > win[j] && j >= 0)
        {
            win[j + 1] = win[j];
            users[j+1] = users[j];
            --j;
        }
        win[j + 1] = key;
        users[j+1] = temp;
    }
};