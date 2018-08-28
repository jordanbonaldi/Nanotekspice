/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** SimulateCommand
*/

#include "SimulateCommand.hpp"

nts::SimulateCommand::SimulateCommand(std::string const &name) : ACommand(name)
{
}

nts::SimulateCommand::~SimulateCommand()
{
}

void nts::SimulateCommand::action(std::string const &args)
{
	nts::Circuit *circuit = nts::Circuit::getInstance();
	std::vector<Output *> outputs = circuit->getOutputs();

	(void)args;
	for (auto *i : outputs)
		i->compute();
	for (auto *compo : circuit->getComponents())
		compo->update();
	for (auto *i : circuit->getClocks())
		i->reverse();
}
