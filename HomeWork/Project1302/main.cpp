/*
 *  Created on: Mar 30, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates Employee Class.
 */
#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"

using namespace std;

void Print_employee(Employee A);

int main(void)
{
Employee A("Susan Meyers",47899,"Accounting","Vice President");
Employee B("Mark Jones", 39119, "IT", "Programmer");
Employee C("Joy Rogers", 81774, "Manufacturing", "Engineer");
Print_employee(A);
Print_employee(B);
Print_employee(C);
}
/**********************************************************
 * Function prints employee class object.
 */
void Print_employee(Employee A)
{
	cout << left << setw(20)<< A.get_Name() << setw(20) << A.get_idNumber() << setw(20)
			<< A.get_Department() << setw(20) << A.get_Position()  << right << endl;
}
