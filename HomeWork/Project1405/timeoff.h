/*
 *  Created on: May 6, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 *     Purpose: Keeps track of time off.
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include<string>
#include "numdays.h"
using namespace std;

class TimeOff
{
private:
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
    string empName;
    unsigned int empNumber;
public:
    TimeOff(string name, unsigned int number)
       { 
        this->empName = name;
        this->empNumber = number;}
    void SetmaxSickDays(NumDays Max){ maxSickDays = Max;}
    float GetmaxSickDays(){return this->maxSickDays.getworkdays();}
    void SetsickDays(NumDays Sickdays){this->sickTaken = Sickdays;}
    float GetsickDays(){return this->sickTaken.getworkdays();}
    void SetmaxVacation(NumDays Max);
    float GetmaxVacation(){return this->maxVacation.getworkdays();}
    void SetvacTaken(NumDays Days){this->vacTaken = Days;}
    float GetvacTaken(){return this->vacTaken.getworkdays();}
    void SetmaxUnpaid(NumDays Days){this->maxUnpaid = Days;}
    float GetmaxUnpaid(){return this->maxUnpaid.getworkdays();}
    void SetunpaidTaken(NumDays Days){this->unpaidTaken = Days;}
    float GetunpaidTaken(){return this->unpaidTaken.getworkdays();}
    string GetName(){return empName;}
    int GetEmpNumber(){return empNumber;}
};


#endif /* TIMEOFF_H */

