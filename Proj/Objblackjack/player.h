/*
 * player.h
 *
 *  Created on: May 7, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: To implement a player class.
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "hand.h"
#include "deckofcards.h"

using namespace std;

class Player
{
protected:
	Hand hands[MAX_HANDS];
	int size;
	DeckOfCards *Deck;
	int purse;
public:
	Player();
	Player(DeckOfCards &Deck);
	void SetDeck(DeckOfCards &Deck){this->Deck = &Deck;}
	void firstdeal();
	virtual void printHands();
	void play();

};

#endif /* PLAYER_H_ */
