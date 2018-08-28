/*
** EPITECH PROJECT, 2018
** ComponentFactory
** File description:
** Implementation of ComponentFactory
*/

#include "ComponentFactory.hpp"

std::unique_ptr<nts::IComponent>
nts::ComponentFactory::createComponent(const std::string &type,
				const std::string &value)
{
	static std::map<std::string, std::function<IComponent *()>> classNames =
	{
		{"output", [&]() -> IComponent * {return new Output(value);}},
		{"input", [&]() -> IComponent * {return new Input(value);}},
		{"clock", [&]() -> IComponent * {return new Clock(value);}},
		{"true", [&]() -> IComponent * {return new True(value);}},
		{"false", [&]() -> IComponent * {return new False(value);}},
		{"4008", [&]() -> IComponent * {return new Chip_4008(value);}},
		{"4001", [&]() -> IComponent * {return new Chip_4001(value);}},
		{"4011", [&]() -> IComponent * {return new Chip_4011(value);}},
		{"4013", [&]() -> IComponent * {return new Chip_4013(value);}},
		{"4017", [&]() -> IComponent * {return new Chip_4017(value);}},
		{"4030", [&]() -> IComponent * {return new Chip_4030(value);}},
		{"4040", [&]() -> IComponent * {return new Chip_4040(value);}},
		{"4069", [&]() -> IComponent * {return new Chip_4069(value);}},
		{"4071", [&]() -> IComponent * {return new Chip_4071(value);}},
		{"4081", [&]() -> IComponent * {return new Chip_4081(value);}},
		{"4094", [&]() -> IComponent * {return new Chip_4094(value);}},
		{"4514", [&]() -> IComponent * {return new Chip_4514(value);}},
		{"terminal", [&]() -> IComponent * {return new Terminal(value);}},
		{"2716", [&]() -> IComponent * {return new Chip_2716(value);}}
	};
	try
	{
		return std::unique_ptr<nts::IComponent>(classNames[type]());
	}
	catch (...)
	{
		throw ComponentTypeUnknown(type);
	}
}
