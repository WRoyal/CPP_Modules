#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){};

HumanA::~HumanA(){};

void	HumanA::attack()
{
	std::cout << "\033[34m" << this->name << " \033[0m" << "attacks with their " << this->weapon.GetType() << std::endl;
}