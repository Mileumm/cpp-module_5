#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat Alice = Bureaucrat("Alice", 1);
		std::cout << Alice << std::endl;
		Alice.incrementGrade();
		Alice.decrementGrade();
		std::cout << Alice << std::endl;
		std::cout << Alice << std::endl;
		std::cout << "//////////////" << std::endl;
		Form Form_1 = Form("Form_1", 13, 134);
		Alice.signForm(Form_1);
		std::cout << Form_1 << std::endl;
		Form Form_2 = Form("Form_2", 0, 134);
		Form Form_3 = Form("Form_3", 5, 134);
		Alice.signForm(Form_3);
		std::cout << Form_3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't create bureaucrat because because "<< '\n';
        std::cout << e.what() << std::endl;
	}
	return (0);
}