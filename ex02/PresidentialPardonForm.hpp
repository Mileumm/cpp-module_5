#ifndef PRESFORM_H
# define PRESFORM_H

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

		void execute(Bureaucrat const & executor) const;

		class NotSigned : public std::exception
		{
			public :
				    const char* what() const throw();
		};
};
#endif