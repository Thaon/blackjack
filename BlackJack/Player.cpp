#include "Player.h"

	Player::Player() :
		m_name("Player"),
		m_isAI(false),
		m_isDealer(false)
	{
	}

	Player::Player(std::string name) :
		m_name(name),
		m_isAI(false),
		m_isDealer(false)
	{
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

	void Player::Update()
	{

	}

	//getters
	std::string Player::Name() { return m_name; }
	int Player::Points() { return GetPoints(); }
	CardVector Player::Cards() { return m_cards; }
	bool Player::IsAI() { return m_isAI; }
	bool Player::IsDealer() { return m_isDealer; }

	//setters
	void Player::SetDealer(bool setDealer) { m_isDealer = setDealer; }