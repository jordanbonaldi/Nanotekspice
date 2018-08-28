/*
** EPITECH PROJECT, 2018
** Clock
** File description:
** Implementation of Clock
*/

#include "Clock.hpp"

Clock::Clock(const std::string &s) : AComponent(s, 1, "clock")
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
	if (pin - 1 > 0)
		throw nts::PinUnknown("error");
	return this->value;
}

void Clock::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin - 1 < this->numberOfPins && !this->pins.at(pin - 1)) {
		this->pins[pin - 1] = &other;
		other.setLink(otherPin, *this, pin);
	} else if (pin > this->numberOfPins)
		throw nts::PinUnknown("error");
}

void Clock::dump() const
{
	std::cout << "clock : " << name << std::endl;
	std::cout << "clock value : " << this->value << std::endl;
	std::cout << "linked : " << (this->pins.at(0) ? "yes" : "no") << std::endl;
}
