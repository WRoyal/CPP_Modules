#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain *dogBrain;
public:
	Dog();
	virtual ~Dog();
	
	Dog &operator=(const Dog &klas);
	Dog(Dog const &klas);

	virtual void makeSound() const;
};

#endif