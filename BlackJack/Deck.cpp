#include "stdafx.h"

#include "Deck.h"

CardVector m_cards;

int Deck::GetRandomNumber() //utility
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 51);
	//return rand() % 52 + 1;
	return dist(mt);
}

Deck::Deck() : m_cards(51)
{
	m_cards[0] = Card("Ace of spades", 1, 11);
	m_cards[1] = Card("Two of Spades", 2);
	m_cards[2] = Card("Three of Spades", 3);
	m_cards[3] = Card("Four of Spades", 4);
	m_cards[4] = Card("Five of Spades", 5);
	m_cards[5] = Card("Six of Spades", 6);
	m_cards[6] = Card("Seven of Spades", 7);
	m_cards[7] = Card("Eight of Spades", 8);
	m_cards[8] = Card("Nine of Spades", 9);
	m_cards[9] = Card("Ten of Spades", 10);
	m_cards[10] = Card("Jack of Spades", 10);
	m_cards[11] = Card("Queen of Spades", 10);
	m_cards[12] = Card("King of Spades", 10);

	m_cards[13] = Card("Ace of hearts", 1, 11);
	m_cards[14] = Card("Two of hearts", 2);
	m_cards[15] = Card("Three of hearts", 3);
	m_cards[16] = Card("Four of hearts", 4);
	m_cards[17] = Card("Five of hearts", 5);
	m_cards[18] = Card("Six of hearts", 6);
	m_cards[19] = Card("Seven of hearts", 7);
	m_cards[20] = Card("Eight of hearts", 8);
	m_cards[21] = Card("Nine of hearts", 9);
	m_cards[22] = Card("Ten of hearts", 10);
	m_cards[23] = Card("Jack of hearts", 10);
	m_cards[24] = Card("Queen of hearts", 10);
	m_cards[25] = Card("King of hearts", 10);

	m_cards[26] = Card("Ace of clubs", 1, 11);
	m_cards[27] = Card("Two of clubs", 2);
	m_cards[28] = Card("Three of clubs", 3);
	m_cards[29] = Card("Four of clubs", 4);
	m_cards[30] = Card("Five of clubs", 5);
	m_cards[31] = Card("Six of clubs", 6);
	m_cards[32] = Card("Seven of clubs", 7);
	m_cards[33] = Card("Eight of clubs", 8);
	m_cards[34] = Card("Nine of clubs", 9);
	m_cards[35] = Card("Ten of clubs", 10);
	m_cards[36] = Card("Jack of clubs", 10);
	m_cards[37] = Card("Queen of clubs", 10);
	m_cards[38] = Card("King of clubs", 10);

	m_cards[39] = Card("Ace of diamonds", 1, 11);
	m_cards[40] = Card("Two of diamonds", 2);
	m_cards[41] = Card("Three of diamonds", 3);
	m_cards[42] = Card("Four of diamonds", 4);
	m_cards[43] = Card("Five of diamonds", 5);
	m_cards[44] = Card("Six of diamonds", 6);
	m_cards[45] = Card("Seven of diamonds", 7);
	m_cards[46] = Card("Eight of diamonds", 8);
	m_cards[47] = Card("Nine of diamonds", 9);
	m_cards[48] = Card("Ten of diamonds", 10);
	m_cards[49] = Card("Jack of diamonds", 10);
	m_cards[50] = Card("Queen of diamonds", 10);
	m_cards[51] = Card("King of diamonds", 10);
}

Card Deck::DrawCard(std::shared_ptr<Deck> deck)//does not yet remove the drawn card, fix this later on!!!
{
	int CardNumber = GetRandomNumber();
	return deck->Cards()[CardNumber];
}

//getters
CardVector Cards() { return m_cards; }
CardVector::size_type Size() { return m_cards.size(); }

//again, no setters for now