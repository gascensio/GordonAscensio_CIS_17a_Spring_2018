/*
 * hand.h
 *
 *  Created on: May 7, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: To implement a card hand class.
 */

#ifndef HAND_H_
#define HAND_H_

#include <string>
#include "blackjack.h"
#include "card.h"
using namespace std;
class Hand
{
protected:
	Card *cards;
	int last;
	status stat;
	int wager;
public:
	// Initializer
	Hand();
	virtual void print();
	void PrntStat();
	Card getcard(int sub);
	void SetStat(status s){	this->stat = s;}
	status GetStat(){return this->stat;}
	void addcard(const char card);
	Hand split();
	void hit(char card);
	void DoubleDown(char card);
	void stand();
	void initialize();
	short countcards();
	void operator=(const Hand &right);
	//char operator[](const int sub);
	~Hand(){delete [] cards;}
};

#endif /* HAND_H_ */
