/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Create class
*/

#ifndef NANOTEKSPICE_PARSER_HPP
	#define NANOTEKSPICE_PARSER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
#include <memory>
#include "IInstance.hpp"
#include "InstanceManager.hpp"
#include "NTSErrors.hpp"
#include "AComponent.hpp"

namespace nts
{
	class Parser : public IInstance
	{
	public:
		Parser(int, const char **);
		void readFile();
		void parseContent();
		void dump();
		void setInputs();
		Parser &build();
		const std::vector<std::unique_ptr<IComponent>> &getComponents() const;
		std::string getName() const override;
		static Parser *getInstance();
	private:
		std::string filename;
		std::list<std::string> filecontent;
		std::vector<std::string> arguments;
		std::vector<std::unique_ptr<IComponent>> components;
		void createLinks(const std::string &);
		void createChipsets(const std::string &);
		IComponent * getComponent(const std::string &name) const;
		std::pair<std::string, size_t> getPair(const std::string &);
		std::pair<std::string, int> getArgValues(const std::string &);
		std::string name;
	};
};

#endif //NANOTEKSPICE_PARSER_HPP
