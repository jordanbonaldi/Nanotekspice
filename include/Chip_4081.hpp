/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4081
*/

#ifndef Chip_4081_hpp
	#define Chip_4081_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4081 : public nts::AComponent
{
public:
	Chip_4081(const std::string &s);
	~Chip_4081();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4081_hpp */
