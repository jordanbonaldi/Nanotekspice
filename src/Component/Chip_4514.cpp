/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4514
*/

#include "Chip_4514.hpp"

Chip_4514::Chip_4514(const std::string &s) : AComponent(s, 24, "4514")
{
}

Chip_4514::~Chip_4514()
{
}

nts::Tristate Chip_4514::compute(std::size_t pin)
{
	auto inputs = nts::Circuit::getInstance()->getInputs();
	auto outputs = nts::Circuit::getInstance()->getOutputs();

	if (!this->pins[pin - 1])
		throw nts::PinUnknown("error");
	std::for_each(outputs.begin(), outputs.end(), [](Output *out){
		out->setValue(0);
	});
	outputs[0]->setValue(inputs.at(4)->getValue());
	return nts::FALSE;
}
