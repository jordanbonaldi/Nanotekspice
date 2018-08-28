/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4069
*/

#ifndef Chip_4069_hpp
	#define Chip_4069_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4069 : public nts::AComponent
{
public:
	Chip_4069(const std::string &s);
	~Chip_4069();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4069_hpp */
