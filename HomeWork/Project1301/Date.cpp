/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Date.cpp
 * Author: Gordon
 *
 * Created on March 30, 2018, 8:47 AM
 */
#include <iostream>
#include "Date.h"

using namespace std;

void Date::set_date()
{
	cout << "Enter month? ";
	cin >> month;
	while(month > 12 || month < 1){
		cout << "Enter valid month";
		cin >> month;
	}

	cout << "Enter day? ";
	cin >> day;
	while (day > 31 || day < 1){
		cout << "Enter valid day";
		cin >> day;
	}
	cout << "Enter year? ";
	cin >> year;
}
void Date::print_date_std() const
{
    cout << month << "/" << day << "/" << year;
}
void Date::print_date_long()const
{
	this->print_month();
	cout  << day << "," << year;
}
void Date::print_date_euro()const
{
	cout << day << " ";
	this->print_month();
	cout << year;
}
void Date::print_month() const
{

    switch(month){
    case January:
    	cout << "January ";
    	break;
    case February:
    	cout << "February ";
    	break;
    case March:
    	cout << "March ";
    	break;
    case April:
    	cout << "April ";
    	break;
    case May:
    	cout << "May ";
    	break;
    case June:
    	cout << "June ";
    	break;
    case July:
    	cout << "July ";
    	break;
    case August:
    	cout << "August ";
    	break;
    case October:
    	cout << "October";
    	break;
    case September:
    	cout << "September ";
    	break;
    case December:
    	cout << "December ";
    }
}


