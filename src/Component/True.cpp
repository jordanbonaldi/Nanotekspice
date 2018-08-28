/*
** EPITECH PROJECT, 2018
** True
** File description:
** Implementation of True
*/

#include "True.hpp"

True::True(const std::string &s) : nts::AComponent(s, 1, "true")
{
	value = nts::TRUE;
}

nts::Tristate True::compute(std::size_t pin)
{
	if (pin - 1 > 0)
		throw nts::PinUnknown("error");
	return this->value;
}

void True::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin - 1 < this->numberOfPins && !this->pins.at(pin - 1)) {
		this->pins[pin - 1] = &other;
		other.setLink(otherPin, *this, pin);
	} else if (pin > this->numberOfPins)
		throw nts::PinUnknown("error");
}

void True::dump() const
{
	std::cout << "true : " << name << std::endl;
	std::cout << "true value : " << this->value << std::endl;
	std::cout << "linked : " << (this->pins.at(0) ? "yes" : "no") << std::endl;
}
