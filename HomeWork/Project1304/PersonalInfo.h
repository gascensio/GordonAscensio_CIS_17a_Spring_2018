/*
 * PersonalInfo.h
 *  Created on: April 1, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates PersonalInfo Class.
 */


#ifndef PERSONALINFO_H_
#define PERSONALINFO_H_

#include <iostream>
#include <string>

using namespace std;

class PersonalInfo
{
private:
	string name;
	string address;
	int age;
	string phone;
public:
	PersonalInfo(string name, string address, int age, string phone){
		this->name = name;
		this->address = address;
		this->age = age;
		this->phone = phone;
	}
	string get_name()const{return name;}
	string get_address()const{return address;}
	int get_age()const{return age;}
	string get_phone()const{return phone;}
	void prnt_all_info()const;
};

#endif /* PERSONALINFO_H_ */
