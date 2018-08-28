/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** InputCommand
*/

#include "InputCommand.hpp"

nts::InputCommand::InputCommand(std::string const &name) : ACommand(name)
{

}

nts::InputCommand::~InputCommand()
{

}

void nts::InputCommand::action(std::string const &args)
{
	std::string name;
	int value;
	nts::Circuit *circuit = nts::Circuit::getInstance();

	name = args.substr(0, args.find('='));
	value = atoi(args.substr(args.find('=') + 1, args.size() - 1).c_str());
	for (auto *i : circuit->getInputs()) {
		if (!i->getName().compare(name)) {
			i->setValue(value);
			return;
		}
	}
	std::cout << name << " doesn't exists" << std::endl;
}
