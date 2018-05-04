/*
 *  Created on: May 2, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Print Day of year
 */

#ifndef DAYOFYEAR_H_
#define DAYOFYEAR_H_
#include <iostream>
#include <string>
using namespace std;

enum { January, February, March, April, May, June, July,
	August, September, October, November, December };

class DayOfYear
{
private:
	int days;
	static string month[12];
public:
        DayOfYear(string month, int day);
	DayOfYear(int numdays);
	void print();
        DayOfYear operator++();
        DayOfYear operator++(int);
        DayOfYear operator--();
        DayOfYear operator--(int);
};




#endif /* DAYOFYEAR_H_ */
