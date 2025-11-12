#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp" 

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
	return (*this);
}

const char * PresidentialPardonForm::NotSigned::what() const throw()
{
	return ("didn't signed");
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getExecGrade() && getSigned() == true)
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << executor.getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else if (executor.getGrade() > getExecGrade())
	{
		throw GradeTooLowException();
	}
	else
	{
		throw NotSigned();
	}
}
