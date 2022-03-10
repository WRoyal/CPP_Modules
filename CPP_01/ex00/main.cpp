#include "Zombie.hpp"

Zombie *newZombie(std::string name);
Zombie *randomChump(std::string name);

int main(void)
{
	Zombie *Luke = newZombie("Luke");
	Zombie *Yoda = newZombie("Yoda");
	Luke->announce();
	Yoda->announce();
	randomChump("Luke");
	randomChump("Yoda");
	delete Luke;
	delete Yoda;
}
