#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
		try 
		{
			Bureaucrat Alice = Bureaucrat("Alice", 1);
			Bureaucrat David = Bureaucrat("David", 1);
		
			Alice.decrementGrade();
			std::cout << Alice << std::endl;
			Alice.incrementGrade();
			std::cout << Alice << std::endl;
			std::cout << "//////////////" << std::endl;
			PresidentialPardonForm Form_1 = PresidentialPardonForm("Martin");
			Alice.signForm(Form_1);
			std::cout << Form_1 << std::endl;
			David.executeForm(Form_1);
			std::cout << "//////////////" << std::endl;
			RobotomyRequestForm Form_2 = RobotomyRequestForm("Martin");
			Alice.signForm(Form_2);
			std::cout << Form_2 << std::endl;
			David.executeForm(Form_2);
			std::cout << "//////////////" << std::endl;
			ShrubberyCreationForm Form_3 = ShrubberyCreationForm("Martin");
			std::cout << Form_3 << std::endl;
			Alice.signForm(Form_3);
			David.executeForm(Form_3);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	return (0);
}