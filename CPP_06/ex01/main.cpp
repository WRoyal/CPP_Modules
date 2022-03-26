#include <iostream>
#include <string>

typedef struct
{
	int x;
	int y;
} Data;


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data *data = new Data();

	data->x = 14;
	std::cout << data->x << std::endl;
	std::cout << "Address data: " << data << std::endl;
	std::cout << "Ptr: " << serialize(data) << std::endl;
	std::cout << "Address data: " << deserialize(serialize(data)) << std::endl;
	
	delete data;

	return 0;
}