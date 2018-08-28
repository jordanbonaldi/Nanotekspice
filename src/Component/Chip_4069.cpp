/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4069
*/

#include "Chip_4069.hpp"

Chip_4069::Chip_4069(const std::string &s) : AComponent(s, 14, "4069")
{
	this->outputslinks[2] = std::make_pair(1, 0);
	this->outputslinks[4] = std::make_pair(3, 0);
	this->outputslinks[6] = std::make_pair(5, 0);
	this->outputslinks[8] = std::make_pair(9, 0);
	this->outputslinks[10] = std::make_pair(11, 0);
	this->outputslinks[12] = std::make_pair(13, 0);
}

Chip_4069::~Chip_4069()
{
}

nts::Tristate Chip_4069::compute(std::size_t pin)
{
	if (pin <= 13 && (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13))
		return this->pins.at(pin - 1) ?
			this->pins.at(pin - 1)->compute(this->links.at(pin - 1)) :
			nts::Tristate::UNDEFINED;
	else if (pin < 13 && pin != 7 && this->pins.at(this->outputslinks[pin].first - 1) &&
		this->pins.at(this->outputslinks[pin].first - 1)
			->compute(this->links.at(this->outputslinks[pin].first - 1)) != nts::Tristate::UNDEFINED)
		return static_cast<nts::Tristate>(!
			static_cast<int>(this->pins.at(this->outputslinks[pin].first - 1)
				->compute(this->links.at(this->outputslinks[pin].first - 1))));
	if (pin == 7)
		std::cout << "Invalid VSS" << std::endl;
	else if (pin == 14)
		std::cout << "Invalid VDD" << std::endl;
	return nts::Tristate::UNDEFINED;
}
