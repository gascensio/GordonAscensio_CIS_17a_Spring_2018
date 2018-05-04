/*
 *  Created on: May 2, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Print Day of year
 */
#include <iostream>
#include <string>
#include "dayofyear.h"

using namespace std;

string DayOfYear::month[12] = {"January","February","March","April","May","June",
								"July","August","September","October","November",
								"December"};
DayOfYear::DayOfYear(string month, int day)
{
    if (day > 31 || day < 1){
        cout << "ERROR";
        exit(0);
    }
    if(month == "January")
        this->days = day;
    else if(month == "February")
        this->days = 31 + day;
    else if(month == "March")
        this->days = 59 + day;
    else if(month == "April")
        this->days = 90 + day;
    else if(month == "May")
        this->days = 120 + day;
    else if(month == "June")
        this->days = 151 + day;
    else if(month == "July")
        this->days = 181 + day;
    else if(month == "August")
        this->days = 212 + day;
    else if(month == "September")
        this->days = 243 + day;
    else if(month == "October")
        this->days = 273 + day;
    else if(month == "November")
        this->days = 304 + day;
    else if(month == "December")
        this->days = 334 + day;
    else{
        cout << "ERROR";
        exit(0);
    }
}
DayOfYear::DayOfYear(int numdays)
{
	if(numdays > 365){
		this->days = 365;
		return;
	}
	if(numdays < 1){
		this->days = 1;
		return;
	}
	this->days = numdays;
}
void DayOfYear::print()
{
	if(days <= 31)
		cout << this->month[January] << " " << days;
	else if(days > 31 && days <= 59)
		cout << this->month[February] << " " << days - 31;
	else if(days > 59 && days <= 90)
		cout << this->month[March] << " " << days - 59;
	else if(days > 90 && days <= 120)
		cout << this->month[April] << " " << days - 90;
	else if(days > 120 && days <= 151)
		cout << this->month[May] << " " << days - 120;
	else if(days > 151 && days <= 181)
		cout << this->month[June] << " " << days - 151;
	else if(days > 181 && days <= 212)
		cout << this->month[July] << " " << days - 181;
	else if(days > 212 && days <= 243)
		cout << this->month[August] << " " << days - 212;
	else if(days > 243 && days <= 273)
		cout << this->month[September] << " " << days - 243;
	else if(days > 273 && days <= 304)
		cout << this->month[October] << " " << days - 273;
	else if(days > 304 && days <= 334)
		cout << this->month[November] << " " << days - 304;
	else if(days > 334 && days <= 365)
		cout << this->month[December] << " " << days - 334;
}

DayOfYear DayOfYear::operator++()
{
    if(this->days == 365)
        this->days = 1;
    else 
        ++this->days;
    return *this;
}
DayOfYear DayOfYear::operator++(int)
{
    DayOfYear temp(days);
    if(days == 365)
        days = 1;
    else
        days++;
    return temp;
}
DayOfYear DayOfYear::operator--()
{
    if(this->days == 1)
        this->days = 365;
    else
        --this->days;
    return *this;
}
DayOfYear DayOfYear::operator--(int)
{
    DayOfYear temp(days);
    if(days == 1)
        days = 365;
    else
        days--;
    return temp;
}