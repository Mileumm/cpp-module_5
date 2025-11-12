#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form() : _name("default"),  _signed(false), _signGrade(1), _execGrade(1)
{

}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
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

Form::~Form()
{

}

Form::Form(const Form& obj) : _name(obj.getName()), _signed(obj.getSigned()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{

}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		_signed = obj.getSigned();
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat& obj)
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
		std::cout << obj.getName() << " couldn’t sign " << _name << " because ";
		throw GradeTooLowException();
	}
}

const bool& Form::getSigned(void) const
{
	return (_signed);
}

const int& Form::getSignGrade(void) const
{
	return (_signGrade);
}

const int& Form::getExecGrade(void) const
{
	return (_execGrade);
}

const std::string& Form::getName(void) const
{
	return (_name);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << " need " << obj.getSignGrade() << " for be signed and " << obj.getExecGrade() << " for be executed. ";
	if (obj.getSigned())
		os << obj.getName() << " has been signed.";
	else
		os << obj.getName() << " has not been signed.";
	return (os);
}