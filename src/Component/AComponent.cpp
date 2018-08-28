/*
** EPITECH PROJECT, 2018
** AComponent
** File description:
** Implementation of AComponent
*/

#include <NTSErrors.hpp>
#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name, size_t nb,
			const std::string &type)
	: name(name), numberOfPins(nb), type(type), value(nts::UNDEFINED)
{
	for (size_t i = 0; i < this->numberOfPins; i++) {
		this->pins[i] = nullptr;
	}
	this->pin = 0;
	this->init = false;
}

void nts::AComponent::update()
{
	this->pin ++;
	this->init = true;
}

const std::string &nts::AComponent::getName() const
{
	return name;
}

size_t nts::AComponent::getNumberOfPins() const
{
	return this->numberOfPins;
}

std::map<size_t, nts::IComponent *> nts::AComponent::getPins() const
{
	return this->pins;
}

void nts::AComponent::reverse()
{
	this->value = static_cast<nts::Tristate>(!static_cast<int>(this->value));
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin <= this->numberOfPins && !this->pins.at(pin - 1)) {
		this->links[pin - 1] = otherPin;
		this->pins[pin - 1] = &other;
		other.setLink(otherPin, *this, pin);
	} else if (pin > this->numberOfPins)
		throw nts::PinUnknown("error on pin " + std::to_string(pin));
}

void nts::AComponent::dump() const
{
	std::cout << "Component name : " << name << std::endl;
	for (size_t i = 0; i < numberOfPins; ++i) {
		std::cout << "Pin number " << i + 1 << " with value ";
		if (this->pins.at(i))
			std::cout << this->pins.at(i)->
				compute(this->links.at(i)) << std::endl;
		else
			std::cout << "error" << std::endl;
	}
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
	(void)pin;
	return FALSE;
}

nts::Tristate nts::AComponent::getValue() const
{
	return value;
}

void nts::AComponent::setValue(int value)
{
	if (value == 1)
		this->value = nts::TRUE;
	else if (value == 0)
		this->value = nts::FALSE;
	else
		throw InputUnknown(this->getName() + " wrong value");
}

const std::string &nts::AComponent::getType() const
{
	return type;
}

std::ostream &operator<<(std::ostream &out, nts::Tristate value)
{
	if (value == nts::TRUE)
		return out << "TRUE";
	else if (value == nts::FALSE)
		return out << "FALSE";
	else
		return out << "UNDEFINED";
}
