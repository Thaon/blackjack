#include "stdafx.h"

#include "Player.h"


Player::Player()
	{
	}
Player::Player(std::shared_ptr<Deck> gameDeck) :
		m_gameDeck(gameDeck),
		m_name("Player"),
		m_isAI(false),
		m_isDealer(false),
		m_state(playing),
		m_cards(12)// 4! - 3
	{
		//fille the hand with empty cards first
		for (auto iterator = 0; iterator < m_cards.size(); ++iterator)
		{
			m_cards[iterator] = Card("No Card", -1);
		}

		//start the game with two cards in hand
		m_cards[0] = m_gameDeck->DrawCard(m_gameDeck);
		m_cards[1] = m_gameDeck->DrawCard(m_gameDeck);
	}

Player::Player(std::string name, std::shared_ptr<Deck> gameDeck) :
		m_gameDeck(gameDeck),
		m_name(name),
		m_isAI(false),
		m_isDealer(false),
		m_state(playing),
		m_cards(12)// 4! - 3

	{
		//same here
		for (auto iterator = 0; iterator < m_cards.size(); ++iterator)
		{
			m_cards[iterator] = Card("No Card", -1);
		}
		m_cards[0] = m_gameDeck->DrawCard(m_gameDeck);
		m_cards[1] = m_gameDeck->DrawCard(m_gameDeck);
	}

	void Player::DrawCard()
	{
		//find the first available empty card slot
		for (auto iterator = 0; iterator < m_cards.size(); ++iterator)
		{
			if (m_cards[iterator].Value() != -1)
			{
				//put a card in there :P
				m_cards[iterator] = m_gameDeck->DrawCard(m_gameDeck);
				return;
			}
		}
	}

	int Player::GetPoints()
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

	void Player::ShowCards()
	{
		std::cout << "the cards in your hand are:" << std::endl;
		for (auto iterator = m_cards.begin(); iterator != m_cards.end(); ++iterator)
		{
			if (iterator->Value() != -1)
				std:: cout << iterator->Name() << std::endl;
		}
		std::cout << "for a total of " << GetPoints() << " points" << std::endl;
	}

	void Player::AskForCommand()
	{
		std::string command;
		std::cout << "do you want to draw another card? (yes/no)" << std::endl;
		std::cin >> command;
		if (command == "yes" || command == "y")
		{
			DrawCard();
			m_state = playing;
		}
		if (command == "no" || command == "n")
		{
			m_state = done;
		}
	}

	void Player::Update()
	{
		//check the player state
		if (m_state == busted)
		{
			std::cout << m_name << " is busted" << std::endl;
			return;
		}
		if (m_state == done)
		{
			std::cout << m_name << " is staying" << std::endl;
			return;
		}
		while (m_state == playing)
		{
			if (!m_isAI)
			{
				//check if the player can play
				if (GetPoints() > 21)
				{
					m_state = busted;
					return;
				}
				//show cards
				ShowCards();
				//ask the player what to do
				AskForCommand();//ask for player action and set m_state accordingly
			}
		}
	}

	//getters
	std::string Player::Name() { return m_name; }
	int Player::Points() { return GetPoints(); }
	CardVector Player::Cards() { return m_cards; }
	bool Player::IsAI() { return m_isAI; }
	bool Player::IsDealer() { return m_isDealer; }

	//setters
	void Player::SetDealer(bool setDealer) { m_isDealer = setDealer; }
	void Player::SetPlayerState(PlayerState newState) { m_state = newState; }