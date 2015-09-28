#pragma once

#include "Deck.h"

class Player
{
private:
	std::string m_name;
	std::shared_ptr<Deck> m_gameDeck;
	CardVector m_cards;
	bool m_isAI;
	bool m_isDealer;
	enum PlayerState {busted, playing, done};
	PlayerState m_state;

public:
	Player();
	Player(std::shared_ptr<Deck> gameDeck);
	Player(std::string name, std::shared_ptr<Deck> gameDeck);

	void DrawCard();

	void ShowCards();

	void AskForCommand();

	int GetPoints();

	void Update();

	//setters
	void SetAI(bool setAI);
	void SetDealer(bool setDealer);
	void SetPlayerState(PlayerState newState);

	//getters
	std::string Name();
	int Points();
	CardVector Cards();
	bool IsAI();
	bool IsDealer();
};