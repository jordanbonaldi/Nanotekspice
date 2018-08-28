/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** IInstance
*/

#ifndef IInstance_HPP
	#define IInstance_HPP

#include <iostream>

namespace nts
{
	class IInstance
	{
	public:
		virtual ~IInstance() = default;

		virtual std::string getName() const = 0;
	};
}

#endif
