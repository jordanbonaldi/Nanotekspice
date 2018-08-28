/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** ACommand
*/

#ifndef ACommand_hpp
	#define ACommand_hpp

# include <iostream>
#include "InstanceManager.hpp"

namespace nts
{
	class ACommand
	{
	public:
		ACommand(std::string const &name);
		virtual ~ACommand();

		const std::string getName() const;
		virtual void action(std::string const &args) = 0;
	private:
		std::string name;
	};
}

#endif /* ACommand_hpp */
