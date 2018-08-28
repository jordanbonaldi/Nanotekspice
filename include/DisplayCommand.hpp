/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** DisplayCommand
*/

#ifndef DisplayCommand_hpp
	#define DisplayCommand_hpp

# include <iostream>
# include <algorithm>
# include "IComponent.hpp"
# include "Parser.hpp"
# include "Circuit.hpp"
# include "ACommand.hpp"

namespace nts
{
	class DisplayCommand : public nts::ACommand
	{
	public:
		DisplayCommand(std::string const &);
		~DisplayCommand();

		virtual void action(std::string const &args) final;
	private:
	};
}

#endif /* DisplayCommand_hpp */
