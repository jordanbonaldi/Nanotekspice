/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** InstanceManager
*/

#include "InstanceManager.hpp"

std::vector<nts::IInstance *> nts::InstanceManager::instances;

nts::IInstance *
nts::InstanceManager::getInstanceFromString(std::string const &name)
{
	for (IInstance *i : instances)
		if (!i->getName().compare(name))
			return i;
	return nullptr;
}

nts::IInstance *
nts::InstanceManager::addInstanceByString(nts::IInstance *instance)
{
	instances.push_back(instance);
	return instance;
}
