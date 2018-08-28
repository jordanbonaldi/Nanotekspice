/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** IComponent
*/

#ifndef IComponent_HPP
	#define IComponent_HPP

#include <iostream>
#include <vector>
#include <map>

namespace nts
{
	class AComponent;
	enum Tristate
	{
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent
	{
	public:
		virtual ~IComponent() = default;
	public:
		virtual const std::string &getName() const = 0;
		virtual const std::string &getType() const = 0;
		virtual nts::Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent & other, std::
		size_t otherPin) = 0;
		virtual void dump() const = 0;
		virtual size_t getNumberOfPins() const = 0;
		virtual std::map<size_t, nts::IComponent *> getPins() const = 0;
		virtual Tristate getValue() const = 0;
		virtual void setValue(int value) = 0;
		virtual void update() = 0;
	};
}

#endif
