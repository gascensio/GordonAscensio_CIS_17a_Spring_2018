/*
 *  Created on: May 6, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 *     Purpose: Keeps track of time off.
 */

#include "numdays.h"
#include "timeoff.h"

void TimeOff::SetmaxVacation(NumDays Max)
{
    const int MAXVACATION = 240;
    int max = Max.gethours();
    if(max > MAXVACATION){
        this->maxVacation = 240;
    }else{
        this->maxVacation = Max;
    }
    return;
}
