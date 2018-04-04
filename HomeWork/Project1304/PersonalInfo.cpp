/*
 *  Created on: April 1, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates PersonalInfo Class.
 */

#include <iostream>
#include "PersonalInfo.h"

using namespace std;

void PersonalInfo::prnt_all_info()const
{
	cout << name << " " << address << " age " << age << " phone: " << phone;
}


