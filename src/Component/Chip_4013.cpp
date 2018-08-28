/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4013
*/

#include "Chip_4013.hpp"

Chip_4013::Chip_4013(const std::string &s) : AComponent(s, 14, "4013")
{
}

Chip_4013::~Chip_4013()
{
}

nts::Tristate Chip_4013::compute(std::size_t pin)
{
	auto clocks = nts::Circuit::getInstance()->getClocks();
	auto outputs = nts::Circuit::getInstance()->getOutputs();
	auto inputs = nts::Circuit::getInstance()->getInputs();

	if (!this->pins[pin - 1])
		throw nts::PinUnknown("error");
	outputs[0]->setValue(clocks[0]->getValue());
	return nts::Tristate::UNDEFINED;
}
