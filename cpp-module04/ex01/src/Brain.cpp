#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	*this = obj;
	std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->idea[i] = obj.idea[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}