/*
** EPITECH PROJECT, 2018
** Terminal
** File description:
** Implementation of Terminal
*/

#include "Terminal.hpp"

Terminal::Terminal(const std::string &s) : AComponent(s, 24, "terminal")
{
}

Terminal::~Terminal()
{

}

nts::Tristate Terminal::compute(size_t pin)
{
	return AComponent::compute(pin);
}
