/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(int argc, const char **argv) : name("circuit")
{
	nts::InstanceManager::addInstanceByString(this);
	nts::Parser *p = new nts::Parser(argc, argv);
	auto &components = p->build().getComponents();
	nts::Interpretor *inter;

	std::for_each(components.begin(), components.end(), [this] (auto &i) {
		if (!i->getType().compare("output"))
			this->outputs.push_back(dynamic_cast<Output *>(i.get()));
		else if (!i->getType().compare("input"))
			this->inputs.push_back(dynamic_cast<Input *>(i.get()));
		else if (!i->getType().compare("clock"))
			this->clocks.push_back(dynamic_cast<Clock *>(i.get()));
		else
			this->components.push_back(i.get());
	});
	inter = new nts::Interpretor();
	nts::InstanceManager::addInstanceByString(inter);
	inter->build();
}

std::vector<Input *> nts::Circuit::getInputs() const
{
	return this->inputs;
}

std::vector<Clock *> nts::Circuit::getClocks() const
{
	return this->clocks;
}

std::vector<nts::IComponent *> nts::Circuit::getComponents() const
{
	return this->components;
}

std::vector<Output *> nts::Circuit::getOutputs() const
{
	return this->outputs;
}

std::string nts::Circuit::getName() const
{
	return this->name;
}

nts::Circuit *nts::Circuit::getInstance()
{
	return dynamic_cast<nts::Circuit *>(InstanceManager::getInstanceFromString("circuit"));
}
