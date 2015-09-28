#include "stdafx.h"

#include "Game.h"

typedef std::vector<Player> PlayersVector;


Game::Game() :
	m_players(2),
	m_state(menu)
{
}

void Game::GameSetup()
{
	std::shared_ptr<Deck> m_deck = std::make_unique<Deck>();
	int numberOfPlayers = AskForPlayersNumber();
	int numberOfAIPlayers = AskForAIPlayersNumber();
	m_players.reserve(numberOfPlayers);
	m_players.resize(numberOfPlayers);
	int AIPlayers = numberOfAIPlayers;
	for (int i = 0; i < numberOfPlayers; ++i)
	{
		if (AIPlayers > 0)
		{
			std::string playerName = AskForPlayerName(i, true);
			m_players[i] = Player(playerName, m_deck);
			m_players[i].SetAI(true);
			AIPlayers--;
		}
		else
		{
			std::string playerName = AskForPlayerName(i, false);
			m_players[i] = Player(playerName, m_deck);
			m_players[i].SetAI(false);
		}
	}
	//create the Dealer
	std::unique_ptr<Player> m_dealer = std::make_unique<Player>();
	m_dealer->SetDealer(true);
}

void Game::Run()
{
	while (m_state == menu)
	{
		//do menu stuff here
	}

	while (m_state == game)
	{
		//set up game
		GameSetup();

		//for each player do player->update
		for (int i = 0; i < m_players.size(); ++i)
		{
			m_players[i].Update();
		}

		//for the dealer do dealer->update
		m_dealer->Update();

		//go to each according end screen
	}
}

std::string Game::AskForPlayerName(int playerNumber, bool isAI)
{
	std::string name;
	if (isAI)
	{
		std::cout << "Please insert the name for AI player number " << playerNumber << ": ";
	}
	else
	{
		std::cout << "Please insert the name for human player number " << playerNumber << ": ";
	}
	std::cin >> name;
	std::cout << std::endl;
	return name;
}

int Game::AskForPlayersNumber()
{
	int playersNumber;
	std::cout << "Please insert the total number of players, including AI players: ";
	std::cin >> playersNumber;
	std::cout << std::endl;
	return playersNumber;
}

int Game::AskForAIPlayersNumber()
{
	int AIplayersNumber;
	std::cout << "Please insert the number of AI players: ";//CHECK IF THERE ARE TOO MANY AI PLAYERS!!!!!!!!!!!!!!!!!!!!!
	std::cin >> AIplayersNumber;
	std::cout << std::endl;
	return AIplayersNumber;
}

//getters

//setters
void Game::SetState(GameState newState) { m_state = newState; }
