#ifndef ROBOFORM_H
# define ROBOFORM_H

#include <ctime> 
#include <cstdlib>
#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
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