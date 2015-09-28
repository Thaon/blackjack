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
	Card DrawCard(std::shared_ptr<Deck> deck);

	//getters
	CardVector Cards();
	CardVector::size_type Size();

	//again, no setters for now
};