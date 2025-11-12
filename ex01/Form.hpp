#ifndef FORM_H
# define FORM_H

#include <exception>
#include <string>
#include <iostream>
class Bureaucrat;

class Form
{
	private :
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public :
		Form();
		Form(std::string name, int signGrade, int execGrade);
		~Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		void beSigned(const Bureaucrat& obj);
		const bool& getSigned(void) const;
		const int& getSignGrade(void) const;
		const int& getExecGrade(void) const;
		const std::string& getName(void) const;
		
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
std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif