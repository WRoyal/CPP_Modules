#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){};

HumanB::~HumanB(){};

void	HumanB::attack()
{
	std::cout << "\033[33m" << this->name << " \033[0m" << "attacks with their " << this->weapon->GetType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}