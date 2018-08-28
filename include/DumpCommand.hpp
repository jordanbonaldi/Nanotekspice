/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** DumpCommand
*/

#ifndef DumpCommand_hpp
	#define DumpCommand_hpp

#include <iostream>
#include "Circuit.hpp"
#include "IComponent.hpp"
#include "ACommand.hpp"

namespace nts
{
	class DumpCommand : public nts::ACommand
	{
	public:
		DumpCommand(std::string const &);
		~DumpCommand();

		virtual void action(std::string const &args)final;
	private:
	};
}

#endif /* DumpCommand_hpp */
