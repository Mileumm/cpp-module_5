#ifndef SHRUBBERYFORM_H
# define SHRUBBERYFORM_H

#include <exception>
#include <string>
#include <fstream>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private :
	std::string _target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		std::string getTarget();

		void execute(Bureaucrat const & executor) const;

		class NotSigned : public std::exception
		{
			public :
				    const char* what() const throw();
		};
};
#endif