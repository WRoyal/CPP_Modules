#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);

	ScavTrap(ScavTrap &klas);
	ScavTrap &operator=(ScavTrap &klas);

	void guardGate();
	void attack(const std::string& target);
};

std::ostream &operator<<(std::ostream &out, ScavTrap const &klas);

#endif