/*
 * Employee.h
 *
 *  Created on: Mar 30, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Weather Data Structure.
 */


#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>

using namespace std;

class Employee
{
private:
	string Name;
	int idNumber;
	string Department;
	string Position;
public:
	Employee(string Empname, int Empidnum, string Dep, string Posit );
	Employee(string Empname, int Empidnum);
	Employee(){Name = "",idNumber = 0, Department = "", Position = "";}
	void put_Name(string name){Name = name;}
	void put_idNumber(int id){idNumber = id;}
	void put_Department(string Dep){Department = Dep;}
	void put_Position(string Pos){Position = Pos;}
	string get_Name()const{return Name;}
	int get_idNumber()const{return idNumber;}
	string get_Department()const{return Department;}
	string get_Position()const{return Position;}
};

#endif /* EMPLOYEE_H_ */
