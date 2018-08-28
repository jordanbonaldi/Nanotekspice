/*
** EPITECH PROJECT, 2018
** AComponent
** File description:
** Declaration of AComponent
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP
	#define NANOTEKSPICE_ACOMPONENT_HPP

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "NTSErrors.hpp"
#include "IComponent.hpp"

namespace nts
{
	class AComponent : public IComponent
	{
	public:
		AComponent(const std::string &, size_t, const std::string &);
		const std::string &getName() const override;
		const std::string &getType() const override;
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin) override;
		void dump() const override;
		size_t getNumberOfPins() const final;
		std::map<size_t, nts::IComponent *> getPins() const final;
		nts::Tristate compute(std::size_t pin = 1) override;
		nts::Tristate getValue() const override;
		void setValue(int) override;
		void reverse();
		void update() override;
	protected:
		std::string name;
		size_t numberOfPins;
		std::map<size_t, std::pair<size_t, size_t>> outputslinks;
		std::map<size_t, size_t> links;
		std::map<size_t, nts::IComponent *> pins;
		std::string type;
		nts::Tristate value;
		int pin;
		bool init;
	};
}

std::ostream &operator<<(std::ostream &out, nts::Tristate);

#endif //NANOTEKSPICE_ACOMPONENT_HPP
