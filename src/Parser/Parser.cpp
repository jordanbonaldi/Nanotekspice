/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Create class
*/

#include <ComponentFactory.hpp>

nts::Parser::Parser(int argc, const char **args) : name("parser")
{
	filename = args[1];
	for (int i = 2; i < argc; ++i)
		arguments.emplace_back(args[i]);
}

void nts::Parser::readFile()
{
	std::string buff;
	std::ifstream stream;

	if (this->filename.find(".nts") == std::string::npos)
		throw nts::UnknownFileType(this->filename + " is not a .nts "
								"extension");
	stream.open(this->filename);
	if (!stream)
		throw nts::UnknownFile(this->filename + " unknown");
	while (getline(stream, buff)) {
		std::replace(buff.begin(), buff.end(), '\t', ' ');
		if (buff.find("#") != std::string::npos)
			buff = buff.substr(0, buff.find("#"));
		if (!*buff.c_str())
			continue;
		this->filecontent.push_back(buff);
	}
}

const std::vector<std::unique_ptr<nts::IComponent>> &
nts::Parser::getComponents() const
{
	return this->components;
}

nts::Parser &nts::Parser::build()
{
	this->readFile();
	this->parseContent();
	return *this;
}

std::string nts::Parser::getName() const
{
	return this->name;
}

nts::Parser *nts::Parser::getInstance()
{
	return static_cast<Parser *>
		(InstanceManager::getInstanceFromString("parser"));
}

static inline std::string &rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
			std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	for(int i = s.size() - 1; i >= 0; i--)
		if(s[i] == ' ' && s[i] == s[i - 1])
			s.erase(s.begin() + i);
	return s;
}

void nts::Parser::parseContent()
{
	bool first = false;
	bool state = false;

	if (*filecontent.begin() != ".chipsets:")
		throw NoChipsetSection("no chipset section");
	for (std::string &line : filecontent)
	{
		if  (line.empty())
			continue;
		line = rtrim(line);
		if (line.at(0) != '.' && !state)
			createChipsets(line);
		else if (line.at(0) != '.' && state)
			createLinks(line);
		if (line == ".chipsets:" && first)
			throw LexicalErrors("incorrect line " + line);
		else if (line == ".links:")
			state = true;
		else if (line == ".links:" && state)
			throw LexicalErrors("incorrect line " + line);
		else if (line.at(0) == '.' && first)
			throw LexicalErrors("command " + line);
		first = true;
	}
	if (!state)
		throw NoLinkSection("no link section");
	setInputs();
}

void nts::Parser::createChipsets(const std::string &line)
{
	std::string name;
	std::string type;
	std::string tmp;
	std::istringstream f(line);

	std::getline(f, type, ' ');
	std::getline(f, name, ' ');
	std::getline(f, tmp, '\0');
	if (!tmp.empty() || type.empty() || name.empty())
		throw LexicalErrors("incorrect line " + line);
	for (auto const &c : components)
		if (c->getName() == name)
			throw SameComponentName(name + "already exist");
	name = name.substr(0, name.find("(", 0));
	components.push_back(nts::ComponentFactory::createComponent(type, name));
}

void nts::Parser::createLinks(const std::string &line)
{
	std::string first;
	std::string second;
	std::string tmp;
	std::istringstream f(line);

	std::getline(f, first, ' ');
	std::getline(f, second, ' ');
	std::getline(f, tmp, '\0');
	if (!tmp.empty() || first.empty() || second.empty())
		throw LexicalErrors("incorrect line " + line);
	auto pair1 = getPair(first);
	auto pair2 = getPair(second);
	getComponent(pair1.first)->setLink(pair1.second,
				*getComponent(pair2.first), pair2.second);
}

nts::IComponent *nts::Parser::getComponent(const std::string &name) const
{
	for (auto const &c : components)
		if ((c.get())->getName() == name)
			return c.get();
	throw ComponentNameUnknown(name);
}

std::pair<std::string, size_t> nts::Parser::getPair(const std::string &string)
{
	std::pair<std::string, size_t> pair;
	std::string first;
	std::string second;
	std::string tmp;
	std::istringstream f(string);

	std::getline(f, first, ':');
	std::getline(f, second, ':');
	std::getline(f, tmp, '\0');
	if (!tmp.empty() || first.empty() || second.empty())
		throw LexicalErrors("incorrect line " + string);
	pair.first = first;
	pair.second = static_cast<size_t>(atoi(second.c_str()));
	return pair;
}

void nts::Parser::dump()
{
	for (auto const &c : components)
	{
		c->dump();
	}
}

std::pair<std::string, int> nts::Parser::getArgValues(const std::string &string)
{
	std::pair<std::string, int> pair;
	std::string first;
	std::string second;
	std::string tmp;
	std::istringstream f(string);

	std::getline(f, first, '=');
	std::getline(f, second, '=');
	std::getline(f, tmp, '\0');
	if (!tmp.empty() || first.empty() || second.empty())
		throw LexicalErrors("incorrect arg " + string);
	pair.first = first;
	pair.second = atoi(second.c_str());
	return pair;
}

void nts::Parser::setInputs()
{
	for (const std::string &s : arguments)
	{
		auto pair = getArgValues(s);
		this->getComponent(pair.first)->setValue(pair.second);
	}
	for (auto const &c : components)
		if (c->getType() == "input" && c->getValue() == nts::UNDEFINED)
			throw InputNotProvided(c->getName());
}
