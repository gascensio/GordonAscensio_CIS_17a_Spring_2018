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
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deckofcards.h"
#include "blackjack.h"
using namespace std;

/**********************************************************
 * Function shuffles a deck of 52 cards
 */
void DeckOfCards::shuffle()
{
	int i;
	int card;
	char temp;

	for(i = 0;i < DECK_SIZE;i++){
		card = static_cast<short>(rand()%52);
		temp = this->deck[i];
		this->deck[i] = this->deck[card];
		this->deck[card] = temp;
	}
	nextcard = 0;
}
/**********************************************************
 * Function returns the next card in the deck.
 */
char DeckOfCards::deal()
{
	char card = deck[static_cast<int>(nextcard)];

	nextcard++;
	return card;

}
