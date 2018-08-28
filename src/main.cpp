/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

# include <iostream>
# include <exception>
#include <Parser.hpp>
#include <Circuit.hpp>
# include "Interpretor.hpp"
#include "InstanceManager.hpp"

int main(int argc, char const **argv)
{
	if (argc < 2)
		throw std::invalid_argument(std::string(argv[0]) +
			" circuit_file.nts input_name=input_value");
	nts::Circuit circuit(argc, argv);
	return 0;
}
