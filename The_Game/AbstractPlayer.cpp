#include "AbstractPlayer.h"

AbstractPlayer::AbstractPlayer(bool human) :
hand(new vector<Card>),
isHuman(human),
maxCardsInHand(6),
canPlayCard(true)
{
	hand->reserve(maxCardsInHand);
}

AbstractPlayer::~AbstractPlayer(){
	delete hand;
	hand = nullptr;
}

void AbstractPlayer::seeHand(){								//shows the players hand
	for (Card card : *hand)cout << card.getValue() << endl;
}

void AbstractPlayer::setHuman(bool setting){
	isHuman = setting;
}

void AbstractPlayer::getMoreCards(Deck &deck,int cardsNeeded){
	if (deck.getRemainingCards() == 0 || cardsNeeded > deck.getRemainingCards())return; //make sure we can take from the deck.
	for (int i = 0; i < cardsNeeded; ++i){
		hand->push_back(deck.m_Cards->at(i));				//add the drawn card to your hand.
	}
	deck.drawNumberOfCards(cardsNeeded);					//remove the drawn cards from the deck.
}

bool AbstractPlayer::checkIsHuman(){						//checks if player is human or not
	return (isHuman) ? true : false;
}

vector<Card>& AbstractPlayer::getHand(){
	return *hand;
}

int AbstractPlayer::checkNeededCards(){
	return maxCardsInHand - hand->size();
}

void AbstractPlayer::display(vector<Card> hand, vector<Pile> piles){
	cout << "----------------" << endl;
	transform(name.begin(), name.end(),name.begin(),toupper);
	cout << name <<" HAND" << endl;
	cout << "----------------\n" << endl;

	int cardNumber = 1;
	for (Card card : hand){
		cout << cardNumber << ") " << card.getValue() << endl;
		cardNumber++;
	}

	cout << "----------------" << endl;
	cout << "PILES" << endl;
	cout << "----------------\n" << endl;

	cout << "DECREASING" << endl;
	cout << "----------" << endl;
	int pileNumber = 1;
	for (Pile pile : piles){
		if (pile.isDecreasingPile()){
			cout << pileNumber << ") " << pile.getCurrentCard() << endl;
			pileNumber++;
		}
	}

	cout << "\nINCREASING" << endl;
	cout << "----------" << endl;
	for (Pile pile : piles){
		if (!pile.isDecreasingPile()){
			cout << pileNumber << ") " << pile.getCurrentCard() << endl;
			pileNumber++;
		}
	}

}