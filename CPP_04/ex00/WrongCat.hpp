#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	virtual ~WrongCat();
	
	WrongCat &operator=(const WrongCat &klas);
	WrongCat(WrongCat const &klas);

	virtual void makeSound() const;
};

#endif