#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <exception>
#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	private :
		const std::string	_name;
		int				_grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat& operator=(const Bureaucrat& obj);
		const std::string& getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		const int& getGrade(void) const;
		void signForm(Form& form);

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif