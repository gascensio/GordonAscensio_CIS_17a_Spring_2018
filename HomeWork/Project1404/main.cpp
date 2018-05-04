/*
 *  Created on: May 4, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 *     Purpose: Converts work hours to days
 */


#include <cstdlib>
#include <iostream>
#include "numdays.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    NumDays Obj(40);
    
    cout << Obj.workdays() << endl;
    Obj++;
    cout << Obj.workdays() << endl;
    return 0;
}

