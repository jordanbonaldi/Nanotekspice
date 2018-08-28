/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4001
*/

#ifndef Chip_4001_hpp
	#define Chip_4001_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4001 : public nts::AComponent
{
public:
	Chip_4001(const std::string &s);
	~Chip_4001();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4001_hpp */
