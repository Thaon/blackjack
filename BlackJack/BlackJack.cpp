#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>


//utility functions
static int GetRandomCard()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 51);
	//return rand() % 52 + 1;
	return dist(mt);
}

static void Pause()
{
	std::cout << "Press any key to continue...\n";
	std::cin.sync(); // Flush The Input Buffer Just In Case
	std::cin.ignore(); // There's No Need To Actually Store The Users Input
}

class Card
{
public:
	Card()
	{
		m_name = "default";
		m_value = 0;
		m_alternateValue = -1;
	}

	Card(const std::string name, short int value) :
		m_name(name),
		m_value(value),
		m_alternateValue(-1)
	{
	}

	Card(const std::string name, short int value, short int alternateValue) :
		m_name(name),
		m_value(value),
		m_alternateValue(alternateValue)
	{
	}

	//getters
	std::string Name() const { return m_name; }
	int Value() { return m_value; }
	int AlternateValue() { return m_alternateValue; }

	//no setters for now

private:
	short int m_value;
	short int m_alternateValue;
	std::string m_name;
};

typedef std::vector<Card> CardVector;

class Deck
{
public:
	Deck() : m_cards(51)
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
		m_cards[10] = Card("Knight of Spades", 10);
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
		m_cards[23] = Card("Knight of hearts", 10);
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
		m_cards[36] = Card("Knight of clubs", 10);
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
		m_cards[49] = Card("Knight of diamonds", 10);
		m_cards[50] = Card("Queen of diamonds", 10);
		m_cards[51] = Card("King of diamonds", 10);
	}

	Card DrawCard(Deck deck)
	{
		int CardNumber = GetRandomCard();
		return deck.cards()[CardNumber];
	}

	//getters
	CardVector cards() { return m_cards; }
	CardVector::size_type size() { return m_cards.size(); }

	//again, no setters for now

private:
	CardVector m_cards;
};

class Player
{
public:
	Player() :
		m_name("Player"),
		m_isAI(false)
	{
	}

	Player(std::string name) :
		m_name(name),
		m_isAI(false)
	{
	}

	int GetPoints()
	{
		int points = 0;
		int altValueCards = 0;
		for (CardVector::size_type i = 0; i < Cards().size(); ++i)
		{
			if (Cards()[i].AlternateValue() != -1)
			{
				points += Cards()[i].Value();
			}
			else
			{
				altValueCards++;
			}
		}
		for (int i = 0; i < altValueCards; i++)//if there are cards in hand with alternate value, we try and calculate the best outcome for the player
		{
			if (points + 11 > 21)
			{
				points++;
			}
			else
			{
				points += 11;
			}
		}
		return points;
	}

	void Update()
	{

	}

	void Draw()
	{

	}

	//setters
	void SetAI(bool setAI) { m_isAI = setAI; }

private:
	std::string m_name;
	CardVector m_cards;
	bool m_isAI;

	//getters
	std::string Name() { return m_name; }
	int Points() { return GetPoints(); }
	CardVector Cards() { return m_cards; }
	bool IsAI() { return m_isAI;  }
};

typedef std::vector<Player> PlayersVector;

class Game
{
public:
	Game() :
		m_players(2),
		m_state(menu)
	{
	}

	void GameSetup()
	{
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
				m_players[i] = Player(playerName);
				m_players[i].SetAI(true);
				AIPlayers--;
			}
			else
			{
				std::string playerName = AskForPlayerName(i, false);
				m_players[i] = Player(playerName);
				m_players[i].SetAI(false);
			}
		}
	}

	void Update()
	{

	}

	void Draw()
	{

	}

	std::string AskForPlayerName(int playerNumber, bool isAI)
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

	int AskForPlayersNumber()
	{
		int playersNumber;
		std::cout << "Please insert the total number of players, including AI players: ";
		std::cin >> playersNumber;
		std::cout << std::endl;
		return playersNumber;
	}

	int AskForAIPlayersNumber()
	{
		int AIplayersNumber;
		std::cout << "Please insert the number of AI players: ";//CHECK IF THERE ARE TOO MANY AI PLAYERS!!!!!!!!!!!!!!!!!!!!!
		std::cin >> AIplayersNumber;
		std::cout << std::endl;
		return AIplayersNumber;
	}

private:
	enum GameState { menu, game, end };
	GameState m_state = menu;
	PlayersVector m_players;
	//getters

	//setters
	GameState SetState(GameState newState) { m_state = newState; }
};

void main()
{
	Deck deck;
	//for (CardVector::const_iterator iter = deck.cards().begin(); iter != deck.cards().end(); ++iter)
	//{
	//	std::cout << iter->Name();
	//}
	/*
	for (CardVector::size_type i = 0; i < deck.cards().size(); i++)
	{
		std::cout << deck.cards()[i].Name() << std::endl;
	}
	Pause();
	int times = 0;
	
	while (times < 5)
	{
		std::cout << deck.DrawCard(deck).Name() << std::endl;
		Pause();
		times++;
	}
	*/
	//std::unique_ptr<Game> blackJack(new Game());
	std::unique_ptr<Game> blackJack = std::make_unique<Game>();
	blackJack->GameSetup();
	Pause();
}
