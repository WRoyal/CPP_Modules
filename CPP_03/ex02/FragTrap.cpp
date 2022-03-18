#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("noname", 100, 100, 30)
{
	std::cout << "\033[31;1m" << "FragTrap \tdefault constructor" << " \033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "\033[31;1m" << "FragTrap \tconstructor" << " \033[0m" << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[31;1m" << "FragTrap \tdefault destructor" << " \033[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap &klas)
{
	*this = klas;
	std::cout << "\033[31;1m" << "FragTrap \tcopy constructor" << " \033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &klas)
{
	this->name = klas.getName();
	this->energyPoints = klas.getEnergy();
	this->hitPoints = klas.getHit();
	this->attack_damage = klas.getDamage();
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "\033[31;1m" << "FragTrap\t" << "\033[0m" << this->name << " attacks " << target;
		std::cout << ", causing " << "\033[33;1m" << this->attack_damage << " \033[0m" << "points of damage!" << std::endl;
	}
	else
		std::cout << "\033[33;1m" << "NO HITPOINTS" << " \033[0m" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << name << " \t\tHigh Fives!" << std::endl;
}

// void FragTrap::guardGate()
// {
// 	std::cout << "<\x1b[32m" << "FragTrap" << "\x1b[0m>\t" << name << " have enterred in Gate keeper mode." << "\n";
// }

std::ostream &operator<<(std::ostream &out, FragTrap const &klas)
{
	out << "\033[32;1m" << klas.getName() << "\033[0m\t\t" << klas.getHit() << " " << klas.getEnergy() << " " << klas.getDamage() << "\n";
	return out;
}
