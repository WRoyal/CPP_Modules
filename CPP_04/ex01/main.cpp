#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"



int main(void)
{
	Animal *cat = new Cat();
	std::cout << "\n";
	Animal *dog = new Dog();
	std::cout << "\n";
	Animal *catCopy = new Cat(*(Cat*)cat);

	
	std::cout << "\n";
	cat->makeSound();
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	std::cout << dog->getType() << std::endl;
	catCopy->makeSound();
	std::cout << catCopy->getType() << std::endl;
	std::cout << "\n";


	delete cat;
	delete dog;
	delete catCopy;
// 	Animal	animal;
// 	Cat		cat;
// 	Dog		dog;
// 	
// 	std::cout << "\n";
// 
// 	animal.makeSound();
// 	cat.makeSound();
// 	dog.makeSound();
// 
// 	std::cout << "\033[35mType\033[0m\t\t" << animal.getType() << std::endl;
// 	std::cout << "\033[35mType\033[0m\t\t" << cat.getType() << std::endl;
// 	std::cout << "\033[35mType\033[0m\t\t" << dog.getType() << std::endl;
// 	std::cout << "\n";
	// delete animal;
}