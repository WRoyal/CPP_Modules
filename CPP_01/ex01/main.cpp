#include "Zombie.hpp"
Zombie *zombieHorde(int N, std::string name);

#define ZOMBIES_NUM 5

int main(void)
{
	Zombie *zombies = zombieHorde(ZOMBIES_NUM, "Luke");;
	for (int a = 0; a < ZOMBIES_NUM; a++)
		zombies[a].announce();
	delete [] zombies;
	zombies = zombieHorde(ZOMBIES_NUM, "Yoda");
	for (int a = 0; a < ZOMBIES_NUM; a++)
		zombies[a].announce();
	delete [] zombies;
	return 0;
}
