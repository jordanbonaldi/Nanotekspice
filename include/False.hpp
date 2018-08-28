/*
** EPITECH PROJECT, 2018
** False
** File description:
** Declaration of False
*/

#ifndef NANOTEKSPICE_FALSE_HPP
#define NANOTEKSPICE_FALSE_HPP

#include "AComponent.hpp"

class False : public nts::AComponent
{
public:
	False(const std::string &);
	nts::Tristate compute(std::size_t) final;
	void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) final;
	void dump() const final;
private:
};


#endif //NANOTEKSPICE_FALSE_HPP
