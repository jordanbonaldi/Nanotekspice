/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4071
*/

#include "Chip_4071.hpp"

Chip_4071::Chip_4071(const std::string &s) : AComponent(s, 14, "4071")
{
	this->outputslinks[3] = std::make_pair(1, 2);
	this->outputslinks[4] = std::make_pair(5, 6);
	this->outputslinks[10] = std::make_pair(8, 9);
	this->outputslinks[11] = std::make_pair(12, 13);
}

Chip_4071::~Chip_4071()
{
}

nts::Tristate Chip_4071::compute(std::size_t pin)
{
	if (pin <= 13 && pin != 3 && pin != 4 && pin != 10 && pin != 11 && pin != 7)
		return this->pins.at(pin - 1) ?
			this->pins.at(pin - 1)->compute(this->links.at(pin - 1)) :
			nts::Tristate::UNDEFINED;
	else if (pin < 13 && pin != 7 && this->pins.at(this->outputslinks[pin].first - 1) &&
			this->pins.at(this->outputslinks[pin].second - 1))
		return static_cast<nts::Tristate>(
			static_cast<int>(this->pins.at(this->outputslinks[pin].first - 1)->compute(this->links.at(this->outputslinks[pin].first - 1))) ||
			static_cast<int>(this->pins.at(this->outputslinks[pin].second - 1)->compute(this->links.at(this->outputslinks[pin].second - 1))));
	if (pin == 7)
		std::cout << "Invalid VSS" << std::endl;
	else if (pin == 14)
		std::cout << "Invalid VDD" << std::endl;
	return nts::Tristate::UNDEFINED;
}
