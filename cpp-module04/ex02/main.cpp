#include "Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

int main()
{
	Animal *arr[10];
	// creat obj's
	std::cout << "====creat obj's====" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (i < 5)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}

	// check sound
	std::cout << "====check sound====" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 0)
			std::cout << "=====Cat=====" << std::endl;
		if (i == 5)
			std::cout << "======Dog=====" << std::endl;
		std::cout << i << "-";
		arr[i]->makeSound();
	}
	// check type
	std::cout << "====check type====" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 0)
			std::cout << "=====Cat=====" << std::endl;
		if (i == 5)
			std::cout << "======Dog=====" << std::endl;
		std::cout << i << "-" << arr[i]->getType() << std::endl;
	}

	std::cout << "====check copy constructor====" << std::endl;
	Cat x;
	Cat b(x);
	std::cout << "====check destroyed====" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		delete (arr[i]);
	}
	std::cout << "====check destroyed for x and b====" << std::endl;
	return 0;
}