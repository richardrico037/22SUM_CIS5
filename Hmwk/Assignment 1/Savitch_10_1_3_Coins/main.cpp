/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: C++ Template - To be used in all future Assignments
 */

//System Libraries
#include <iostream>

int main() {
    using std::cin; 
    using std::cout;
    using std::endl;
    
    int Quarters, Dimes, Nickels, Total;
    cout << "Quarters = ";
    cin >> Quarters;
    cout << "Dimes = ";
    cin >> Dimes;
    cout << "Nickels = ";
    cin >> Nickels;
    Total = Quarters*25 + Dimes*10 + Nickels*5;
    cout << "Total = " << Total << " cents" << endl;
    return 0;
}

