/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Chip_4801
*/

#ifndef Chip_4801_hpp
	#define Chip_4801_hpp

#include <iostream>
#include "AComponent.hpp"

class Chip_4801 : public nts::AComponent
{
public:
	Chip_4801(const std::string &s);
	~Chip_4801();

	virtual nts::Tristate compute(std::size_t pin = 1) final;
private:
};

#endif /* Chip_4801_hpp */
