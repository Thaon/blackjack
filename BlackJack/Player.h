#pragma once

#include "Deck.h"

class Player
{
private:
	std::string m_name;
	CardVector m_cards;
	bool m_isAI;
	bool m_isDealer;

public:
	Player();

	Player(std::string name);

	int GetPoints();

	void Update();

	//setters
	void SetAI(bool setAI);
	void SetDealer(bool setDealer);

	//getters
	std::string Name();
	int Points();
	CardVector Cards();
	bool IsAI();
	bool IsDealer();
};