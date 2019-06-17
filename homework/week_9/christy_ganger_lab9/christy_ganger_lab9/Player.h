/*CIS 162c++
week 9 blackjack
Written by  jim bailey,
This specific file, and modifications made by christy ganger
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "BlackJackHand.h"


class Player
{

	private:
	    int stake;
	    int bet;

	protected:
		BlackJackHand *myHand;

	public:
		Player();
		Player(int stake);
		~Player();
		bool takeCard(PlayingCard *c);
		std::string showHand();
		int getLowScore();
		int getHighScore();
		int getScore();
		bool busted();
		bool wantCard();
		void clearHand();
		void setStake(int stake);
		int getStake();
		bool makeBet(int bet);
		void won();
		void lost();
};

#endif // PLAYER_H
