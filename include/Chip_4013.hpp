/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4013
*/

#ifndef Chip_4013_hpp
	#define Chip_4013_hpp

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

class Chip_4013 : public nts::AComponent
{
public:
	Chip_4013(const std::string &s);
	~Chip_4013();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4013_hpp */
