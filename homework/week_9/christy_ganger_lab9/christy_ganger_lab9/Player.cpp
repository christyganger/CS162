/*CIS 162c++
week 9 blackjack
Written by  jim bailey,
This specific file, and modifications made by christy ganger
*/
#include "Player.h"
#include "Dealer.h"

        Player::Player()
        {
            this->myHand = new BlackJackHand();
        }

		Player::Player(int stake)
		{
            setStake(stake);
		}

		Player::~Player()
		{
            delete myHand;
		}

		bool Player::takeCard(PlayingCard *c)
		{
            return myHand->addCard(c);
        }

		std::string Player::showHand()
		{
            return myHand->getAllCardCodes();
		}

		int Player::getLowScore()
		{
            return myHand->getLowScore();
		}

		int Player::getHighScore()
		{
            return myHand->getHighScore();
		}

		int Player::getScore()
		{
            if(getHighScore() > 21)
            {
                return getLowScore();
            }
            return getHighScore();
		}

		bool Player::busted()
		{
            return myHand->isBust();
		}

		bool Player::wantCard()
		{

            if(getScore() < 16)
            {
                return true;
            }
            return false;
		}

		void Player::clearHand()
		{
            myHand->clearHand();
		}

		void Player::setStake(int stake1)
		{
            this->stake = stake1;
		}

		int Player::getStake()
		{
            return this->stake;
		}

		bool Player::makeBet(int bet)
		{
            if(bet <= getStake())
            {
                this->bet = bet;
                return true;
            }
            return false;
		}

		void Player::won()
		{
            this->stake += this->bet;
		}

		void Player::lost()
		{
            this->stake -= this->bet;
		}
