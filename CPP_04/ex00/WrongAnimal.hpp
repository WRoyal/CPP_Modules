#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
	WrongAnimal(std::string const &type);

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	
	WrongAnimal &operator=(const WrongAnimal &klas);
	WrongAnimal(WrongAnimal const &klas);

	std::string const &getType() const;
	virtual void makeSound() const;
};

#endif