#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp" 

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
	return (*this);
}

const char * RobotomyRequestForm::NotSigned::what() const throw()
{
	return ("didn't signed");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getExecGrade() && getSigned() == true)
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
	}
	else if (executor.getGrade() > getExecGrade())
	{
		std::cout << executor.getName() << " can't executed " << getName() << " because ";
		throw GradeTooLowException();
	}
	else
	{
		std::cout << executor.getName() << " can't executed " << getName() << " because ";
		throw NotSigned();
	}
}
