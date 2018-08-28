/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4017
*/

#include "Chip_4017.hpp"

Chip_4017::Chip_4017(const std::string &s) : AComponent(s, 16, "4017")
{
	this->clock_state = false;
	this->pin = 1;
}

Chip_4017::~Chip_4017()
{
}

void Chip_4017::update()
{
	if (this->init && this->clock_state)
		return;
	if (this->pin >= 10) {
		this->pin = 1;
		//nts::Circuit::getInstance()->getOutputs()[1]->setValue(1);
	}
	else
		this->pin ++;
	this->init = true;
}

nts::Tristate Chip_4017::compute(std::size_t pin)
{
	auto clocks = nts::Circuit::getInstance()->getClocks();
	auto outputs = nts::Circuit::getInstance()->getOutputs();
	auto inputs = nts::Circuit::getInstance()->getInputs();
	int counter = 0;
	bool on = clocks.at(0)->getValue() == nts::Tristate::TRUE;
	bool reset = inputs[0]->getValue() == nts::Tristate::TRUE;

	if (reset) {
		outputs[1]->setValue(1);
		this->pin = 1;
		return nts::Tristate::TRUE;
	}
	std::for_each(outputs.begin(), outputs.end(), [&](Output *output) {
		if (counter)
			output->setValue(0);
		else
			output->setValue(on);
		counter++;
	});
	this->clock_state = on;
	if (!on)
		outputs[this->init ? this->pin : 1]->setValue(1);
	else
		outputs[this->init ? this->pin : 2]->setValue(1);
	if (pin == 8) {
		std::cout << "Invalid VSS" << std::endl;
		return nts::Tristate::UNDEFINED;
	} else if (pin == 16) {
		std::cout << "Invalid VDD" << std::endl;
		return nts::Tristate::UNDEFINED;
	}
	return this->pin >= 6 ? nts::Tristate::FALSE : nts::Tristate::TRUE;
}
