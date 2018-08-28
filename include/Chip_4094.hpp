/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4094
*/

#ifndef Chip_4094_hpp
	#define Chip_4094_hpp

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

class Chip_4094 : public nts::AComponent
{
public:
	Chip_4094(const std::string &s);
	~Chip_4094();

	void update() final;
	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
	bool clock_state;
};

#endif /* Chip_4094_hpp */
