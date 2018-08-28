/*
** EPITECH PROJECT, 2018
** Clock
** File description:
** Declaration of Clock
*/

#ifndef NANOTEKSPICE_CLOCK_HPP
#define NANOTEKSPICE_CLOCK_HPP

#include "AComponent.hpp"

class Clock : public nts::AComponent
{
public:
	Clock(const std::string &);
	nts::Tristate compute(std::size_t) final;
	void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) final;
	void dump() const final;
private:
};


#endif //NANOTEKSPICE_CLOCK_HPP
