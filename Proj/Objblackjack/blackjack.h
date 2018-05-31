/*
 *  Created on: May 7, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: blackjack definitions.
 */

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

const int DECK_SIZE = 52;
const int MAX_CARDS = 12;
const int MAX_HANDS = 4;
const int MAX_PLAYERS = 5;

// enum {Hit, Stand, Double, Split, Surrender};
enum status {Not_Used = -1, first, Hit, Surrender, Stand, Double, Bust};

void itoa(int n, char s[]);
void reverse(char *s);
char *getcard(short card, char *str);

#endif /* BLACKJACK_H_ */
