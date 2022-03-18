#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("Luke");
	std::cout << a << "\n";

	ScavTrap b("Yoda");
	std::cout << "\n";

	ScavTrap c(b);
	std::cout << c << "\n";
	std::cout << "\n";

	ScavTrap d("Borya");
	std::cout << "\n";

	a.attack("Yoda");
	a.TakeDamage(2);
	a.beRepaired(12);
	c.attack("Borya");
	c.TakeDamage(2);
	c.beRepaired(12);

	std::cout << "\n";
	
	// a.attack("Yoda");
	// a.beRepaired(12);
	// a.attack("Yoda");
	// a.print();
	// a.print();
	// b.TakeDamage(2);
	// b.print();
	// b.attack("Luke");
	return 0;
}