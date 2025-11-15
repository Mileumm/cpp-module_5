#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp" 

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
	return (*this);
}

const char * ShrubberyCreationForm::NotSigned::what() const throw()
{
	return ("didn't signed");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getExecGrade() && getSigned() == true)
	{
		std::cout << executor.getName() << " executed ShrubberyCreationForm!" << std::endl;
		std::string name = _target + "_shrubbery";
		std::ofstream file(name.c_str());
		if (!file)
			std::cout << "Erreur : can't create file." << std::endl;
		file << "      /\\" << std::endl;
		file << "     /**\\" << std::endl;
		file << "    /****\\" << std::endl;
		file << "   /******\\" << std::endl;
		file << "  /********\\" << std::endl;
		file << " /**********\\" << std::endl;
		file << "/************\\" << std::endl;
		file << "      ||" << std::endl;
		file << "      ||" << std::endl;
		file.close();
	}
	else if (executor.getGrade() > getExecGrade())
	{
		throw GradeTooLowException();
	}
	else
	{
		throw NotSigned();
	}
}
