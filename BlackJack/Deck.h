#pragma once

#include <vector>
#include <random>

#include "Card.h"

typedef std::vector<Card> CardVector;

class Deck
{
private:
	CardVector m_cards;
public:
	int GetRandomNumber();
	Deck();
	Card DrawCard(Deck deck);

	//getters
	CardVector cards();
	CardVector::size_type size();

	//again, no setters for now
};