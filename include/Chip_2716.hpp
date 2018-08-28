/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_2716
*/

#ifndef Chip_2716_hpp
	#define Chip_2716_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_2716 : public nts::AComponent
{
public:
	Chip_2716(const std::string &s);
	~Chip_2716();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_2716_hpp */
