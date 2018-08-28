/*
** EPITECH PROJECT, 2018
** Output
** File description:
** Implementation of Output
*/

#include "Circuit.hpp"
#include "Output.hpp"

Output::Output(const std::string &s) : nts::AComponent(s, 1, "output")
{
}

nts::Tristate Output::compute(std::size_t pin)
{
	if (pin - 1 > 0)
		throw nts::PinUnknown("errorcompute");
	if (!this->pins.at(0) && pin == 1)
		return nts::Tristate::UNDEFINED;
	this->value = this->pins[pin - 1]->compute(this->links);
	return this->value;
}

void Output::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin - 1 < this->numberOfPins && !this->pins.at(pin - 1)) {
		this->links = otherPin;
		this->pins[pin - 1] = &other;
		other.setLink(otherPin, *this, pin);
	} else if (pin > this->numberOfPins)
		throw nts::PinUnknown("errorsetlink");
}

void Output::dump() const
{
	std::cout << "Output : " << name << std::endl;
	std::cout << "Output value : " << this->value << std::endl;
	std::cout << "linked : " << (this->pins.at(0) ? "yes" : "no") << std::endl;
}
