#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attack_damage;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const *klas);

	ClapTrap &operator=(ClapTrap const &klas);

	void attack(const std::string& target);
	void TakeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void	print();
};

#endif