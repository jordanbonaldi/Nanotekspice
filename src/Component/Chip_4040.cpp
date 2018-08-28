/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4040
*/

#include "Chip_4040.hpp"

Chip_4040::Chip_4040(const std::string &s) : AComponent(s, 16, "4040")
{
	this->clock_state = false;
}

Chip_4040::~Chip_4040()
{
}

void Chip_4040::update()
{
	if (this->init && this->clock_state)
		return;
	if (this->pin > 15)
		this->pin = 0;
	else
		this->pin ++;
	this->init = true;
}

nts::Tristate Chip_4040::compute(std::size_t pin)
{
	if (!this->pins[pin - 1])
		throw nts::PinUnknown("error");
	return nts::Tristate::UNDEFINED;
}
