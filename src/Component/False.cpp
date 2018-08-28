/*
** EPITECH PROJECT, 2018
** False
** File description:
** Implementation of False
*/

#include "False.hpp"

False::False(const std::string &s) : nts::AComponent(s, 1, "false")
{
	value = nts::FALSE;
}

nts::Tristate False::compute(std::size_t pin)
{
	if (pin - 1 > 0)
		throw nts::PinUnknown("error");
	return this->value;
}

void False::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin - 1 < this->numberOfPins && !this->pins.at(pin - 1)) {
		this->pins[pin - 1] = &other;
		other.setLink(otherPin, *this, pin);
	} else if (pin > this->numberOfPins)
		throw nts::PinUnknown("error");
}

void False::dump() const
{
	std::cout << "false : " << name << std::endl;
	std::cout << "false value : " << this->value << std::endl;
	std::cout << "linked : " << (this->pins.at(0) ? "yes" : "no") << std::endl;
}
