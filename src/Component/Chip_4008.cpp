/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4008
*/

#include "Chip_4008.hpp"

Chip_4008::Chip_4008(const std::string &name) : AComponent(name, 16, "4008")
{
	this->outputslinks[10] = std::make_pair(6, 7);
	this->outputslinks[11] = std::make_pair(4, 5);
	this->outputslinks[12] = std::make_pair(2, 3);
	this->outputslinks[13] = std::make_pair(1, 15);
}

Chip_4008::~Chip_4008()
{
}

nts::Tristate Chip_4008::compute(std::size_t pin)
{
	nts::Tristate add_va = nts::Tristate::FALSE;
	nts::Tristate ret_va = nts::Tristate::UNDEFINED;
	nts::Tristate a_va = nts::Tristate::UNDEFINED;
	nts::Tristate b_va = nts::Tristate::UNDEFINED;
	char test = 0;
	bool toto = false;

	if (pin == 14)
		toto = true;
	if (this->pins.at(8))
		add_va = this->pins.at(8)->compute(this->links.at(8));
	if (pin < 8 || pin == 15 || pin == 9)
		return this->pins.at(pin - 1) ?
			this->pins.at(pin - 1)->compute(this->links.at(pin - 1)) :
			nts::Tristate::UNDEFINED;
	else if (toto || (pin >= 10 && pin < 14)) {
		if (toto) pin--;
		for (size_t i = 10; i <= pin; i++) {
			if (this->outputslinks.find(i) != this->outputslinks.end() &&
				this->pins.at(this->outputslinks.at(i).first - 1) &&
				this->pins.at(this->outputslinks.at(i).second - 1)) {
					a_va = this->pins.at(this->outputslinks.at(i).first - 1)->compute(this->links.at(this->outputslinks.at(i).first - 1));
					b_va = this->pins.at(this->outputslinks.at(i).second - 1)->compute(this->links.at(this->outputslinks.at(i).second - 1));
					test = (char)a_va + (char)b_va + (char)add_va;
					add_va = static_cast<nts::Tristate>(test >> 1);
					ret_va = static_cast<nts::Tristate>(test & 1);
				}
		}
	}
	if (pin == 8) {
		std::cout << "Invalid VSS" << std::endl;
		return nts::Tristate::UNDEFINED;
	} else if (pin == 16) {
		std::cout << "Invalid VDD" << std::endl;
		return nts::Tristate::UNDEFINED;
	}
	if (toto)
		return add_va;
	return ret_va;
}
