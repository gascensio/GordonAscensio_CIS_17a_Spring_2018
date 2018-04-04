/*
 *  Created on: April 1, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates Inventory Class.
 */
#include <iostream>
#include <iomanip>

using namespace std;

#include "Inventory.h"

void PrintItem(Inventory Item);

int main()
{
	Inventory hat(1, 7.95, 50);
	Inventory shirt(2, 9.95, 10);

	//Initialize total cost member.
	hat.setTotalCost();
	shirt.setTotalCost();

	//Print each item.
	PrintItem(hat);
	cout << endl;
	PrintItem(shirt);

}
/**********************************************************
 * Function PrintItem prints the fields of an Inventory
 * Object.
 */
void PrintItem(Inventory Item)
{
	cout << "Item number #"<< Item.getItemNumber()
			<< " quantity " <<  Item.getQuantity()
			<< fixed << setprecision(2)
			<< " cost $" << Item.getCost()
			<< " Total cost $" << Item.getTotalCost();
}

