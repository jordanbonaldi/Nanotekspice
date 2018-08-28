/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "Parser.hpp"

void launchTest(int ac, const char **av)
{
	nts::Parser parser = nts::Parser(ac, av);
	parser.build();
}

Test(parser_error, simple_test)
{
	int ac = 2;
	const char* av[3] = { const_cast<char *>("./nanotekspice"),
				const_cast<char *>("1.nts"), NULL };
	launchTest(ac, av);
}
