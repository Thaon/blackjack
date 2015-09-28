#pragma once

#include "Player.h"

typedef std::vector<Player> PlayersVector;

class Game
{
private:
	enum GameState { menu, game, end };
	GameState m_state;
	Deck m_deck;
	PlayersVector m_players;
	std::unique_ptr<Player> m_dealer;

public:
	Game();

	void GameSetup();

	void Run();

	std::string AskForPlayerName(int playerNumber, bool isAI);

	int AskForPlayersNumber();

	int AskForAIPlayersNumber();

	//getters

	//setters
	void SetState(GameState newState);
};