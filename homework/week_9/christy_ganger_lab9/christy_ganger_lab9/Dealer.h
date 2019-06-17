/*CIS 162c++
week 9 blackjack
Written by  jim bailey,
This specific file, and modifications made by christy ganger
*/
#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "PlayingCardDeck.h"

class Dealer : public Player
{
	private:
		PlayingCardDeck * theDeck;

    protected:
        Player * dealerplayer;

    public:
    	Dealer();
    	Dealer(int numShuffles);
    	~Dealer();
        std::string showHand();
        std::string fullHand();
        PlayingCard* dealCard();
        int cardsLeft();
        void shuffle();

};



#endif
