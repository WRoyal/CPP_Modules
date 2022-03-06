// #include <iostream>
#include "phonebook.hpp"
// #include "contact.hpp"

int main(int argc, char **argv)
{
	std::string		str;
	PhoneBook book;
	int id = 0;

	std::cout << "Commands: ADD, SEARCH, EXIT\n";
	while (1)
	{
		std::cout << "Enter the command: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "Empty command\n";
			break;
		}
		if (str == "ADD")
		{
			id = book.AddContact(id);
			if (id == 8)
				id = 0;
		}
		if (str == "EXIT")
		{
			std::cout << "EXIT\n";
			break;
		}
	}
	return 0;
}