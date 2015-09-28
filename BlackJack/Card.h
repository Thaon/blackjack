#pragma once

#include <iostream>
#include <string>
#include <memory>

class Card
{
private:
	short int m_value;
	short int m_alternateValue;
	std::string m_name;

public:
	Card();
	Card(const std::string name, short int value);
	Card::Card(const std::string name, short int value, short int alternateValue);

	//getters
	std::string Name() const;
	int Value();
	int AlternateValue();

	//no setters for now
};