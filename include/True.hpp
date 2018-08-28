/*
** EPITECH PROJECT, 2018
** True
** File description:
** Declaration of True
*/

#ifndef NANOTEKSPICE_TRUE_HPP
#define NANOTEKSPICE_TRUE_HPP

#include "AComponent.hpp"

class True : public nts::AComponent
{
public:
	True(const std::string &);
	nts::Tristate compute(std::size_t) final;
	void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) final;
	void dump() const final;
private:
};


#endif //NANOTEKSPICE_TRUE_HPP
