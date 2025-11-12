#ifndef SHRUBBERYFORM_H
# define SHRUBBERYFORM_H

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

		void execute(Bureaucrat const & executor) const;

		class NotSigned : public std::exception
		{
			public :
				    const char* what() const throw();
		};
};
#endif