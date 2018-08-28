/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** InstanceManager
*/

#ifndef InstanceManager_hpp
	#define InstanceManager_hpp

#include <iostream>
#include <vector>
#include "IInstance.hpp"

namespace nts
{
	class InstanceManager
	{
	public:
		static nts::IInstance *getInstanceFromString(std::string const &);
		static nts::IInstance *addInstanceByString(nts::IInstance *);
		static std::vector<nts::IInstance *> instances;
	private:
	};
}

#endif /* InstanceManager_hpp */
