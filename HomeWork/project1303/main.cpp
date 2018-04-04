/*
 *  Created on: April 1, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates Car Class.
 */

#include <iostream>
#include "Car.h"

using namespace std;


int main(void)
{
	Car Aobj(1912,"Ford");
	int count;

	cout << "Speed=" << Aobj.get_speed() << endl;
	for(count = 0; count < 5; count++){
		Aobj.accelerate();
		cout << "Speed=" << Aobj.get_speed() << endl;
	}
	for(count = 0; count < 5; count++){
		Aobj.brake();
		cout << "Speed=" << Aobj.get_speed() << endl;
	}
}

