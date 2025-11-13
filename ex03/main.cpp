#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
		try 
		{
			Bureaucrat Alice = Bureaucrat("Alice", 1);
			Bureaucrat David = Bureaucrat("David", 1);
			Intern someRandomIntern;

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
			std::cout << "//////////////" << std::endl;
			AForm* Form_4 = someRandomIntern.makeForm("presidential pardon" , "Martin");
			AForm * Form_5 = someRandomIntern.makeForm("robotomy request" , "Martine");
			AForm * Form_6 = someRandomIntern.makeForm("shrubbery creation" , "Marc");

			Form_4->beSigned(Alice);
			Form_4->execute(David);
			Form_5->beSigned(Alice);
			Form_5->execute(David);
			Form_6->beSigned(Alice);
			Form_6->execute(David);

			std::cout << *Form_4 << std::endl;
			std::cout << *Form_5 << std::endl;
			std::cout << *Form_6 << std::endl;

		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	return (0);
}