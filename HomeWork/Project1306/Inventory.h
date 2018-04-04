/*
 *  Created on: April 3, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose:  Inventory Class definition.
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

class Inventory
{
private:
	int itemNumber;
	int quantity;
	float cost;
	float totalCost;
public:
	Inventory(){
		itemNumber = 0;
		quantity = 0;
		cost = 0.0;
		totalCost = 0.0;}
	Inventory(int itemNum, float cost, int quantity){
		this->itemNumber = itemNum;
		this->cost = cost;
		this->quantity = quantity;
		this->totalCost = 0.0;}
		bool setItemNumber(int itemNum){
			if(itemNum >= 0){
				this->itemNumber = itemNum;
				return true;
			}else{
				this->itemNumber = 0;
				return false;
			}
		}
		bool setQuantity(int quantity){
				if(quantity >= 0){
				this->quantity = quantity;
				return true;
			}else{
				this->quantity = 0;
				return false;
			}
		}
		void setCost(int cost){
			if(cost >= 0)
				this->cost = cost;
			else
				this->cost = 0.0;
		}
		void setTotalCost(){this->totalCost = cost * 1.06;}
		int getItemNumber()const{return this->itemNumber;}
		int getQuantity()const{return this->quantity;}
		float getCost()const{return this->cost;}
		float getTotalCost()const{return this->totalCost;}
};




#endif /* INVENTORY_H_ */
