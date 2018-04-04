/*
 * Car.h
 *  Created on: April 1, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates Employee Class.
 */

#ifndef CAR_H_
#define CAR_H_

#include<string>
using namespace std;

class Car
{
private:
	int yearModel;
	string make;
	int speed;
public:
	Car(int year, string make){
		yearModel = year;
		this->make = make;
		speed = 0;}
	int get_modelyear()const{return yearModel;}
	string get_make()const{return make;}
	int get_speed()const{return speed;}
	void accelerate(){speed += 5;}
	void brake(){speed -= 5;}
};



#endif /* CAR_H_ */
