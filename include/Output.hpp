/*
** EPITECH PROJECT, 2018
** Output
** File description:
** Declaration of Output
*/

#ifndef NANOTEKSPICE_OUTPUT_HPP
#define NANOTEKSPICE_OUTPUT_HPP

#include "AComponent.hpp"

class Output : public nts::AComponent
{
public:
	Output(const std::string &);

	virtual nts::Tristate compute(std::size_t pin = 1) final;
	virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) final;
	virtual void dump() const final;
private:
	size_t links;
};


#endif //NANOTEKSPICE_OUTPUT_HPP
