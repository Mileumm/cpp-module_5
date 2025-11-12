#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
		try 
		{
			Bureaucrat Alice = Bureaucrat("Alice", 1);
			Bureaucrat David = Bureaucrat("David", 4);
		
			Alice.decrementGrade();
			std::cout << Alice << std::endl;
			Alice.incrementGrade();
			std::cout << Alice << std::endl;
			std::cout << "//////////////" << std::endl;
			PresidentialPardonForm Form_1 = PresidentialPardonForm("Form_1");
			Bureaucrat Alie = Bureaucrat("Alce", -1);
			Alice.signForm(Form_1);
			std::cout << Form_1 << std::endl;
			David.executeForm(Form_1);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	return (0);
}