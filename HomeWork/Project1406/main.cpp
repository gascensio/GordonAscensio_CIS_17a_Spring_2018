/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gordon
 *
 * Created on May 4, 2018, 2:37 PM
 */

#include <cstdlib>
#include <iostream>
#include "numdays.h"
#include "timeoff.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    TimeOff Time("John Doe", 1);
    unsigned int MonsWrk; // Months employee has worked for company.
    
    cout << "Enter number of months an employee has worked?";
    cin >> MonsWrk;
    
    NumDays MaxVacHr(MonsWrk * 12);
    NumDays SickHr(MonsWrk * 8);
    Time.SetmaxVacation(MaxVacHr);
    Time.SetmaxSickDays(SickHr);
    cout << "Name: " << Time.GetName() << endl;
    cout << "Employee #" << Time.GetEmpNumber() << endl;
    cout << "The number of Sick days are " << Time.GetmaxSickDays() << endl;
    cout << "The number of Vacation days are " << Time.GetmaxVacation() << endl;
    return 0;
}

