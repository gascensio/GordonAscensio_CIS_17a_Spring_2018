/*
 *  Created on: May 4, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 *     Purpose: Converts work hours to days
 */


#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays
{
private:
    int workhr;
public:
    NumDays(int hr);
    NumDays operator+(const NumDays &right);
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator-(const NumDays &right);
    NumDays operator--();
    NumDays operator--(int);
    void gethours(int hr);
    float workdays();
    int hours(){return this->workhr;}
};


#endif /* NUMDAYS_H */

