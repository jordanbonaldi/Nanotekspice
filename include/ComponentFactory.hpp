/*
** EPITECH PROJECT, 2018
** ComponentFactory
** File description:
** Declaration of ComponentFactory
*/

#ifndef NANOTEKSPICE_COMPONENTFACTORY_HPP
#define NANOTEKSPICE_COMPONENTFACTORY_HPP

#include <functional>
#include "IComponent.hpp"
#include "Parser.hpp"
#include "Chip_4008.hpp"
#include "Chip_4001.hpp"
#include "Chip_4011.hpp"
#include "Chip_4013.hpp"
#include "Chip_4017.hpp"
#include "Chip_4030.hpp"
#include "Chip_4040.hpp"
#include "Chip_4069.hpp"
#include "Chip_4071.hpp"
#include "Chip_4081.hpp"
#include "Chip_4094.hpp"
#include "Chip_4514.hpp"
#include "Chip_4801.hpp"
#include "Chip_2716.hpp"
#include "Output.hpp"
#include "Terminal.hpp"
#include "Input.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"

namespace nts
{
	class ComponentFactory
	{
	public:
		static std::unique_ptr<nts::IComponent>
		createComponent(const std::string &type,
				const std::string &value);
	};
}

#endif //NANOTEKSPICE_COMPONENTFACTORY_HPP
