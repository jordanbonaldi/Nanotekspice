/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_2716
*/

#include "Chip_2716.hpp"

Chip_2716::Chip_2716(const std::string &s) : AComponent(s, 24, "2716")
{
}

Chip_2716::~Chip_2716()
{
}

nts::Tristate Chip_2716::compute(std::size_t pin)
{
	if (!this->pins[pin])
		throw nts::PinUnknown("error");
	return nts::Tristate::UNDEFINED;
}
