/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** ExitCommand
*/

#ifndef ExitCommand_hpp
	#define ExitCommand_hpp

# include <iostream>
# include "Interpretor.hpp"
# include "ACommand.hpp"

namespace nts
{
	class ExitCommand : public nts::ACommand
	{
	public:
		ExitCommand(std::string const &);
		~ExitCommand();

		virtual void action(std::string const &args) final;
	private:
	};
}

#endif /* ExitCommand_hpp */
