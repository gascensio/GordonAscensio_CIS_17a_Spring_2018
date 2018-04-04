/*
 *  Created on: April 3, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates PersonalInfo Class.
 */

#include <iostream>
using namespace std;

void PrintItem(RetailItem Item);

int main(void)
{
	RetailItem A("Jacket", 12, 59.95);
	RetailItem B("Designer Jeans", 40, 34.95);
	RetailItem C("Shirt", 20, 24.95);
	PrintItem(A);
	cout << endl;
	PrintItem(B);
	cout << endl;
	PrintItem(C);


}
void PrintItem(RetailItem Item)
{
	cout << Item.description << " Quantity: "
			<< Item.unitsOnHand << " $" << Item.price;
}
