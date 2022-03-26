#include <iostream>
#include <string>

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate()
{
	switch (rand() % 3)
	{
	case 0:
		return (dynamic_cast<Base*>(new A));
	case 1:
		return (dynamic_cast<Base*>(new B));
	case 2:
		return (dynamic_cast<Base*>(new C));
	
	default:
		return NULL;
	}
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "type A" << std::endl;
		return ;
	}
	catch(std::bad_cast& e){}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "type B" << std::endl;
		return ;
	}
	catch(std::bad_cast& e){}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "type C" << std::endl;
		return ;
	}
	catch(std::bad_cast& e){}
	
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "type A" << std::endl;
		return ;
	}

	B *b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "type B" << std::endl;
		return ;
	}

	C *c_c = dynamic_cast<C*>(p);
	if (c_c != NULL)
	{
		std::cout << "type C" << std::endl;
		return ;
	}
}

int main()
{
	srand(time(0));

	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;

	return (0);
}