/*
** EPITECH PROJECT, 2018
** Terminal
** File description:
** Declaration of Terminal
*/

#ifndef NANOTEKSPICE_TERMINAL_HPP
#define NANOTEKSPICE_TERMINAL_HPP

#include <AComponent.hpp>

class Terminal : public nts::AComponent
{
public:
	Terminal(const std::string &s);
	virtual ~Terminal();
	virtual nts::Tristate compute(std::size_t pin = 1) final;
};


#endif //NANOTEKSPICE_TERMINAL_HPP
