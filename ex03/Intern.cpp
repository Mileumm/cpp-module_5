#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern& obj)
{
	(void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

AForm* makePresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}



AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string tab[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	AForm* (*form[3])(const std::string&) = 
	{
		&makePresidential,
		&makeRobotomy,
		&makeShrubbery
	};

	size_t i = 0;
	while (i < 3)
	{
		if (name == tab[i])
		{
			std::cout << "Inter creates " <<  name << "!" << std::endl;
			return (form[i](target));
		}
		i++;
	}
	std::cout << "Intern couldn't creates any form." << std::endl;
	return (NULL);
}
