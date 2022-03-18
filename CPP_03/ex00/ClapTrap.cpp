#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "No name";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attack_damage = 0;
	std::cout << "** Default constructor **" << std::endl;
}

ClapTrap::~ClapTrap(){std::cout << "** Default destructor **" << std::endl;}

ClapTrap::ClapTrap(ClapTrap const *klas)
{
	*this = klas;
	std::cout << "** Copy constructor **" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &klas)
{
	std::cout << "** Assignation constructor **" << std::endl;
	this->name = klas.name;
	this->hitPoints = klas.hitPoints;
	this->energyPoints = klas.energyPoints;
	this->attack_damage = klas.attack_damage;
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attack_damage = 0;
	std::cout << "** Constructor " << name << " **" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "\033[32;1m" << this->name << " \033[0m" << "attacks " << "\033[31;1m" << target << "\033[0m";
		std::cout << ", causing " << "\033[33;1m" << this->attack_damage << " \033[0m" << "points of damage!" << std::endl;
	}
	else
		std::cout << "\033[33;1m" << "NO HITPOINTS" << " \033[0m" << std::endl;
}

void ClapTrap::TakeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "\033[32;1m" << this->name << " \033[0mtake " << "\033[33;1m" << amount << " \033[0m" << "damage" << std::endl;
}

void	ClapTrap::print()
{
	std::cout << "Name - " << this->name << std::endl;
	std::cout << "HP - \t " << this->hitPoints << std::endl;
	std::cout << "Energy - " << this->energyPoints << std::endl;
	std::cout << "Damage - " << this->attack_damage << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		this->hitPoints += amount;
		std::cout << "\033[32;1m" << this->name << " \033[0m" << "Repair" << " \033[33;1m" << amount << " \033[0m" << std::endl;	
	}
	else
		std::cout << "\033[33;1m" << "NO HITPOINTS" << " \033[0m" << std::endl;
}
