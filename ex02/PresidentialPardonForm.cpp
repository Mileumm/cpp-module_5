#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp" 

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
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
		std::cout << executor.getName() << " executed PresidentialPardonForm!" <<std::endl;
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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
