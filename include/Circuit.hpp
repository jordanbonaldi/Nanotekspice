/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Circuit
*/

#ifndef Circuit_hpp
	#define Circuit_hpp

#include <iostream>
#include <vector>
#include "IInstance.hpp"
#include "InstanceManager.hpp"
#include "Clock.hpp"
#include "Parser.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Interpretor.hpp"

namespace nts
{
	class Circuit : public IInstance
	{
	public:
		Circuit(int argc, const char **argv);

		std::vector<Input *> getInputs() const;
		std::vector<Output *> getOutputs() const;
		std::vector<nts::IComponent *> getComponents() const;
		virtual std::string getName() const;
		static Circuit *getInstance();
		std::vector<Clock *> getClocks() const;
	private:
		std::string name;
		std::vector<Input *> inputs;
		std::vector<Output *> outputs;
		std::vector<Clock *> clocks;
		std::vector<nts::IComponent *> components;
	};
}

#endif /* Circuit_hpp */
