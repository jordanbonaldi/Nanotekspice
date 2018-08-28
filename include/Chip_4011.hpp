/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4011
*/

#ifndef Chip_4011_hpp
	#define Chip_4011_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4011 : public nts::AComponent
{
public:
	Chip_4011(const std::string &s);
	~Chip_4011();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4011_hpp */
