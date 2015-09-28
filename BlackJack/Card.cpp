#include "stdafx.h"

#include "Card.h"

Card::Card()
{
	m_name = "default";
	m_value = 0;
	m_alternateValue = -1;
}

Card::Card(const std::string name, short int value) :
m_name(name),
m_value(value),
m_alternateValue(-1)
{
}

Card::Card(const std::string name, short int value, short int alternateValue) :
m_name(name),
m_value(value),
m_alternateValue(alternateValue)
{
}

//getters
std::string Card::Name() const { return m_name; }
int Card::Value() { return m_value; }
int Card::AlternateValue() { return m_alternateValue; }