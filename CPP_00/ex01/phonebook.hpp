#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class	PhoneBook
{
	private	:
		Contact contacts[8];
	public	:
	PhoneBook(void );
	~PhoneBook(void );
	int AddContact(int id);
	// int SearchContact(void);
};

#endif