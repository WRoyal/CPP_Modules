#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string name);

	FragTrap(FragTrap &klas);
	FragTrap &operator=(FragTrap &klas);

	void	highFivesGuys();
	void	attack(const std::string& target);
};

std::ostream &operator<<(std::ostream &out, FragTrap const &klas);

#endif