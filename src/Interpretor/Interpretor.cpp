/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Interpretor
*/

#include "Interpretor.hpp"

nts::Interpretor::Interpretor()
{
	this->name = "interpretor";
	this->cmds.push_back(new ExitCommand("exit"));
	this->cmds.push_back(new DisplayCommand("display"));
	this->cmds.push_back(new DumpCommand("dump"));
	this->cmds.push_back(new SimulateCommand("simulate"));
	this->cmds.push_back(new LoopCommand("loop"));
	this->cmds.push_back(new InputCommand("input"));
}

std::string nts::Interpretor::getName() const
{
	return this->name;
}

void nts::Interpretor::setEnd(bool a)
{
	this->end = a;
}

nts::ACommand *nts::Interpretor::getCommand(std::string const &cmdname) const
{
	for (nts::ACommand *p : this->cmds)
		if (!p->getName().compare(cmdname))
			return p;
	return nullptr;
}

nts::Interpretor *nts::Interpretor::getInstance()
{
	return static_cast<nts::Interpretor *>(
		nts::InstanceManager::getInstanceFromString("interpretor"));
}

std::list<nts::ACommand *> nts::Interpretor::getCmds() const
{
	return this->cmds;
}

void nts::Interpretor::build()
{
	nts::ACommand *tmp = nullptr;
	std::string buffer;

	signal(SIGINT, [](int i){ (void) i; });
	this->getCommand("simulate")->action("");
	this->getCommand("display")->action("");
	std::cout << "> ";
	while (!this->end && std::getline(std::cin, buffer)) {
		remove_if(buffer.begin(), buffer.end(), isspace);

		tmp = buffer.find('=') != std::string::npos ? this->getCommand("input") :
			this->getCommand(buffer);
		if (tmp)
			tmp->action(buffer);
		if (!this->end)
			std::cout << "> ";
	}
	//std::cout << "exit" << std::endl;;
}
