#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "No name";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attack_damage = 0;
	std::cout << "\033[36;1m" << "ClapTrap \tdefault constructor" << " \033[0m" << std::endl;
}

ClapTrap::~ClapTrap(){std::cout << "\033[36;1m" << "ClapTrap \tdefault destructor" << " \033[0m" << std::endl;}

ClapTrap::ClapTrap(ClapTrap const *klas)
{
	*this = klas;
	std::cout << "\033[36;1m" << "ClapTrap \tcopy constructor" << " \033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad) : name(name), hitPoints(hp), energyPoints(ep), attack_damage(ad)
{
	std::cout << "\033[36;1m" << "ClapTrap \tconstructor" << " \033[0m" << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &klas)
{
	std::cout << "\033[36;1m" << "ClapTrap \tassignation constructor" << " \033[0m" << std::endl;
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
	std::cout << "\033[36;1m" << "ClapTrap \tdefault constructor" << " \033[0m" << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "\033[36;1m" << "ClapTrap\t" << "\033[0m" << this->name << " attacks " << target;
		std::cout << ", causing " << "\033[33;1m" << this->attack_damage << " \033[0m" << "points of damage!" << std::endl;
	}
	else
		std::cout << "\033[33;1m" << "NO HITPOINTS" << " \033[0m" << std::endl;
}

void ClapTrap::TakeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "\033[32;1m" << this->name << " \t\t\033[0mtake " << "\033[33;1m" << amount << " \033[0m" << "damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		this->hitPoints += amount;
		std::cout << "\033[32;1m" << this->name << " \t\t\033[0m" << "repair" << " \033[33;1m" << amount << " \033[0m" << std::endl;	
	}
	else
		std::cout << "\033[33;1m" << "NO HITPOINTS" << " \033[0m" << std::endl;
}

std::string ClapTrap::getName() const
{
	return this->name;
}

int	ClapTrap::getHit() const
{
	return this->hitPoints;
}

int	 ClapTrap::getEnergy() const
{
	return this->energyPoints;
}

int	ClapTrap::getDamage() const
{
	return this->attack_damage;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &klas)
{
	out << "\033[32;1m" << klas.getName() << "\033[0m\t\t" << klas.getHit() << " " << klas.getEnergy() << " " << klas.getDamage() << "\n";
	return out;
}