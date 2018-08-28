/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** ACommand
*/

#include "ACommand.hpp"

nts::ACommand::ACommand(std::string const &name)
{
	this->name = name;
}

nts::ACommand::~ACommand()
{
}

const std::string nts::ACommand::getName() const
{
	return this->name;
}
