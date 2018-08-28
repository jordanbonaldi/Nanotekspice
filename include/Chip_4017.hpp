/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4017
*/

#ifndef Chip_4017_hpp
	#define Chip_4017_hpp

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

class Chip_4017 : public nts::AComponent
{
public:
	Chip_4017(const std::string &s);
	~Chip_4017();

	virtual void update() final;
	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
	bool clock_state;
};

#endif /* Chip_4017_hpp */
