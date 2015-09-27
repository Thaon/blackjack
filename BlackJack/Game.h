#pragma once

#include <memory>

#include "Player.h"

typedef std::vector<Player> PlayersVector;

class Game
{
private:
	static enum GameState { menu, game, end };
	GameState m_state;
	PlayersVector m_players;
	std::unique_ptr<Player> m_dealer;

public:
	Game();

	void GameSetup();

	void Update();

	std::string AskForPlayerName(int playerNumber, bool isAI);

	int AskForPlayersNumber();

	int AskForAIPlayersNumber();

	//getters

	//setters
	GameState SetState(GameState newState);
};