/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** LoopCommand
*/

#ifndef LoopCommand_hpp
	#define LoopCommand_hpp

#include <iostream>
#include <signal.h>
#include "Interpretor.hpp"
# include "ACommand.hpp"

namespace nts
{
	class LoopCommand : public nts::ACommand
	{
	public:
		LoopCommand(std::string const &);
		~LoopCommand();

		virtual void action(std::string const &args) final;
	private:
		static bool loop;
	};
}

#endif /* LoopCommand_hpp */
