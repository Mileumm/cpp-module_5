#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp" 

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
	return (*this);
}

const char * ShrubberyCreationForm::NotSigned::what() const throw()
{
	return ("didn't signed");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
