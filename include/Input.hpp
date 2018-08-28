/*
** EPITECH PROJECT, 2018
** Input
** File description:
** Declaration of Input
*/

#ifndef NANOTEKSPICE_INPUT_HPP
#define NANOTEKSPICE_INPUT_HPP

#include "AComponent.hpp"

class Input : public nts::AComponent
{
public:
	Input(const std::string &);
	nts::Tristate compute(std::size_t) final;
	void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) final;
	void dump() const final;
private:
};


#endif //NANOTEKSPICE_INPUT_HPP
