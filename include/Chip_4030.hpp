/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4030
*/

#ifndef Chip_4030_hpp
	#define Chip_4030_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4030 : public nts::AComponent
{
public:
	Chip_4030(const std::string &s);
	~Chip_4030();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4030_hpp */
