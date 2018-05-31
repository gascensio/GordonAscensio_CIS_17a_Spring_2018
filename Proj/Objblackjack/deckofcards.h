/*
 * hand.h
 *
 *  Created on: May 7, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: To implement a deck of cards class.
 */
#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

#include <iostream>
#include <string>
#include "blackjack.h"

using namespace std;

class DeckOfCards
{
private:
	 char *deck;
	 char nextcard;
public:
	DeckOfCards(){
		deck = new char[DECK_SIZE];
		for(char i = 0;i < DECK_SIZE;i++)
			deck[static_cast<int>(i)] = i; // should be set to i
		nextcard = 0;
	}
	void shuffle();
	char deal();
	~DeckOfCards(){
		delete [] deck;
	}
};

#endif /* DECKOFCARDS_H_ */