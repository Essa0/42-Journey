#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout<<"Brain Copy Constructor called" << std::endl;
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout<<"Brain Copy Assignment operator called" << std::endl;
	if (this != &obj)
		*this = obj;
	return *this;
}

Brain::~Brain()
{
    std::cout<<"Brain Destructor called" << std::endl;
}