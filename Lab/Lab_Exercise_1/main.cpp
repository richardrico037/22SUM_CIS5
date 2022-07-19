/* 
 * File:   main.cpp
 * Author: Richard R. Rico
 * Created on June 23, 2022, 2:00 PM
 * Purpose: Lab Exercise 1
 */

//System Libraries
#include <iostream>


int main() {
    
    using std::cin;
    using std::cout;
    using std::endl;
    
    float gas_per, gas_cost_1, gas_cost_2;
    float tank, mpg, dist_1, dist_2;
    
    cout << "Gas Gage % Full: ";
    cin >> gas_per;
    cout << "Size of Tank in Gallons: ";
    cin >> tank;
    cout << "Miles per Gallon (MPG): ";
    cin >> mpg;
    cout << "Miles to Gas Station 1: ";
    cin >> dist_1;
    cout << "Gas Cost at Station 1: ";
    cin >> gas_cost_1;
    cout << "Miles to Gas Station 2: ";
    cin >> dist_2;
    cout << "Gas Cost at Station 2: ";
    cin >> gas_cost_2;      
    
    gas_per /= 100;
    float need;
    need = tank - (gas_per*tank);
    
    float cost_1, total_distance_1, cost_drive_1, total_cost_1, final_1;
    
    cost_1 = need * gas_cost_1;
    total_distance_1 = 2 * dist_1;
    cost_drive_1 = (total_distance_1 / mpg) * gas_cost_1;
    total_cost_1 = cost_1 + cost_drive_1;
    final_1 = total_cost_1 / need;  
    cout << "Total Cost 1: " << final_1 << endl;
            
    float cost_2, total_distance_2, cost_drive_2, total_cost_2, final_2;
    
    cost_2 = need * gas_cost_2;
    total_distance_2 = 2 * dist_2;
    cost_drive_2 = (total_distance_2 / mpg) * gas_cost_2;
    total_cost_2 = cost_2 + cost_drive_2;
    final_2 = total_cost_2 / need;  
    cout << "Total Cost 2: " << final_2 << endl;   
     
    return 0;
}

