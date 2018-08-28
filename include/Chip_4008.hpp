/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4008
*/

#ifndef Chip_4008_hpp
	#define Chip_4008_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4008 : public nts::AComponent
{
public:
	Chip_4008(const std::string &s);
	~Chip_4008();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4008_hpp */
