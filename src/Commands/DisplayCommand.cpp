/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** DisplayCommand
*/

#include "DisplayCommand.hpp"

nts::DisplayCommand::DisplayCommand(std::string const &name) : ACommand(name)
{

}

nts::DisplayCommand::~DisplayCommand()
{

}

void nts::DisplayCommand::action(std::string const &args)
{
	nts::Circuit *circuit = nts::Circuit::getInstance();
	std::vector<Output *> outputs = circuit->getOutputs();

	(void)args;
	for (auto *i : circuit->getComponents())
		if (i->getType() == "terminal")
			return;
	std::sort(outputs.begin(), outputs.end(),
		[] (Output *&a, Output *&b) -> bool {
			return a->getName().compare(b->getName()) <= 0;
		});
	std::for_each(outputs.begin(), outputs.end(), [] (Output *&output) -> void {
			std::cout << output->getName() << "=";
			if ((int)output->getValue() < 0)
				std::cout << "U" << std::endl;
			else
				std::cout << (int)output->getValue() << std::endl;
		});
}
