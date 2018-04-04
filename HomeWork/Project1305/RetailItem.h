/*
 * RetailItem.h
 *
 *  Created on: Apr 3, 2018
 *      Author: Gordon
 */

#ifndef RETAILITEM_H_
#define RETAILITEM_H_

#include <string>

using namespace std;

class RetailItem
{
private:
	string description;
	int unitsOnHand;
	float price;
public:
	RetailItem(string des, int units, float price){
		this->description = des;
		this->unitsOnHand = units;
		this->price = price;
	}
	string get_description()const{return description;}
	int get_units()const{return unitsOnHand;}
	float get_price()const{return price;}
	void set_description(string str){description = str;}
	void set_unites(int newunits){this->unitsOnHand = newunits;}
	void set_price(float newprice){price = newprice;}

};

#endif /* RETAILITEM_H_ */
