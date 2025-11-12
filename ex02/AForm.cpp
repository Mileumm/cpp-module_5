#include "AForm.hpp"
#include "Bureaucrat.hpp" 

AForm::AForm() : _name("default"),  _signed(false), _signGrade(1), _execGrade(1)
{

}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1)
	{
		std::cout << "Error grade for sign" << _name << " : ";
		throw GradeTooHighException();
	}
	else if (_signGrade > 150)
	{
		std::cout << "Error grade for sign" << _name << " : ";
		throw GradeTooLowException();
	}
	if (_signGrade < 1)
	{
		std::cout << "Error grade for execute" << _name << " : ";
		throw GradeTooHighException();
	}
	else if (_signGrade > 150)
	{
		std::cout << "Error grade for execute" << _name << " : ";
		throw GradeTooLowException();
	}
}

AForm::~AForm()
{

}

AForm::AForm(const AForm& obj) : _name(obj.getName()), _signed(obj.getSigned()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{

}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		_signed = obj.getSigned();
	}
	return (*this);
}

void AForm::beSigned(const Bureaucrat& obj)
{
	if (_signed == false && obj.getGrade() <= _signGrade)
	{
		std::cout << obj.getName() << " signed " << _name << std::endl;
		_signed = true;
	}
	else if (_signed == true && obj.getGrade() <= _signGrade)
		std::cout << obj.getName() << " couldn’t sign " << _name << " because it's already signed." << std::endl;
	else
	{
		throw GradeTooLowException();
	}
}

const bool& AForm::getSigned(void) const
{
	return (_signed);
}

const int& AForm::getSignGrade(void) const
{
	return (_signGrade);
}

const int& AForm::getExecGrade(void) const
{
	return (_execGrade);
}

const std::string& AForm::getName(void) const
{
	return (_name);
}

std::string AForm::getTarget(void) const
{
	return (_target);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << " need " << obj.getSignGrade() << " for be signed and " << obj.getExecGrade() << " for be executed. ";
	if (obj.getSigned())
		os << obj.getName() << " has been signed.";
	else
		os << obj.getName() << " has not been signed.";
	return (os);
}