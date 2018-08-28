/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** ExitCommand
*/

# include "ExitCommand.hpp"

nts::ExitCommand::ExitCommand(std::string const &name) : ACommand(name)
{
}

nts::ExitCommand::~ExitCommand()
{

}

void nts::ExitCommand::action(std::string const &args)
{
	(void)args;
	nts::Interpretor::getInstance()->setEnd(true);
}
