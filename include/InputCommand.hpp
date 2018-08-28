/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** InputCommand
*/

#ifndef InputCommand_hpp
	#define InputCommand_hpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Circuit.hpp"
# include "ACommand.hpp"

namespace nts
{
	class InputCommand : public nts::ACommand
	{
	public:
		InputCommand(std::string const &);
		~InputCommand();

		virtual void action(std::string const &args) final;
	private:
	};
}

#endif /* InputCommand_hpp */
