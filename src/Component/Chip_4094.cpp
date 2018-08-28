/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4094
*/

#include "Chip_4094.hpp"

Chip_4094::Chip_4094(const std::string &s) : AComponent(s, 16, "4094")
{
	this->clock_state = false;
	this->pin = 0;
}

Chip_4094::~Chip_4094()
{
}

void Chip_4094::update()
{
	if (this->init && this->clock_state)
		return;
	this->pin ++;
	this->init = true;
}

nts::Tristate Chip_4094::compute(std::size_t pin)
{
	auto clocks = nts::Circuit::getInstance()->getClocks();
	auto outputs = nts::Circuit::getInstance()->getOutputs();
	auto inputs = nts::Circuit::getInstance()->getInputs();
	bool on = clocks.at(0)->getValue() == nts::Tristate::TRUE;

	if ((size_t)this->pin >= outputs.size() - 1 ||
		(!on && (size_t)this->pin >= outputs.size() - 2)) {
		std::for_each(outputs.begin(), outputs.end(), [](Output *out){
			out->setValue(1);
		});
		this->clock_state = on;
		return nts::Tristate::TRUE;
	}
	this->clock_state = on;
	if (!this->init)
		std::for_each(outputs.begin(), outputs.end(), [](Output *out){
			out->setValue(0);
		});
	std::for_each(outputs.begin(), outputs.end(), [](Output *out){
		out->setValue(0);
	});
	for (size_t i = 0; i < (size_t)this->pin; i++) {
		outputs[i]->setValue(1);
	}
	if ((size_t)this->pin >= outputs.size() - 2)
		outputs[outputs.size() - 2]->setValue(1);
	if (pin == 8) {
		std::cout << "Invalid VSS" << std::endl;
		return nts::Tristate::UNDEFINED;
	} else if (pin == 16) {
		std::cout << "Invalid VDD" << std::endl;
		return nts::Tristate::UNDEFINED;
	}
	return nts::Tristate::FALSE;
}
