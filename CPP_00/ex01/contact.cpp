#include "Contact.hpp"

Contact::Contact(void ) {}

Contact::~Contact(void ) {}

void	Contact::CreateContact(void)
{
	int flag = 0;

	std::cout << "FirstName -> ";
	std::getline(std::cin, this->FirstName);
	if (std::cin.eof())
		std::cout << "Empty FirstName" << std::endl;

	std::cout << "LastName -> ";
	std::getline(std::cin, this->LastName);
	if (std::cin.eof())
		std::cout << "Empty LastName" << std::endl;
	
	std::cout << "NickName -> ";
	std::getline(std::cin, this->NickName);
	if (std::cin.eof())
		std::cout << "Empty NickName" << std::endl;

	std::cout << "PhoneNumber -> ";
	std::getline(std::cin, this->PhoneNumber);
	if (std::cin.eof())
		std::cout << "Empty PhoneNumber" << std::endl;

	std::cout << "DarkestSecret -> ";
	std::getline(std::cin, this->DarkestSecret);
	if (std::cin.eof())
		std::cout << "Empty DarkestSecret" << std::endl;
}

int	Contact::EmptyContact(void)
{
	int	flag = 0;

	if (this->FirstName.empty())
		flag = 1;
	if (this->LastName.empty())
		flag = 1;
	if (this->NickName.empty())
		flag = 1;
	if (this->PhoneNumber.empty())
		flag = 1;
	if (this->DarkestSecret.empty())
		flag = 1;
	if (flag == 0)
		return 0;
	else
		return 1;
}

void Contact::PrintContact(int id)
{
	std::cout << "│" << std::setw(10) << id + 1;
	if (this->FirstName.size() > 10)
		std::cout << "│" << std::setw(10 - 1) << this->FirstName.substr(0,9) << ".";
	else
		std::cout << "│" << std::setw(10) << this->FirstName;

	if (this->LastName.size() > 10)
		std::cout << "│" << std::setw(10 - 1) << this->LastName.substr(0,9) << ".";
	else
		std::cout << "│" << std::setw(10) << this->LastName;

	if (this->NickName.size() > 10)
		std::cout << "│" << std::setw(10 - 1) << this->NickName.substr(0,9) << ".";
	else
		std::cout << "│" << std::setw(10) << this->NickName;
	std::cout << "│" << std::endl;
}

void	Contact::FullContact(void )
{
	std::cout << "FirstName: " << FirstName << std::endl;
	std::cout << "LastName: "  << LastName << std::endl;
	std::cout << "NickName: "  << NickName << std::endl;
	std::cout << "PhoneNumber: " << PhoneNumber << std::endl;
	std::cout << "DarkestSecret: " << DarkestSecret << std::endl;
}