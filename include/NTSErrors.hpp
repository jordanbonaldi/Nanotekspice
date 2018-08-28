/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Errors
*/

#ifndef NTSErrors_HH
	#define NTSErrors_HH

#include <iostream>
#include <exception>

namespace nts
{
	class NTSError : public std::exception
	{
	public:
		NTSError(std::string const &msg,
			std::string const &type = "Unknown");

		std::string const &getComponent() const;
		const char *what() const throw() final;
	private:
		std::string msg;
		std::string type;
	};

	class LexicalErrors : public NTSError
	{
	public:
		LexicalErrors(std::string const &);
	};

	class ComponentTypeUnknown : public NTSError
	{
	public:
		ComponentTypeUnknown(std::string const &);
	};

	class ComponentNameUnknown : public NTSError
	{
	public:
		ComponentNameUnknown(std::string const &);
	};

	class PinUnknown : public NTSError
	{
	public:
		PinUnknown(std::string const &);
	};

	class SameComponentName : public NTSError
	{
	public:
		SameComponentName(std::string const &);
	};

	class OutputNotLinked : public NTSError
	{
	public:
		OutputNotLinked(std::string const &);
	};

	class InputNotProvided : public NTSError
	{
	public:
		InputNotProvided(std::string const &);
	};

	class InputUnknown : public NTSError
	{
	public:
		InputUnknown(std::string const &);
	};

	class NoChipsetSection : public NTSError
	{
	public:
		NoChipsetSection(std::string const &);
	};

	class NoLinkSection : public NTSError
	{
	public:
		NoLinkSection(std::string const &);
	};

	class InfiniteLoop : public NTSError
	{
	public:
		InfiniteLoop(std::string const &);
	};

	class UnknownFile : public NTSError
	{
	public:
		UnknownFile(std::string const &);
	};

	class UnknownFileType : public NTSError
	{
	public:
		UnknownFileType(std::string const &);
	};
}

#endif
