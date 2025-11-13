#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp" 

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
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
		std::cout << executor.getName() << " executed this form." << std::endl;
		srand(static_cast<unsigned int>(time(NULL)));
		if (rand() % 2 == 1)
		{
			std::cout << "Congratulations, "<< _target << " has been robotomized successfully !" << std::endl;
			std::cout << "BZZZZZZZZZRRRRRRRRTTTT!" << std::endl;
		}
		else
		{
			std::cout << "Sorry, "<< _target << " the robotomy failed ..." << std::endl;
		}
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
