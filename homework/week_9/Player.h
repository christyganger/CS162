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
		int busted();
		bool wantCard();
		void clearHand();
		void setStake(int stake);
		int getStake();
		bool makeBet(int bet);
		void won();
		void lost();
};

#endif // PLAYER_H
