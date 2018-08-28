/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Interpretor
*/

#ifndef Interpretor_hpp
	#define Interpretor_hpp

# include <iostream>
# include <algorithm>
# include <list>
# include <signal.h>
# include <unistd.h>
# include "IInstance.hpp"
# include "DisplayCommand.hpp"
# include "LoopCommand.hpp"
# include "DumpCommand.hpp"
# include "SimulateCommand.hpp"
# include "ExitCommand.hpp"
# include "InputCommand.hpp"
# include "ACommand.hpp"
# include "InstanceManager.hpp"

namespace nts
{
	class Interpretor : public IInstance
	{
	public:
		Interpretor();

		void build();
		nts::ACommand *getCommand(std::string const &cmdname) const;
		std::list<nts::ACommand *> getCmds() const;
		void setEnd(bool a);
		static Interpretor *getInstance();
		virtual std::string getName() const;
	private:
		bool end = false;
		std::list<nts::ACommand *> cmds;
		std::string name;
	};
}

#endif /* Interpretor_hpp */
