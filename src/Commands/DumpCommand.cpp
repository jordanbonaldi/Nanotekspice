/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** DumpCommand
*/

#include "DumpCommand.hpp"

nts::DumpCommand::DumpCommand(std::string const &name) : ACommand(name)
{

}

nts::DumpCommand::~DumpCommand()
{

}

void nts::DumpCommand::action(std::string const &args)
{
	auto components = nts::Circuit::getInstance()->getComponents();

	(void)args;
	std::for_each(components.begin(), components.end(), []
			(nts::IComponent *component) {
		component->dump();
	});
}
