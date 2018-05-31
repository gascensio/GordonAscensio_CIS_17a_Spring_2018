/*  card.h
 *  Created on: May 7, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: To implement the card class.
 */
#ifndef CARD_H_
#define CARD_H_
/**********************************************************
 * Card Class represents one of 52 possible cards
 */
class Card
{
private:
	char card;
public:
	Card();
	void setcard(const char card);
	char get(){return this->card;}
	void operator=(const char card);
	void operator=(const Card &right);
	bool operator==(const Card card);
	char suit();
	char *rank();
	int value();
};



#endif /* CARD_H_ */
