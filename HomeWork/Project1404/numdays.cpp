

/*
 *  Created on: May 4, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 *     Purpose: Converts work hours to days
 */

#include <iostream>
#include "numdays.h"
using namespace std;

NumDays::NumDays(int hr)
{
    if(hr > 0)
        workhr = hr;
    else 
        workhr = 0;
}
NumDays NumDays::operator+(const NumDays &right)
{
    NumDays temp(this->workhr);
    
    temp.workhr = this->workhr + right.workhr;
    if(temp.workhr < 0)
        temp.workhr = 0;
    return temp;
}
NumDays NumDays::operator++()
{
    ++workhr;
    return *this;
}
NumDays NumDays::operator++(int)
{
    NumDays temp(workhr);
    
    workhr++;
    return temp;
}
NumDays NumDays::operator-(const NumDays &right)
{
    NumDays temp(this->workhr);
    
    temp.workhr = this->workhr - right.workhr;
    if(temp.workhr < 0)
        temp.workhr = 0;
    return temp;
}
NumDays NumDays::operator--()
{
    if(this->workhr < 1)
        this->workhr = 0;
    --workhr;
    return *this;
}
NumDays NumDays::operator--(int)
{
    NumDays temp(workhr);
    
    if(this->workhr < 1)
        this->workhr = 0;
    else
        this->workhr--;
    return temp;
    
    
}
 void NumDays::gethours(int hr)
 {
     if(hr < 0){
         cout << "ERROR";
         exit(0);
     }else 
         this->workhr = hr;
     return;
 }
 float NumDays::workdays()
 {
     float out = static_cast<float>(this->workhr) / 8.0;
     return out;
 }
