/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** SimulateCommand
*/

#ifndef SimulateCommand_hpp
	#define SimulateCommand_hpp

# include <iostream>
# include "Clock.hpp"
# include "Circuit.hpp"
# include "ACommand.hpp"

namespace nts
{
	class SimulateCommand : public nts::ACommand
	{
	public:
		SimulateCommand(std::string const &);
		~SimulateCommand();

		virtual void action(std::string const &args) final;
	private:
	};
}

#endif /* SimulateCommand_hpp */
