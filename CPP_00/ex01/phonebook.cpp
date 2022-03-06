#include "phonebook.hpp"

PhoneBook::PhoneBook(void ) {}

PhoneBook::~PhoneBook(void ) {}

int PhoneBook::AddContact(int id)
{
	std::cout << "Enter contact fields: first name, last name, nickname, phone number and darkest secret." << std::endl;
	std::cout << "---------------------------------------------------------------------------------------" << std::endl;
	this->contacts[id].CreateContact();
	// std::cout << this->contacts[id].EmptyContact() << std::endl;
	// this->contacts[id].PrintContact(id);
	if (this->contacts[id].EmptyContact())
	{
		std::cout << "Empty contact" << std::endl;
		return id;
	}
	else
	{
		std::cout << "Contact ID " << id + 1 << " added successfully" << std::endl;
		return id + 1;
	}
}

// int PhoneBook::SearchContact(void)
// {
// 	std::string
// }