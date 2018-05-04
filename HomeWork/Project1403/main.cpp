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

int main()
{
	int num;

	cout << "Enter the day a number between 1 and 365?";
	cin >> num;
	while(num < 1 || num > 365){
		cout << "number out of bounds try again?";
		cin >> num;
	}
	DayOfYear Day(num);
        Day--;
        --Day;

	Day.print();
}
