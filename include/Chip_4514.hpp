/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4514
*/

#ifndef Chip_4514_hpp
	#define Chip_4514_hpp

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

class Chip_4514 : public nts::AComponent
{
public:
	Chip_4514(const std::string &s);
	~Chip_4514();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4514_hpp */
