/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4040
*/

#ifndef Chip_4040_hpp
	#define Chip_4040_hpp

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

class Chip_4040 : public nts::AComponent
{
public:
	Chip_4040(const std::string &s);
	~Chip_4040();

	virtual void update() final;
	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
	bool clock_state;
};

#endif /* Chip_4040_hpp */
