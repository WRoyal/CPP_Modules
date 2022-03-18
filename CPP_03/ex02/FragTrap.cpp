#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noname", 100, 50, 20)
{
	std::cout << "\033[31;1m" << "ScavTrap \tdefault constructor" << " \033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "\033[31;1m" << "ScavTrap \tconstructor" << " \033[0m" << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[31;1m" << "ScavTrap \tdefault destructor" << " \033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &klas)
{
	*this = klas;
	std::cout << "\033[31;1m" << "ScavTrap \tcopy constructor" << " \033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &klas)
{
	this->name = klas.getName();
	this->energyPoints = klas.getEnergy();
	this->hitPoints = klas.getHit();
	this->attack_damage = klas.getDamage();
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "\033[31;1m" << "ScavTrap\t" << "\033[0m" << this->name << " attacks " << target;
		std::cout << ", causing " << "\033[33;1m" << this->attack_damage << " \033[0m" << "points of damage!" << std::endl;
	}
	else
		std::cout << "\033[33;1m" << "NO HITPOINTS" << " \033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "<\x1b[32m" << "ScavTrap" << "\x1b[0m>\t" << name << " have enterred in Gate keeper mode." << "\n";
}

std::ostream &operator<<(std::ostream &out, ScavTrap const &klas)
{
	out << "\033[32;1m" << klas.getName() << "\033[0m\t\t" << klas.getHit() << " " << klas.getEnergy() << " " << klas.getDamage() << "\n";
	return out;
}