/*
** EPITECH PROJECT, 2018
** Input
** File description:
** Implementation of Input
*/

#include "Input.hpp"

Input::Input(const std::string &s) : nts::AComponent(s, 1, "input")
{
}

nts::Tristate Input::compute(std::size_t pin)
{
	if (pin - 1 > 0)
		throw nts::PinUnknown("errorinput");
	return this->value;
}

void Input::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin - 1 < this->numberOfPins && !this->pins.at(pin - 1)) {
		this->pins[pin - 1] = &other;
		other.setLink(otherPin, *this, pin);
	} else if (pin > this->numberOfPins)
		throw nts::PinUnknown("errorsetlinkinput");
}

void Input::dump() const
{
	std::cout << "input : " << name << std::endl;
	std::cout << "input value : " << this->value << std::endl;
	std::cout << "linked : " << (this->pins.at(0) ? "yes" : "no") << std::endl;
}
