#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>

#include "Player.h"


static void Pause()
{
	std::cout << "Press any key to continue...\n";
	std::cin.sync(); // Flush The Input Buffer Just In Case
	std::cin.ignore(); // There's No Need To Actually Store The Users Input
}

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
