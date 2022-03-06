#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private	:
		Contact contacts[8];
	public	:
	PhoneBook(void );
	~PhoneBook(void );
	int		AddContact(int id);
	int		SearchContact(void);
	void	PrintToDisplay(int id);
};

#endif