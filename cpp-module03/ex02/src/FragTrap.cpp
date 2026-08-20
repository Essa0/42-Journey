#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("player")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << Name << " can't attack right now" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " positive high-fives request on the standard output" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called for " << Name << std::endl;
}