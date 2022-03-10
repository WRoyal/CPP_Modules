#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];

	for (int a = 0; a < N; a++)
		zombies[a].naming(name);
	return zombies;
}