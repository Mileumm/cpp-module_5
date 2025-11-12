#ifndef ROBOFORM_H
# define ROBOFORM_H

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

		void execute(Bureaucrat const & executor) const;

		class NotSigned : public std::exception
		{
			public :
				    const char* what() const throw();
		};
};
#endif