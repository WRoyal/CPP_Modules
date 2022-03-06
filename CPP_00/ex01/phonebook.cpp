#include "PhoneBook.hpp"

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

int PhoneBook::SearchContact(void)
{
	std::string	str_in;
	int index;
	int id = -1;

	std::cout << "╒══════════╤══════════╤══════════╤══════════╕" << std::endl;
	std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
	std::cout << "╞══════════╪══════════╪══════════╪══════════╡" << std::endl;
	while (++id < 8)
		if (!this->contacts[id].EmptyContact())
			this->contacts[id].PrintContact(id);
	std::cout << "╘══════════╧══════════╧══════════╧══════════╛" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the index of the desired contact: " << std::endl;
	std::getline(std::cin, str_in);
	index = atoi(str_in.c_str());
	if (index < 1 || index > 8)
	{
		std::cout << "Invalid contact index" << std::endl;
		return 0;
	}
	this->PrintToDisplay(index - 1);
	return 0;
}

void PhoneBook::PrintToDisplay(int id)
{
	if (this->contacts[id].EmptyContact())
		std::cout << "Empty contact" << std::endl;
	else
		this->contacts[id].FullContact();
}