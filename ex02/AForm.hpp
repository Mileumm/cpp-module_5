#ifndef AFORM_H
# define AFORM_H

#include <exception>
#include <string>
#include <iostream>
class Bureaucrat;

class AForm
{
	private :
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		std::string _target;
	public :
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		void beSigned(const Bureaucrat& obj);
		const bool& getSigned(void) const;
		const int& getSignGrade(void) const;
		const int& getExecGrade(void) const;
		const std::string& getName(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		std::string getTarget() const;

		class GradeTooHighException : public std::exception
		{
			public :
				    const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				    const char* what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const AForm& obj);
#endif