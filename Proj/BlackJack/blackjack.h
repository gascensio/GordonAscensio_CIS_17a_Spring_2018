/*
 * blackjack.h
 *
 *  Created on: Apr 4, 2018
 *      Author: Gordon
 */

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

const int DECK_SIZE = 52;
const int MAX_CARDS = 12;
const int MAX_HANDS = 4;
const int MAX_PLAYERS = 5;

// enum {Hit, Stand, Double, Split, Surrender};
enum status {Not_Used = -1, first, Hit, Surrender, Stand, Double, Bust};
struct DeckOfCards{
	short *array;	//The deck
	short index;
	short size;
};

struct Hand {
	short cards[MAX_CARDS];
	short index;
	int bet;
	status Stat; // keeps track
};
struct Player{
	Hand hand[MAX_HANDS];
	short numhands;
};
struct Game{
	Hand Dealer;
	Player Players[MAX_PLAYERS];
	short numplayers;
	short *Deck;
	short index;
	short decksize;
};

char suit(short card);
char *getcard(short card, char *str);
void initDeck(Game &G);
void Shuffle(Game &);
short DealCard(Game &game);
void firstDeal(Game &game);
void printHand(Hand hand);
short CountCards(Hand H);
short CardVelue(short card);
void initGame(Game &G);
void initPlayer(Player &P);
void initHand(Hand &H);
void startGame(Game &G, short );
void printGame(Game &G, bool flag);
void DealerPlay(Game &G);
void firstplay(Game &G, short player, short h);
void continuePlay(Game &G,short player);
void printEnd(Game G);
void itoa(int n, char s[]);
void reverse(char s[]);



#endif /* BLACKJACK_H_ */