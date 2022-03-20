#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main(void)
{
	Animal	animal;
	Cat		cat;
	Dog		dog;
	WrongAnimal wro;
	WrongCat kat;
	std::cout << "\n";

	animal.makeSound();
	cat.makeSound();
	dog.makeSound();
	wro.makeSound();
	kat.makeSound();

	std::cout << "\033[35mType\033[0m\t\t" << animal.getType() << std::endl;
	std::cout << "\033[35mType\033[0m\t\t" << cat.getType() << std::endl;
	std::cout << "\033[35mType\033[0m\t\t" << dog.getType() << std::endl;
	std::cout << "\033[35mType\033[0m\t\t" << wro.getType() << std::endl;
	std::cout << "\033[35mType\033[0m\t\t" << kat.getType() << std::endl;

	std::cout << "\n";
}