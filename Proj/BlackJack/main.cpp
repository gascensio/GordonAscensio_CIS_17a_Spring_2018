/*
 *  Created on: April 3, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: blackjack game with structures.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#include"blackjack.h"

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

int main()
{

	unsigned seed = time(0);
	Game game;
	short numplayers;
	char ch;

	srand(seed);
	do{
		initGame(game); // Initialize the deck and players.
		Shuffle(game);	// Shuffles deck of cards.
		cout << "Number of players between 1 and 5?";
		cin >> numplayers; // Gets number of players
		while(numplayers < 1 || numplayers > 5){
			cout << "out of bounds try again";
			cin >> numplayers;
		}
		cin.ignore();
		startGame(game, numplayers);
		for(int c = 0;c < game.numplayers;c++){
			continuePlay(game,c);
		}
		DealerPlay(game);
		printEnd(game);
		cout << "Hit 'Q' to quit or anything else to play again";
		cin >> ch;
	}while(toupper(ch) != 'Q');
        delete game.Deck;
}

/**********************************************************
 * Function tacks a integer between 0 and 51 representing
 * a unique card in a deck of 52 cards and returns the
 * cards suit.
 *
 */
char suit(short card)
{
	if(card < 13 && card >= 0)
		return 'S';
	else if(card < 26 && card >= 0)
		return 'C';
	else if(card < 39 && card >= 0)
		return 'H';
	else if(card < 52 && card >= 0)
		return 'D';
	return '\0';
}
/**********************************************************
 * the function getcard determines wither a card is a
 * ace, jack, queen, king, or a number card and returns
 * a c string encoded the characters "A", "J", "Q", "K",
 * or digits.
 */
char *getcard(short card, char *str)
{
	if(card%13 == 0){
		str[0] = 'A';
                str[1] = '\0';
        }else if(card%13 >= 1 && card%13 < 9)
		itoa(card%13+1,str);
	else if(card%13 == 9 ){
		str[0]='1';
                str[1]='0';
                str[2]='\0';
        }
	else if(card%13 == 10){
            str[0] = 'J';
            str[1] = '\0';
        }
	else if(card%13 == 11){
            str[0] = 'Q';
            str[1] = '\0';
        }
	else if(card%13 == 12){
            str[0] = 'K';
            str[1] = '\0';
        }
	else {
           str[0] = '\0';
        }
	return str;
}
/**********************************************************
 * The function initDeck initializes a deck of cards
 * with in a structure of type Game.
 */
void initDeck(Game &G)
{
	G.Deck = new short[DECK_SIZE];
	G.decksize = DECK_SIZE;
	for(int c = 0;c < DECK_SIZE;c++){
		G.Deck[c] = c;
	}
	G.index = 0;
}
/**********************************************************
 * The function Shuffle Shuffles the Deck in side a Game
 * structure.
 */
void Shuffle(Game &game)
{
	short n;
	short temp;

	for(int c = 0;c < game.decksize;c++){
		n =(short)(rand()%52);
		temp = game.Deck[c];
		game.Deck[c] = game.Deck[n];
		game.Deck[n] = temp;
	}
	game.index = 0;
}
/**********************************************************
 * The function DealCard gets the next card in the G.Deck
 * array and advances the G.index by one.
 */
short DealCard(Game &G)
{
	short card = G.Deck[G.index];
	G.index++;
	return card;
}
/**********************************************************
 * Function firstDeal()
 * Function deals the first round of cards.
 */
void firstDeal(Game &game)
{
	const int NUMPLAYERS = game.numplayers;

	for(int c = 0;c < NUMPLAYERS;c++)
		game.Players[c].hand[0].cards[0] = DealCard(game);
	game.Dealer.cards[0] = DealCard(game);
	for(int i = 0;i < NUMPLAYERS;i++){
		game.Players[i].hand[0].cards[1] = DealCard(game);
		game.Players[i].numhands = 1;
		game.Players[i].hand[0].index = 2;
		game.Players[i].hand[0].Stat = first;
	}
	game.Dealer.cards[1] = DealCard(game);
	game.Dealer.index = 2;

}
/**********************************************************
 * The function printHand prints all of the cards in a
 * hand of cards that is stored in a struct type Hand.
 */
void printHand(Hand hand)
{
	char str[3];
	for(int c = 0;c < hand.index;c++){
		cout << getcard(hand.cards[c],str) << suit(hand.cards[c]);
		cout << " ";
	}
	cout << " :" << CountCards(hand) << " ";
	return;
}
/**********************************************************
 * The function CountCards counts the cards in a Hand.
 */
short CountCards(Hand H)
{
	short accum = 0;
	short aces = 0;
        int c = 0;

	for(c = 0;c < H.index; c++){
		if(CardVelue(H.cards[c]) == 11)
			aces++;
		if(CardVelue(H.cards[c]) < 1)

                    return -1;
        	accum += CardVelue(H.cards[c]);
	}
	while(accum > 21 && aces > 0){
		accum -= 10; //subtracts 10 for an ace.
		aces--;
	}


	return accum;
}
/**********************************************************
 * The function CardVelue returns a cards value.
 */
short CardVelue(short card)
{
	char *str = new char[3];
	short i = 0;

	str = getcard(card, str);


	if(str[0] == 'A')
		i = 11;
	else if (str[0] == 'J' || str[0] == 'Q' || str[0] == 'K')
		i = 10;
	else if(str[0] >= '1' && str[0] <= '9')
		i = (short)atoi(str);
	else
		i = -1;
	delete str;
	return i;

}
/**********************************************************
 * Function initializes a structure of type Game
 */
void initGame(Game &G)
{
	for(int i = 0;i < MAX_CARDS;i++)
	G.Dealer.cards[i] = -1; //Sets all the cards in the Dealers hand.
	G.Dealer.Stat = first;	//Sets the Status to first card.

	for(int c = 0;c < MAX_PLAYERS;c++) //Initializes each player.
		initPlayer(G.Players[c]);
	initDeck(G);

}
/**********************************************************
 * Function initializes a struct type Player
 */
void initPlayer(Player &P)
{
	P.numhands = 0; // Sets number of hands the player has to zero.
	for(int c = 0;c < MAX_HANDS;c++) 	// Initializes each possible hand in the
		initHand(P.hand[c]);			// a player structure.
}
/**********************************************************
 * Function initializes a structure type Hand.
 */
void initHand(Hand &H)
{
	int i;
	for(i=0;i<MAX_CARDS;i++) // Sets each card to -1.
		H.cards[i]=-1;
	H.Stat = Not_Used; // Sets status flag to not used.
	H.bet = 0;
	H.index = 0;
}
/**********************************************************
 * Function sets the number of players for a game
 * and Deals the first cards.
 */
void startGame(Game &G, short numplayers)
{
	G.numplayers = numplayers;
	firstDeal(G);
}
/**********************************************************
 * Function prints the current game to screen.
 */
void printGame(Game &G, bool flag)
{
	char str[3];

	system("cls"); // Clears the screen.
	cout << "Dealers: ";
	if(flag == false)	//Prints one card if flag is true.
		cout << getcard(G.Dealer.cards[0],str) << suit(G.Dealer.cards[0]);
	else	//Prints the Dealers entire hand if flag is false.
		printHand(G.Dealer);
	cout << endl << endl;

	for(int i = 0;i < G.numplayers;i++){
		cout << "Player #" << i+1 << endl;
		for(int c = 0;c < G.Players[i].numhands;c++){// Runs through 
                                                       //each hand of a player,
			cout << "hand #" << c+1 << " ";//and prints each hand out.
			printHand(G.Players[i].hand[c]);
			if(G.Players[i].hand[c].Stat == first)	// Prints "start of hand" if status is
				cout << "start of hand.";			// first.
			else if(G.Players[i].hand[c].Stat == Surrender)// Prints "Surrender" if status is
				cout << "Surrender";						// Surrender.
			else if(G.Players[i].hand[c].Stat == Stand)	// Prints "Stand" if status is Stand.
				cout << "Stand";
			else if(G.Players[i].hand[c].Stat == Bust)	// Prints "Bust" if status is Bust.
				cout << "Bust";
			else if(G.Players[i].hand[c].Stat == Double)
            	cout << "Double down.";
			cout << endl;
		}
	}
}
/**********************************************************
 * Function firstplay()
 * plays the first hand for each player.
 */
void firstplay(Game &G, short player, short h)
{
	char str[3], arg[3];
	char ch;
	bool can_split = false;
	bool loop;
        short index = G.Players[player].numhands;


	printGame(G,false);
	if(CountCards(G.Players[player].hand[h]) == 21){
			cout << "BlackJack!" << endl;
	}else if(strcmp(getcard(G.Players[player].hand[h].cards[0],str),
			getcard(G.Players[player].hand[h].cards[1],arg)) == 0){
            if(index < MAX_HANDS)
		can_split = true;
            else
                can_split = false;
	}
	cout << "Player #" << player + 1 
                << " type 'H' to Hit, 'S' to Stand, 'D' to Double Down, ";
	if(can_split == true){
		cout << "'U' to Surrender, and 'P' to Split.";
	}else{
		cout <<"and 'U' to Surrender.";
	}
	do{
		ch = cin.get();
		switch(toupper(ch)){
		case 'H':
			G.Players[player].hand[h].Stat = Hit;
			G.Players[player].hand[h].cards[2] = DealCard(G);
			G.Players[player].hand[h].index++;
			if(CountCards(G.Players[player].hand[0]) > 21)
				G.Players[player].hand[h].Stat = Bust;
			loop = false;
			break;
		case 'S':
			G.Players[player].hand[h].Stat = Stand;
			loop = false;
			break;
		case 'D':
			G.Players[player].hand[h].Stat = Double;
			G.Players[player].hand[h].cards[2] = DealCard(G);
			G.Players[player].hand[h].index++;
			if(CountCards(G.Players[player].hand[h]) > 21)
				G.Players[player].hand[h].Stat = Bust;
			loop = false;
			break;
		case 'U':
			G.Players[player].hand[h].Stat = Surrender;
			loop = false;
			break;
		case 'Q':
                    delete G.Deck;
			exit(0);
		default:
			if(toupper(ch) == 'P' && can_split == true){
				G.Players[player].hand[index].cards[0] 
                                        = G.Players[player].hand[0].cards[1];
				G.Players[player].hand[h].cards[1] = DealCard(G);
				G.Players[player].hand[index].cards[1] 
                                        = DealCard(G);
				G.Players[player].hand[h].Stat = first;
				G.Players[player].hand[index].Stat = first;
				G.Players[player].numhands = 2;
				G.Players[player].hand[index].index = 2;
				loop = false;
			}else {
			cout << "invalid choice try again" << endl;
			loop = true;
			}
		}
		cin.ignore();
	}while(loop == true);
	return;

}
/*
 *
 */
void continuePlay(Game &G, short player)
{
	short total;
	char ch;
	bool loop;
	int hands = G.Players[player].numhands;
	int i = 0, test = hands;

	do{
            hands--;
             firstplay(G, player, i);
                if(test < G.Players[player].numhands){
                    test = G.Players[player].numhands;
                    hands++;
                }
            if(G.Players[player].hand[i].Stat == Stand ||
                    G.Players[player].hand[i].Stat == Bust||
                    G.Players[player].hand[i].Stat == Double||
                    G.Players[player].hand[i].Stat == Surrender){
                if (i == G.Players[player].numhands)
                    return;
                else
                    i++;

            }else{

		do{
			printGame(G,false);
			total = CountCards(G.Players[player].hand[i]);
			cout << "Player #" << player + 1 << " hand #" << i + 1;
			if(total == 21){
				cout <<  " is 21." << endl;
			} else if(total > 21){
				cout << " is bust." << endl;
				loop = false;
			}
			cout << " type 'H' to Hit, and 'S' to Stand." << endl;
			ch = cin.get();
			if(toupper(ch) == 'H'){
				G.Players[player].hand[i].cards[G.Players[player].hand[i].index] = DealCard(G);
				G.Players[player].hand[i].index++;
				if(CountCards(G.Players[player].hand[i]) > 21){
					G.Players[player].hand[i].Stat = Bust;
					loop = false;
				}else{
					loop = true;
                                        G.Players[player].hand[i].Stat = Hit;
                                }
			}else if(toupper(ch) == 'S'){
				G.Players[player].hand[i].Stat = Stand;
				loop = false;
			}else if(toupper(ch) == 'Q'){
				exit(0);
			}
			if(CountCards(G.Players[player].hand[i]) > 21){
				G.Players[player].hand[i].Stat = Bust;
				cout << "Player #" << player + 1 << " hand #"
                                        << i + 1 << " is bust!" << endl;
				loop = false;
			}
			cin.ignore();
		}while(loop == true);

		i++;
            }
	}while(hands > 0);

}
void DealerPlay(Game &G){


	while( CountCards(G.Dealer) < 17 ){
		G.Dealer.cards[G.Dealer.index] = DealCard(G);
		G.Dealer.index++;
		G.Dealer.Stat = Hit;
		}
	if(CountCards(G.Dealer) > 21)
		G.Dealer.Stat = Bust;
	else
		G.Dealer.Stat = Stand;

}
void printEnd(Game G)
{
		bool DealerBust = false;;

		system("cls");
		cout << "Dealers: ";
		printHand(G.Dealer);
		if(CountCards(G.Dealer) > 21){
			cout << "Bust";
			DealerBust = true;
		}
		cout << endl << endl;

		for(int i = 0;i < G.numplayers;i++){
			cout << "Player #" << i+1 << endl;;
			for(int c = 0;c < G.Players[i].numhands;c++){
				cout << "hand #" << c+1 << " ";
				printHand(G.Players[i].hand[c]);
                                if(G.Players[i].hand[c].Stat == Surrender)
                                    cout << "lose";
				else if(CountCards(G.Players[i].hand[c]) 
                                        <= 21 && DealerBust == true)
					cout << "WIN!";
				else if(CountCards(G.Players[i].hand[c]) > 21)
					cout << "lose";
				else if(CountCards(G.Players[i].hand[c]) 
                                        == CountCards(G.Dealer) )
					cout << "Push";
				else if(CountCards(G.Players[i].hand[c]) 
                                        < CountCards(G.Dealer)
						&& DealerBust == false)
					cout << "lose";
				else if(CountCards(G.Players[i].hand[c]) 
                                        > CountCards(G.Dealer) && 
                                        CountCards(G.Players[i].hand[c])<= 21)
					cout << "WIN";
				cout << endl;
			}
		}
}
/* ********************************************************
 * Function itoa();
 * From The C programming language Second Edition
 * Brian w. Kernighan and Dennis M Ritchie
 *
 */
void itoa(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
/**********************************************************
 * Function reverse()
 * From The C programming language Second Edition
 * Brian w. Kernighan and Dennis M Ritchie
 */
void reverse(char *s)
{
    int c, i, j;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}