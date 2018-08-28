/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4071
*/

#ifndef Chip_4071_hpp
	#define Chip_4071_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4071 : public nts::AComponent
{
public:
	Chip_4071(const std::string &s);
	~Chip_4071();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4071_hpp */
