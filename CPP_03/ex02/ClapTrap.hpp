#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attack_damage;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const *klas);
	ClapTrap(std::string name, int hp, int ep, int ad);

	ClapTrap	&operator=(ClapTrap const &klas);

	void		attack(const std::string& target);
	void		TakeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		print();

	std::string	getName() const;
	int			getHit() const;
	int			getEnergy() const;
	int			getDamage() const;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &klas);

#endif