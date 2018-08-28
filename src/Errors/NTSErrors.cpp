/*
** EPITECH PROJECT, 2018
** ERRORS_HPP_
** File description:
** ERRORS_HPP_
*/

# include "NTSErrors.hpp"

nts::NTSError::NTSError(std::string const &message,
	std::string const &component) : std::exception()
{
	this->type = component;
	this->msg = this->type + ": " + message;
}

const char *nts::NTSError::what() const throw()
{
	return this->msg.c_str();
}

std::string const &nts::NTSError::getComponent() const
{
	return this->type;
}

nts::LexicalErrors::LexicalErrors(std::string const &msg)
	: NTSError(msg, "LexicalErrors")
{
}

nts::ComponentTypeUnknown::ComponentTypeUnknown(std::string const &msg)
	: NTSError(msg, "ComponentTypeUnknown")
{
}
nts::ComponentNameUnknown::ComponentNameUnknown(std::string const &msg)
	: NTSError(msg, "ComponentNameUnknown")
{
}
nts::PinUnknown::PinUnknown(std::string const &msg)
	: NTSError(msg, "PinUnknown")
{
}
nts::SameComponentName::SameComponentName(std::string const &msg)
	: NTSError(msg, "SameComponentName")
{
}
nts::OutputNotLinked::OutputNotLinked(std::string const &msg)
	: NTSError(msg, "OutputNotLinked")
{
}
nts::InputNotProvided::InputNotProvided(std::string const &msg)
	: NTSError(msg, "InputNotProvided")
{
}
nts::InputUnknown::InputUnknown(std::string const &msg)
	: NTSError(msg, "InputUnknown")
{
}
nts::NoChipsetSection::NoChipsetSection(std::string const &msg)
	: NTSError(msg, "NoChipsetSection")
{
}
nts::NoLinkSection::NoLinkSection(std::string const &msg)
	: NTSError(msg, "NoLinkSection")
{
}

nts::InfiniteLoop::InfiniteLoop(std::string const &msg)
	: NTSError(msg, "InfiniteLoop")
{
}

nts::UnknownFile::UnknownFile(std::string const &msg)
	: NTSError(msg, "UnknownFile")
{
}

nts::UnknownFileType::UnknownFileType(std::string const &msg)
	: NTSError(msg, "UnknownFileType")
{
}