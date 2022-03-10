#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private	:
	std::string type;
public	:
	Weapon();
	~Weapon();
	Weapon(std::string type);
	const	std::string &GetType();
	void	setType(std::string type);
};

#endif