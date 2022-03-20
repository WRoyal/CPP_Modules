#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	type;
	Animal(std::string const &type);

public:
	Animal();
	virtual ~Animal();
	
	Animal &operator=(const Animal &klas);
	Animal(Animal const &klas);

	std::string const &getType() const;
	virtual void makeSound() const;
};

#endif