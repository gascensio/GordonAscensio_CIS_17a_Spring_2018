/*
 * Employee.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Weather Data Structure.
 */
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

Employee::Employee(string Empname, int empidnum, string Dep, string Posit )
{
	this->Name = Empname;
	this->idNumber = empidnum;
	this->Department = Dep;
	this->Position = Posit;
}
Employee::Employee(string Empname, int empidnum)
{
	Name = Empname;
	idNumber = empidnum;
	Department = "";
	Position = "";
}


