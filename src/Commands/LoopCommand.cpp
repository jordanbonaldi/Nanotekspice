/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** LoopCommand
*/

#include "LoopCommand.hpp"

bool nts::LoopCommand::loop = false;

nts::LoopCommand::LoopCommand(std::string const &name) : ACommand(name)
{

}

nts::LoopCommand::~LoopCommand()
{

}

void nts::LoopCommand::action(std::string const &args)
{
	(void)args;
	this->loop = true;
	signal(SIGINT, [](int i)
		{
			(void)i;
			loop = false;
			std::cout << std::endl;
		});
	while (loop)
		Interpretor::getInstance()->
			getCommand("simulate")->action("");
	signal(SIGINT, [] (int i) { (void)i; });
}
