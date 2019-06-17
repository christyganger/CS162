/*CIS 162c++
week 9 blackjack
Written by  jim bailey,
This specific file, and modifications made by christy ganger
*/
#include "Player.h"
#include "Dealer.h"

    	Dealer::Dealer()
    	{
            theDeck = new PlayingCardDeck();
            dealerplayer = new Player();
    	}

    	Dealer::Dealer(int numShuffles)
    	{
            theDeck = new PlayingCardDeck();
            dealerplayer = new Player();
            theDeck->shuffle(numShuffles);
    	}

        Dealer::~Dealer()
        {
            delete theDeck;
            delete dealerplayer;
        }

        std::string Dealer::showHand()
        {
           std::string annoying = dealerplayer->showHand();
           annoying.replace(0,2,"XX");
           return annoying;
        }

        std::string Dealer::fullHand()
        {
            return dealerplayer->showHand();
        }

        PlayingCard* Dealer::dealCard()
        {
          return theDeck->dealCard();
        }


        int Dealer::cardsLeft()
        {
            return theDeck->getCountRemain();
        }

        void Dealer::shuffle()
        {
            theDeck->reset();
            theDeck->shuffle(9);
        }
