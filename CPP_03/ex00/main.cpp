#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Luke");
	ClapTrap b("Yoda");

	// a.attack("Yoda");
	// a.beRepaired(12);
	// a.attack("Yoda");
	a.attack("Yoda");
	a.TakeDamage(2);
	a.print();
	a.beRepaired(12);
	a.print();
	// b.TakeDamage(2);
	// b.print();

	// b.attack("Luke");
	return 0;
}